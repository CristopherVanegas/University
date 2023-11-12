
package com.example.proyectocasaabierta20

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button
import android.widget.CheckBox
import android.widget.EditText
import android.widget.Toast
import com.example.proyectocasaabierta20.database.usuario.queryUsuario

class ActivityRegister : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.register_activity)

        val nombres = findViewById<EditText>(R.id.nombres)
        val apellidos = findViewById<EditText>(R.id.apellidos)
        val r_username =  findViewById<EditText>(R.id.r_username)
        val r_password = findViewById<EditText>(R.id.r_password)
        val registerButton = findViewById<Button>(R.id.RegisterButton)
        val gnMasculino = findViewById<CheckBox>(R.id.gnMasculino)
        val gnFemenino = findViewById<CheckBox>(R.id.gnFemenino)

        var genero = ""
        gnMasculino.setOnClickListener {
            if(gnMasculino.isChecked){
                genero = "hombre"
                gnFemenino.isChecked = false
            }
        }
        gnFemenino.setOnClickListener {
            if(gnFemenino.isChecked){
                genero = "mujer"
                gnMasculino.isChecked = false
            }
        }

        // Instancia de clase queryUsuario
        val objetoBD = queryUsuario(this)
        val letras = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
        val numeros = "0123456789"

        val soloLetras = Regex("[${Regex.escape(letras)}]*")
        registerButton.setOnClickListener {
            val nombreString = nombres.text.toString()
            val apellidoString = apellidos.text.toString()
            val usernameString = r_username.text.toString()
            val passwordString = r_password.text.toString()

            if (nombreString != "" && apellidoString != "" && usernameString != ""
                && passwordString != "" && (gnMasculino.isChecked || gnFemenino.isChecked)) {
                if (soloLetras.matches(nombreString.replace("\\s".toRegex(), "")) &&
                    soloLetras.matches(apellidoString.replace("\\s".toRegex(), ""))){
                    if (passwordString.length >= 8 && numeros.any { it in passwordString} && letras.any { it in passwordString}) {
                        if (objetoBD.buscarSoloUsuario(usernameString) == "") {
                            // Insertar datos de la base
                            objetoBD.agregarUsuario(
                                nombreString,
                                apellidoString,
                                usernameString,
                                passwordString,
                                genero
                            )

                            Toast.makeText(this, "Se agregó con exito", Toast.LENGTH_LONG).show()

                            nombres.setText("")
                            apellidos.setText("")
                            r_username.setText("")
                            r_password.setText("")

                            var i: Intent = Intent(this, ActivityLogin::class.java)
                            startActivity(i)
                        } else {
                            Toast.makeText(this, "Usuario existente, por favor elige otro", Toast.LENGTH_LONG).show()
                        }
                    }else{
                        Toast.makeText(this, "la contraseña debe contener números y letras", Toast.LENGTH_LONG).show()
                    }
                }else{
                    Toast.makeText(this, "Sus nombres y apellidos solo pueden contener letras", Toast.LENGTH_LONG).show()
                }
            } else {
                Toast.makeText(this, "Rellena todos los campos para continuar.", Toast.LENGTH_LONG).show()
            }
        }
    }
}