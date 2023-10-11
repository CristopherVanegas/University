using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio_Herencia
{
    internal abstract class Vehiculo
    {
        // Atributos
        public abstract double MaxFuel { get; set; }
        public abstract int MaxNumeroPasajeros { get; set; }
        public abstract double Velocidad { get; set; }

        // Métodos
        public abstract void Acelerar();
        public abstract void Desacelerar();

    }
}
