import { useState, useEffect } from "react";
import { useOutletContext, useNavigate } from "@remix-run/react";

import { ClientOnly } from "remix-utils";
import { LocationIcon, CardIcon, CuoponDiscountIcon, DescripcionIcon } from "svg/iconos";

import validarCampos from "~/../helpers/validarCampos";
import PagarPayphone from "~/../helpers/pagarPayphone";
import generarId from "~/../helpers/generarId";

import InputPagar from "~/components/input-pagar";
import InputText from "~/components/input-text";
import ResumenPagar from "~/components/resumen-pagar";
import Disponibilidad from "~/components/disponibilidad";

import disponibilidadHorario from "helpers/disponibilidadHorario";

export default function Pagar() {

  const { carrito, auth, setPedido, disponibilidad, setDisponibilidad } = useOutletContext();

  // Manejar los campos del form
  const [entrega, setEntrega] = useState("");
  const [localComercial, setLocalComercial] = useState("");
  const [metodoPago, setMetodoPago] = useState("");
  const [cupon, setCupon] = useState("");

  const [alerta, setAlerta] = useState({});

  const [total, setTotal] = useState(0);

  const navigate = useNavigate(); //Redireccionar

  // Operaciones para calcular el total
  useEffect(() => {
    let productosDelCarritoId = [];
    let productosDelCarrito = [];
    let precioCarrito = 0;
    let num_items = 0;

    carrito.map(producto => {
      productosDelCarritoId.push(producto.id_producto);
      productosDelCarrito.push(producto.nombre);
      precioCarrito += producto.precio;
      num_items += 1;
    });
  }, [])

  //#region Calcular Subtotal
  let subtotal = 0;

  carrito ? carrito.forEach((producto) => {
    subtotal += producto.cantidad * producto.precio;
  }) : [];
  //#endregion

  //Validar Campos, Crear Orden en State
  const handleSubmit = async (e) => {
    e.preventDefault();

    setAlerta({}); //Reiniciar el form

    //Validar Campos
    let errores = validarCampos(entrega, metodoPago, localComercial);

    if (errores.length > 0) {
      setAlerta({
        msg: errores,
        error: true
      })
      return
    }

    // Ver disponibilidad de horario
    const disponibilidadVER = disponibilidadHorario(localComercial);
    setDisponibilidad(disponibilidadVER);

    // Si no hay errores y la disponibilidad es true y entrega es recoger en local
    if (entrega === "Local") {

      const external_id = generarId(); //Generar id para PayPhone

      // Crear la orden en el state
      setPedido({
        total: total.toFixed(2),
        email: auth.email,
        productos: carrito,
        localComercial,
      });

      if (metodoPago == "Tarjeta") {
        PagarPayphone(total, auth.email, external_id)
      }
      else {
        navigate(`/pedido?clientTransactionId=${external_id}`)
      }
    }
  }

  const { msg } = alerta;

  return (
    <ClientOnly fallback={'Cargando...'}>
      {() => (
        <main>
          {!disponibilidad.disponibilidad ? <Disponibilidad mensaje={disponibilidad.mensaje} disponibilidad={disponibilidad.disponibilidad} setDisponibilidad={setDisponibilidad} /> : null}

          <h1 className="text-3xl text-color-aloha text-center font-bold">Detalles</h1>

          { /* MOSTRAR LOS ERRORES DEL FORM */}
          {msg && msg.map(mensaje => (
            <div key={mensaje} className={`from-red-500 to-red-700 mt-4 bg-gradient-to-br text-center p-3 rounded-xl uppercase text-white font-bold text-sm mb-5 mx-auto w-4/5 md:w-2/5`}>
              {mensaje}
            </div>
          ))}

          {/* FORM Y RENDER A MAP, RESUMEN PAGAR */}
          <form onSubmit={e => handleSubmit(e)}>
            { /* ESCOGER EL MÉTODO DE ENTREA (LOCAL, DELIVERY) */}
            <InputPagar icono={<LocationIcon color={'#ea1010'} />} titulo={'Entrega'} valor={entrega} modificador={setEntrega} id={"entrega"} opciones={[{ value: "Local", titulo: "Recoger en Local" }]} obligatorio={true} />

            { /* ESCOGER EL LOCAL COMERCIAL */}
            <InputPagar icono={<DescripcionIcon color={'#ea1010'} />} titulo={'Selecciona el Local'} valor={localComercial} modificador={setLocalComercial} id={"local"} opciones={[{ value: "Garzota", titulo: "Garzota" }, { value: "Centro", titulo: "Centro" }, { value: "Kennedy Norte", titulo: "Kennedy Norte" }, { value: "Gran Manzana", titulo: "Gran Manzana" }, { value: "Palmora Plaza", titulo: "Palmora Plaza" }, { value: "Ceibos", titulo: "Ceibos" }]} obligatorio={true} />

            { /* ESCOGER MÉTODO DE PAGO */}
            <InputPagar icono={<CardIcon />} titulo={'Método de Pago'} valor={metodoPago} modificador={setMetodoPago} id={"metodoPago"} opciones={[{ value: "Efectivo", titulo: "Efectivo" }, { value: "Tarjeta", titulo: "Tarjeta" }]} obligatorio={true} />

            { /* PONER CUPÓN */}
            <InputText icon={<CuoponDiscountIcon />} id={"cupon"} titulo={'Cupón'} valor={cupon} modificador={setCupon} placeholder={"¿Tienes un cupón?"} /> {/* OPCIONAL - ESTÉTICO NO FUNCIONAL */}

            <ResumenPagar subtotal={subtotal} total={total} setTotal={setTotal} entrega={entrega} />
          </form>
        </main>
      )}
    </ClientOnly>
  );
}
