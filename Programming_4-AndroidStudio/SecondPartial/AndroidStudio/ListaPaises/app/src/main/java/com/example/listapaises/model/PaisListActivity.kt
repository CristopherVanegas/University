package com.example.listapaises.model

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.ArrayAdapter
import android.widget.ListView
import com.example.listapaises.R
import com.example.listapaises.adapter.PaisAdapter

class PaisListActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_pais_list)

        // Obtener el elemento visual
        var listView = findViewById<ListView>(R.id.listView)
        // Tener la colccion
        var paises:ArrayList<Pais> = ArrayList()
        // Crear un adaptador - android.R.layout.simple_list_item_1 es el primer layout from android studio
        paises.add(Pais(R.drawable.flag_of_ecuador, "Ecuador", "Quito"))
        paises.add(Pais(R.drawable.flag_of_colombia, "Colombia", "Bogota"))
        paises.add(Pais(R.drawable.flag_of_usa, "USA", "Washington DC"))
        paises.add(Pais(R.drawable.flag_of_canada, "Canada", "Ottawa"))
        // Asignar el adaptador a la vista
        var adapter:PaisAdapter = PaisAdapter(this, paises)
    }
}