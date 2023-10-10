package com.example.login

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button

class SignUp : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_sign_up)

        val btnGoBack: Button = findViewById(R.id.btnGoBack)

        btnGoBack.setOnClickListener {
            var i: Intent = Intent(this, MainActivity::class.java)
            startActivity(i)
        }
    }
}