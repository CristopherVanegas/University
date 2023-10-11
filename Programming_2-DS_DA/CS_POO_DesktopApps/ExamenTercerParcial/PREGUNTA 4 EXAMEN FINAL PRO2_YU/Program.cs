using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PREGUNTA_4_EXAMEN_FINAL_PRO2_YU
{
    internal static class Program
    {
        /// <summary>
        /// Punto de entrada principal para la aplicación.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form_1(Conexion_Base_de_Datos()));
        }

        // > Conexión a la base de datos MySQL de nombre bd_alvarado.
        static MySqlConnection Conexion_BaseDatos()
        {
            string conn = "server=localhost;uid=root;pwd=1234;database=EXAMEN";
            MySqlConnection Conn = new MySqlConnection();
            Conn.ConnectionString = conn;
            return Conn;
        }
    }

}
