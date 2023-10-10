package com.example.picture

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button
import android.widget.EditText
import android.widget.Toast

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        val edtUsuario:EditText = findViewById<EditText>(R.id.edtUsuario)
        val edtClave:EditText = findViewById(R.id.edtClave)
        val btnAceptar:Button = findViewById(R.id.btnAceptar)
        btnAceptar.setOnClickListener {
            var usuario:String = edtUsuario.text.toString()
            var clave:String = edtClave.text.toString()
            Toast.makeText(this@MainActivity, usuario + " " + clave, Toast.LENGTH_LONG).show()
        }
    }
}