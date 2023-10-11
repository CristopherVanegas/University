using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio_Herencia
{
    internal class Auto : Vehiculo
    {
        // Atributos heredados
        public override double MaxFuel { get; set; }
        public override int MaxNumeroPasajeros { get; set; }
        public override double Velocidad { get; set; }

        // Atributos propios
        public string Modelo;

        // Métodos heredados
        public override void Acelerar()
        {
            Console.WriteLine("Acelerando...");
        }

        public override void Desacelerar()
        {
            Console.WriteLine("Desacelerando...");
        }

        // Métodos propios
        public void DoblarAIzquierda()
        {
            Console.WriteLine("Girando a la izquierda...");
        }

        public void DoblarADerecha()
        {
            Console.WriteLine("Girando a la derecha...");
        }
    }
}
