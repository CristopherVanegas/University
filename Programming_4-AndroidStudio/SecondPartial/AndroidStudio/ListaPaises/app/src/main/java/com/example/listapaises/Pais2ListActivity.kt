package com.example.listapaises

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import androidx.recyclerview.widget.GridLayoutManager
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView
import com.example.listapaises.adapter.Pais2Adapter
import com.example.listapaises.model.Pais2

class Pais2ListActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_pais2_list)

        var rvPaises: RecyclerView = findViewById(R.id.rvPaises)
        rvPaises.layoutManager = LinearLayoutManager(this, LinearLayoutManager.VERTICAL, false)
        // rvPaises.layoutManager = GridLayoutManager(this, 2)
        var paises:ArrayList<Pais2> = ArrayList()
        paises.add(Pais2(R.drawable.flag_of_ecuador, "Ecuador", "Quito"));
        paises.add(Pais2(R.drawable.flag_of_ecuador, "Colombia", "Bogotá"));
        paises.add(Pais2(R.drawable.flag_of_ecuador, "Perú", "Lima"));

        var adapter:Pais2Adapter = Pais2Adapter(paises)
        rvPaises.adapter = adapter
    }
}