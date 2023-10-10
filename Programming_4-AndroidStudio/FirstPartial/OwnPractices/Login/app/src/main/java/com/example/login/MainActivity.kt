package com.example.login

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        val btnLogIn: Button = findViewById(R.id.btnLogIn)
        val btnSignUp: Button = findViewById(R.id.btnSignUp)

        btnLogIn.setOnClickListener {
            var i: Intent = Intent(this, LogIn::class.java)
            startActivity(i)
        }
        btnSignUp.setOnClickListener {
            var i: Intent = Intent(this, SignUp::class.java)
            startActivity(i)
        }
    }
}