package com.example.rv_con_intent

import MyAdapter
import android.content.Intent
import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView

class MainActivity : AppCompatActivity() {

    private lateinit var recyclerView: RecyclerView
    private lateinit var adapter: MyAdapter // Asegúrate de reemplazar MyAdapter con el nombre de tu adaptador
    private lateinit var myDataSet: ArrayList<String> // Reemplaza con tu conjunto de datos

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        // Inicializar tu conjunto de datos (puedes obtenerlos de una fuente de datos)
        myDataSet = ArrayList()
        myDataSet.add("Elemento 1")
        myDataSet.add("Elemento 2")
        // Asegúrate de agregar más elementos a tu conjunto de datos

        // Configurar el RecyclerView
        recyclerView = findViewById(R.id.recyclerView)
        recyclerView.layoutManager = LinearLayoutManager(this)
        adapter = MyAdapter(myDataSet) { position ->
            // Acción cuando se hace clic en un elemento del RecyclerView
            val intent = Intent(this, DetalleActivity::class.java)
            // Puedes enviar datos a la actividad de destino si es necesario
            intent.putExtra("ELEMENTO_SELECCIONADO", myDataSet[position])
            startActivity(intent)
        }
        recyclerView.adapter = adapter
    }
}

