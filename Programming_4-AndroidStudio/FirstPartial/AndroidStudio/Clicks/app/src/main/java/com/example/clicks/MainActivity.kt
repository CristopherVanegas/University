package com.example.clicks

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button
import android.widget.TextView

class MainActivity : AppCompatActivity() {

    var c:Int = 0

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        val txtResult:TextView = findViewById(R.id.result)
        val sumar: Button = findViewById(R.id.sumar)
        val restar: Button = findViewById(R.id.restar)
        val multiplicarx2: Button = findViewById(R.id.multiplicarx2)


        sumar.setOnClickListener() {
            c++
            txtResult.setText(c.toString());
        }

        restar.setOnClickListener() {
            c--
            txtResult.setText(c.toString());
        }

        multiplicarx2.setOnClickListener() {
            c*=2
            txtResult.setText(c.toString());
        }
    }
}
