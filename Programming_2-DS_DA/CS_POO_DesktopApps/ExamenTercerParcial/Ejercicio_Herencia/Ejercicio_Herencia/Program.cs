using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio_Herencia
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Random objRandom = new Random(Environment.TickCount);
            string[] ModelosDisponibles = { "Nissan", "Chevrolet", "4 por 4", "Convertible" };

            ArrayList Mis_Autos = new ArrayList();
            ArrayList Mis_Aviones = new ArrayList();

            // Llenado del ArrayList Mis_Autos
            for(int Indice = 0; Indice < 10; Indice++)
            {
                Mis_Autos.Add(new Auto
                {
                    MaxFuel = objRandom.Next(20),
                    MaxNumeroPasajeros = objRandom.Next(100),
                    Velocidad = objRandom.Next(20),
                    Modelo = ModelosDisponibles[objRandom.Next(4)]
                });
            }

            // Llenado del ArrayList Mis_Aviones
            for (int Indice = 0; Indice < 10; Indice++)
            {
                Mis_Aviones.Add(new Avion
                {
                    MaxFuel = objRandom.Next(20),
                    MaxNumeroPasajeros = objRandom.Next(100),
                    Velocidad = objRandom.Next(20),
                    Max_Altitud = objRandom.Next(1000),
                    Num_Motores = objRandom.Next(10),
                });
            }

            // Mostrado del Array List Mis_Autos
            foreach(var Auto_Indice in Mis_Autos)
            {
                Console.WriteLine("> Auto");
                Console.WriteLine("Max Fuel: " + ((Auto)Auto_Indice).MaxFuel);
                Console.WriteLine("Max Número de Pasajeros: " + ((Auto)Auto_Indice).MaxNumeroPasajeros);
                Console.WriteLine("Velocidad: " + ((Auto)Auto_Indice).Velocidad);
                Console.WriteLine("Modelo: " + ((Auto)Auto_Indice).Modelo);
                ((Auto)Auto_Indice).Acelerar();
                ((Auto)Auto_Indice).Desacelerar();
                ((Auto)Auto_Indice).DoblarADerecha();
                ((Auto)Auto_Indice).DoblarAIzquierda();
                Console.WriteLine("\n");
            }

            Console.WriteLine("---");

            // Mostrado del Array List Mis_Aviones
            foreach (var Avion_Indice in Mis_Aviones)
            {
                Console.WriteLine("> Avión");
                Console.WriteLine("Max Fuel: " + ((Avion)Avion_Indice).MaxFuel);
                Console.WriteLine("Max Número de Pasajeros: " + ((Avion)Avion_Indice).MaxNumeroPasajeros);
                Console.WriteLine("Velocidad: " + ((Avion)Avion_Indice).Velocidad);
                Console.WriteLine("Max Altitud: " + ((Avion)Avion_Indice).Max_Altitud);
                Console.WriteLine("Num de Motores: " + ((Avion)Avion_Indice).Num_Motores);
                ((Avion)Avion_Indice).Acelerar();
                ((Avion)Avion_Indice).Desacelerar();
                ((Avion)Avion_Indice).Ascender();
                ((Avion)Avion_Indice).Descender();
                Console.WriteLine("\n");
            }

            Console.ReadKey();
        }
    }
}
