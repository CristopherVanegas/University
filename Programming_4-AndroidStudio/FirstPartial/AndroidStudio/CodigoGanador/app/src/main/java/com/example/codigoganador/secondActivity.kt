package com.example.codigoganador

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button
import android.widget.TextView
import kotlin.random.Random

class secondActivity : AppCompatActivity() {
    var code:Int = 0

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_second)

        val txtGreeting: TextView = findViewById(R.id.txtGreeting)
        val txtNumber: TextView = findViewById(R.id.txtNumber)
        val btnGenerateCode: Button = findViewById(R.id.btnGenerateCode)
        val btnSendByEmail: Button = findViewById(R.id.btnSendByEmail)
        var name: String? = intent.extras?.getString("name")
        txtGreeting.setText("Hi " + name)

        btnGenerateCode.setOnClickListener {
            code = generateCode()
            txtNumber.setText(code.toString())
        }

        btnSendByEmail.setOnClickListener {
            var i:Intent = Intent(Intent.ACTION_SEND)
            i.setType("text/plain")
            i.putExtra(Intent.EXTRA_SUBJECT, "Hi " + name + "keep your code")
            // i.putExtra(Intent.EXTRA_EMAIL, code)
            i.putExtra(Intent.EXTRA_TEXT, code)
            startActivity(i)
        }
    }

    fun generateCode():Int {
        return Random(1000).nextInt(10000)
    }
}