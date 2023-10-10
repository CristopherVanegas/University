package com.example.intentos

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.TextView

class SecondActivity2 : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_second2)
        var label:String? = intent.extras?.getString("Label")
        val txtEtiqueta: TextView = findViewById(R.id.text1)
        txtEtiqueta.setText(label)
    }
}