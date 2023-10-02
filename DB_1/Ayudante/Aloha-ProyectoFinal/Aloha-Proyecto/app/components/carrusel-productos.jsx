import { useOutletContext } from "@remix-run/react";

import CardProducto from "./card-producto";
// import CardPromocion from "./card-promocion";

export default function CarruselProductos({ titulo, enlace }) {
  const { productos, carrito } = useOutletContext();
  
  const productosFiltrados = productos.filter(
    (productoState) => productoState.categoria === enlace
  );

  // Crear una copia del array de productos filtrados con la cantidad en el carrito
  const productosFiltradosConCantidad = productosFiltrados.map((producto) => {
    // Buscar la cantidad del producto en el carrito
    const productoEnCarrito = carrito && carrito.find(
      (productoEnCarrito) => productoEnCarrito._id === producto._id
    );
    // Si el producto está en el carrito, usar su cantidad, de lo contrario usar 0
    const cantidad = productoEnCarrito ? productoEnCarrito.cantidad : 0;
    // Crear una copia del producto con la cantidad en el carrito
    return { ...producto, cantidad };
  });

  const promociones = [];

  productosFiltradosConCantidad.map((producto) => (
    titulo == "Promociones" ? promociones.push(producto) : ""
  ))

  return (
    <section id={`${enlace}`}>

      {titulo !== "Promociones" && (
        <h2 className="text-black text-xl lg:text-2xl font-bold p-3">
          {titulo}
        </h2>
      )}
      
      {/* {titulo == "Promociones" && (
        <CardPromocion promocion={promociones} className="m-auto" />
      )} */}

      <div className="snap-x overflow-x-scroll">
        <div
          className="items-center pr-5 inline-flex"
        >
          {titulo == "Promociones" ? (
            ""
          ) :
            productosFiltradosConCantidad.map((producto) => (
              <CardProducto key={producto.id_producto} producto={producto} />
            ))
          }
        </div>
      </div>
    </section>
  );
}
