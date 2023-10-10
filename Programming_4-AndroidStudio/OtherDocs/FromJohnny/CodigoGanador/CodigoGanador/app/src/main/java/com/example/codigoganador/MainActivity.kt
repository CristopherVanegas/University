package com.example.codigoganador

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button
import android.widget.EditText

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        val txtNombre:EditText = findViewById(R.id.txtNombre)
        val btnConfirmar:Button = findViewById(R.id.btnConfirmar)

        btnConfirmar.setOnClickListener {
            var i:Intent = Intent(this, SecondActivity::class.java)
            i.putExtra("nombre", txtNombre.text.toString())
            startActivity(i)
        }
    }
}