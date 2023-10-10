package com.example.codigoganador

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button
import android.widget.TextView
import kotlin.random.Random

class SecondActivity : AppCompatActivity() {

    var codigo:Int = 0

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_second)

        val txtSaludo:TextView = findViewById(R.id.txtSaludo)
        val txtCodigo:TextView = findViewById(R.id.txtCodigo)
        val btnCodigo:Button = findViewById(R.id.btnCodigo)
        val btnCorreo:Button = findViewById(R.id.btnCorreo)
        var nombre: String? = intent.extras?.getString("nombre")
        txtSaludo.setText("Bienvenido, " + nombre + "!")

        btnCodigo.setOnClickListener {
            codigo = generarCodigo();
            txtCodigo.setText(codigo.toString()) // Conversión
            // txtCodigo.setText("" + codigo) // Concatenación
        }

        btnCorreo.setOnClickListener {
            var i: Intent = Intent(Intent.ACTION_SEND)
            i.setType("text/plain")
            i.putExtra(Intent.EXTRA_SUBJECT, "Hola, " + nombre + ". Recibe tu código.")
            i.putExtra(Intent.EXTRA_EMAIL, codigo)
            startActivity(i)
        }
    }

    fun generarCodigo():Int {
        return Random(1000).nextInt(10000)
    }
}