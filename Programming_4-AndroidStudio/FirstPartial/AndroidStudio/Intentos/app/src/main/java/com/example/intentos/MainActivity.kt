package com.example.intentos

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        val btnAbrirAct2: Button = findViewById(R.id.btnAbrirAct2)
        btnAbrirAct2.setOnClickListener {
            var i: Intent = Intent(this, SecondActivity2::class.java)
            i.putExtra("Label", "Message sent!")
            startActivity(i)
        }
    }
}