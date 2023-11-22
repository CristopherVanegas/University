package com.example.prueba2

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import androidx.recyclerview.widget.GridLayoutManager
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView
import com.example.prueba2.adapter.EstudianteAdapter
import com.example.prueba2.model.Estudiante

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        val rvEst: RecyclerView = findViewById(R.id.rvEstudiantes)
        rvEst.layoutManager = LinearLayoutManager(this, LinearLayoutManager.HORIZONTAL, false)
        rvEst.layoutManager = GridLayoutManager(this, 1)
        val estudiantes:ArrayList<Estudiante> = ArrayList()
        estudiantes.add(Estudiante("Cristopher Vanegas", "Ingenieria",
            "1600940736", "cvanegas@est.ecotec.edu.ec", "aaa", "Ingenieria en Sistemas Inteligentes"))
        estudiantes.add(Estudiante("Valeria Galarza", "Ingeniería",
            "0000000001", "vgalarza@est.ecotec.edu.ec", "bbb", "Software"))
        estudiantes.add(Estudiante("Emilio Aguirre", "Ingenieria",
            "0000000011", "emaguirre@est.ecotec.edu.ec", "ccc", "Ingenieria en Sistemas Inteligentes"))
        estudiantes.add(Estudiante("Yadira Vera", "Marketing",
            "0000000111", "yavera@est.ecotec.edu.ec", "ddd", "Multimedia"))
        estudiantes.add(Estudiante("Heyde Jara", "Ingenieria",
            "0000001111", "hjara@est.ecotec.edu.ec", "ggg", "Ingeniería Industrial"))
        estudiantes.add(Estudiante("Johnny Bajaña", "Ciencias Sociales",
            "0000011111", "abajana@santa-priscila.com", "eee", "Derecho"))
        estudiantes.add(Estudiante("Christian Alaña", "Marketing",
            "0000111111", "cralana@est.ecotec.edu.ec", "fff", "Psicología"))
        estudiantes.add(Estudiante("Henry Jacome", "Ingenieria",
            "000111111", "hjacome@est.ecotec.edu.ec", "hhh", "Ingeniería Mecatronica"))
        estudiantes.add(Estudiante("Zineb Peñafiel", "Ciencias de la Vida",
            "001111111", "zpenafiel@est.ecotec.edu.ec", "iii", "Medicina"))


        val adapter:EstudianteAdapter = EstudianteAdapter(estudiantes) { position ->
            // Acción cuando se hace clic en un elemento del RecyclerView
            val intent = Intent(this, InfoEstudianteActivity::class.java)
            // Puedes enviar datos a la actividad de destino si es necesario
            intent.putExtra("FACULTAD_INTENT", estudiantes[position].facultad)
            intent.putExtra("NOMBRE_INTENT", estudiantes[position].nombre)
            intent.putExtra("CARRERA_INTENT", estudiantes[position].carreraCursando)
            intent.putExtra("CEDULA_INTENT", estudiantes[position].cedula)
            intent.putExtra("CORREO_INTENT", estudiantes[position].correoElectronico)
            intent.putExtra("DIRECCION_INTENT", estudiantes[position].direccion)
            startActivity(intent)
        }
        rvEst.adapter = adapter
    }
}