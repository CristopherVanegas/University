using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PREGUNTA_4_EXAMEN_FINAL_PRO2_YU
{
    public partial class Form1 : Form
    {
        // Clase base: Persona
        class Persona
        {
            public string nombre;
        }

        // Clase derivada: Profesor
        class Profesor : Persona
        {
            public float sueldo;
        }

        // Clase derivada: Estudiante
        class Estudiante : Persona
        {
            public int calificacion;
        }

        private Persona persona; // Una referencia para guardar la instancia de Profesor o Estudiante

        public Form1()
        {
            InitializeComponent();
        }

        private void radProfesor_CheckedChanged(object sender, EventArgs e)
        {
            // Cuando el RadioButton "Profesor" esté seleccionado
            //grbProfesor.Enabled = true;
            //grbEstudiante.Enabled = false;
        }

        private void radEstudiante_CheckedChanged(object sender, EventArgs e)
        {
            // Cuando el RadioButton "Estudiante" esté seleccionado
            // grbProfesor.Enabled = false;
            // grbEstudiante.Enabled = true;
        }

        private void btnCapturaDatos_Click(object sender, EventArgs e)
        {
            // Capturar datos según la selección de Profesor o Estudiante
            if (radProfesor.Checked)
            {
                persona = new Profesor();
                persona.nombre = txtNombre.Text;
                ((Profesor)persona).sueldo = Convert.ToSingle(txtSueldo.Text);
            }
            else if (radEstudiante.Checked)
            {
                persona = new Estudiante();
                persona.nombre = txtNombre.Text;
                ((Estudiante)persona).calificacion = Convert.ToInt32(txtCalificacion.Text);
            }

            MessageBox.Show("Datos capturados exitosamente.");
        }

        private void btnMostrarDatos_Click(object sender, EventArgs e)
        {
            if (persona != null)
            {
                string datos = $"Nombre: {persona.nombre}\n";

                if (persona is Profesor)
                {
                    datos += $"Sueldo: {((Profesor)persona).sueldo}";
                }
                else if (persona is Estudiante)
                {
                    datos += $"Calificación: {((Estudiante)persona).calificacion}";
                }

                MessageBox.Show(datos, "Datos de la persona");
            }
            else
            {
                MessageBox.Show("No se han capturado datos.");
            }
        }
    }
}
