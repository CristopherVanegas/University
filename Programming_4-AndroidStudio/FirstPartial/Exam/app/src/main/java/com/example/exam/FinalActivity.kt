package com.example.exam

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button
import android.widget.TextView

class FinalActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_final)

        val nameConf: TextView = findViewById(R.id.nameConf)
        val emailConf: TextView = findViewById(R.id.emailConf)
        val btnOpenEmail: Button = findViewById(R.id.btnOpenEmail)
        var name: String? = intent.extras?.getString("name")
        var email: String? = intent.extras?.getString("email")

        nameConf.setText(name)
        emailConf.setText(email)

        btnOpenEmail.setOnClickListener {
            var i: Intent = Intent(Intent.ACTION_SEND)
            i.setType("message/rfc822")
            i.putExtra(Intent.EXTRA_EMAIL, arrayOf(email))
            startActivity(i)
        }
    }
}