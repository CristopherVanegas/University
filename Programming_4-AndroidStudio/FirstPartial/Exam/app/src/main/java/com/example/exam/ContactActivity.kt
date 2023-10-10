package com.example.exam

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button
import android.widget.EditText

class ContactActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_contact)

        val editTextName: EditText = findViewById(R.id.editTextName)
        val editTextCorreo: EditText = findViewById(R.id.editTextCorreo)
        val btnAceptarContact: Button = findViewById(R.id.btnAceptarContact)

        btnAceptarContact.setOnClickListener {
            var i: Intent = Intent(this, FinalActivity::class.java)
            i.putExtra("name", editTextName.text.toString())
            i.putExtra("email", editTextCorreo.text.toString())

            startActivity(i)
        }
    }
}