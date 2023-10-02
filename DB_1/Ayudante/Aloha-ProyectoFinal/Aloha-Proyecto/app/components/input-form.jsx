import React from 'react'

export default function InputForm({ descripcion, tipo, id, modificador, valor, color }) {
  return (
    <>
      <div className="m-auto space-y-2 w-4/5 md:w-2/5 mb-2">
        <label htmlFor={`${id}`} className="font-bold text-base">{descripcion}</label>
        <div className="sombra-aloha rounded-xl h-12 bg-white flex justify-center">
          <input
            id={`${id}`}
            type={tipo}
            className={`h-11 px-3 w-full rounded-xl mt-0.5 bg-transparent ${color}`}
            value={valor}
            onChange={e => modificador(e.target.value)}
          />
        </div>
      </div>
    </>
  )
}
