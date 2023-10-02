import CarruselProductos from "~/components/carrusel-productos"

import styles from "../tailwind.css"

export function links() {
  return [
    {
      rel: 'stylesheet',
      href: styles
    }
  ]
}

export function meta() {
  return [{
    charset: 'utf-8',
    title: 'Aloha Café - Inicio',
    viewport: "width=device-width,initial-scale=1"
  }]
}

export default function Index() {
  return (
    <main className="xs:mt-36">
      <CarruselProductos key={'Promociones'} titulo={'Promociones'} enlace={'promociones'} className="m-auto" />
      <CarruselProductos key={'Bolones'} titulo={'Bolones'} enlace={'Bolones'} />
      <CarruselProductos key={'Bebidas Calientes'} titulo={'Bebidas Calientes'} enlace={'bebidas-calientes'} />
      <CarruselProductos key={'Bebidas Frias'} titulo={'Bebidas Frias'} enlace={'bebidas-frias'} />
      <CarruselProductos key={'Extras'} titulo={'Extras'} enlace={'extras'} />
    </main>
  )
}
