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

        val edtNombre: EditText = findViewById(R.id.editTextName)
        val btnContinue: Button = findViewById(R.id.btnContinue)

        btnContinue.setOnClickListener {
            var i: Intent = Intent(this, secondActivity::class.java)
            i.putExtra("name", edtNombre.text.toString())
            startActivity(i)
        }
    }
}