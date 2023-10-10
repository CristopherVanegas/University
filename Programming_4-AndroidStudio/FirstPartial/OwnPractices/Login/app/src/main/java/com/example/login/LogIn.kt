package com.example.login

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button
import android.widget.EditText
import android.widget.TextView

class LogIn : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_log_in)

        val username : String = "vgalarza"
        val passwd : String = "root"

        val btnLogIn : Button = findViewById(R.id.btnLogIn)
        val editTextUsername : EditText = findViewById(R.id.editTextUsername)
        val textPasswd : EditText = findViewById(R.id.editTextPasswd)
        val textAlert : TextView = findViewById(R.id.textAlert)

        btnLogIn.setOnClickListener {
            if (editTextUsername.text.toString() == username && textPasswd.text.toString() == passwd) {
                var i: Intent = Intent(this, Home::class.java)
                i.putExtra("name", editTextUsername.text.toString())
                startActivity(i)
            }
            else
                textAlert.setText("Credential are incorrect")
        }

        val btnGoBack: Button = findViewById(R.id.btnGoBack)

        btnGoBack.setOnClickListener {
            var i: Intent = Intent(this, MainActivity::class.java)
            startActivity(i)
        }
    }
}