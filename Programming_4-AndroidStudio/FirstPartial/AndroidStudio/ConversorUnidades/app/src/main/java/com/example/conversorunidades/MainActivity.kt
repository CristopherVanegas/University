package com.example.conversorunidades

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button
import android.widget.EditText
import android.widget.TextView

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        val kg: EditText = findViewById(R.id.numberToConvert)
        val btnConvert: Button = findViewById(R.id.btnConvert)
        val txtLibras: TextView = findViewById(R.id.result)

        btnConvert.setOnClickListener() {
            var cant:Double = kg.text.toString().toDouble()
            txtLibras.setText(convertirALibras(cant).toString())
        }
    }

    fun convertirALibras(cant:Double):Double {
        return cant*2.2
    }
}