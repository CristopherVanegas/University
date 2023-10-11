using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio_Herencia
{
    internal class Avion : Vehiculo
    {
        // Atributos heredados
        public override double MaxFuel { get; set; }
        public override int MaxNumeroPasajeros { get; set; }
        public override double Velocidad { get; set; }

        // Atributos propios
        public double Max_Altitud;
        public int Num_Motores;

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
        public void Descender()
        {
            Console.WriteLine("Ascendiendo...");
        }

        public void Ascender()
        {
            Console.WriteLine("Descendiendo...");
        }
    }
}
