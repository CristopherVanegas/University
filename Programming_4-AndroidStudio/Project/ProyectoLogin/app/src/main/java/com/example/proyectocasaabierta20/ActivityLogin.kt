package com.example.proyectocasaabierta20

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button
import android.widget.EditText
import android.widget.Toast
import com.example.proyectocasaabierta20.database.usuario.queryUsuario
import com.example.proyectocasaabierta20.database.usuario.usuario

class ActivityLogin : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.login_activity)

        val l_username = findViewById<EditText>(R.id.l_username)
        val l_password = findViewById<EditText>(R.id.l_password)
        val login_button =  findViewById<Button>(R.id.LoginButton)
        val btnRedirectCrear = findViewById<Button>(R.id.btnRedirectCrear)

        // Instancia de clase queryUsuario
        val objetoBD = queryUsuario(this)
        var usuarioObtenido: usuario

        val sharedPreferences = getSharedPreferences("sesion", MODE_PRIVATE)
        val sesionActiva = sharedPreferences.getBoolean("sesionActiva", false)

        if (sesionActiva) {
            val nombreUsuario = sharedPreferences.getString("nombreUsuario", "")
            val usuarioPassword = sharedPreferences.getString("usuarioPassword", "")
            usuarioObtenido = objetoBD.buscarUsuario(nombreUsuario, usuarioPassword)

            var i: Intent = Intent(this, ActivityProfile::class.java)
            i.putExtra("id", usuarioObtenido.id)
            i.putExtra("nombres_persona", usuarioObtenido.first_name)
            i.putExtra("apellidos_persona", usuarioObtenido.last_name)
            i.putExtra("username", usuarioObtenido.username)
            i.putExtra("puntaje", usuarioObtenido.puntos)
            i.putExtra("genero", usuarioObtenido.genero)
            startActivity(i)
        } else {
            // El usuario no ha iniciado sesión
        }

        login_button.setOnClickListener {
            if (l_username.text.toString() != "" && l_password.text.toString() != ""){
                // Obtener datos de la base
                usuarioObtenido = objetoBD.buscarUsuario(l_username.text.toString(), l_password.text.toString())

                if(usuarioObtenido.username != null){
                    Toast.makeText(this, "Usuario existe. \nHola, " + usuarioObtenido.username, Toast.LENGTH_LONG).show()

                    val sharedPreferences = getSharedPreferences("sesion", MODE_PRIVATE)
                    val editor = sharedPreferences.edit()
                    editor.putString("nombreUsuario", usuarioObtenido.username)
                    editor.putString("usuarioPassword", usuarioObtenido.password)
                    editor.putBoolean("sesionActiva", true)
                    editor.apply()

                    var i: Intent = Intent(this, ActivityProfile::class.java)
                    i.putExtra("id", usuarioObtenido.id)
                    i.putExtra("nombres_persona", usuarioObtenido.first_name)
                    i.putExtra("apellidos_persona", usuarioObtenido.last_name)
                    i.putExtra("username", usuarioObtenido.username)
                    i.putExtra("puntaje", usuarioObtenido.puntos)
                    i.putExtra("genero", usuarioObtenido.genero)
                    startActivity(i)
                } else {
                    Toast.makeText(this, "Usuario no existe.", Toast.LENGTH_LONG).show()
                }
            } else {
                Toast.makeText(this, "Rellena todos los campos para continuar.", Toast.LENGTH_LONG).show()
            }
        }

        btnRedirectCrear.setOnClickListener {
            val enviarARegistrarse = Intent(this, ActivityRegister::class.java)
            startActivity(enviarARegistrarse)
        }
    }
}