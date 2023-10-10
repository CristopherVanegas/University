package com.example.exam

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        val btnContinuar: Button = findViewById(R.id.btnContinuar)

        btnContinuar.setOnClickListener {
            var i: Intent = Intent(this, ContactActivity::class.java)
            startActivity(i)
        }
    }
}