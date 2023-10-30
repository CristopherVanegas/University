package com.example.listapaises

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.ArrayAdapter
import android.widget.ListView
import android.widget.Toast
import com.example.listapaises.model.PaisListActivity

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        // Obtener el elemento visual
        val lvPaises:ListView = findViewById(R.id.lvPaises)

        // Tener la colccion
        var paises: Array<String> = arrayOf("Ecuador" ,"Colombria", "Brazil", "Perú")

        // Crear un adaptador - android.R.layout.simple_list_item_1 es el primer layout from android studio
        var adapter:ArrayAdapter<String> = ArrayAdapter(this, R.layout.item_pais, paises)

        // Asignar el adaptador a la vista
        lvPaises.adapter = adapter

        lvPaises.setOnItemClickListener { adapterView, view, i, l ->
            // Toast.makeText(this, "Seleccionó " + paises[i], Toast.LENGTH_SHORT).show()
            startActivity(Intent(this, PaisListActivity::class.java))
        }
    }
}