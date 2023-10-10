package com.example.login

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.TextView

class Home : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_home)

        val textViewUsername : TextView = findViewById(R.id.textViewUsername)
        var name: String? = intent.extras?.getString("name")    // verifica si le llego un string con la clave "name" de algun otro activity

        textViewUsername.setText(name)  // set textUsername.text con el string de otro activity con clave "name"
    }
}