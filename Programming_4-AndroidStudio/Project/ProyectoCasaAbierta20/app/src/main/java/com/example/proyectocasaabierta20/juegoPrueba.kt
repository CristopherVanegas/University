package com.example.proyectocasaabierta20

import android.app.AlertDialog
import android.content.ClipData
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.os.CountDownTimer
import android.view.View
import android.widget.Button
import android.widget.TextView
import com.example.proyectocasaabierta20.database.usuario.queryUsuario

class juegoPrueba : AppCompatActivity() {
    var contadorControl:Int = 0
    var controlTiempo: Int = 15

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_juego_prueba)

        val contadorTexto: TextView = findViewById(R.id.tV_Contador)
        val presionaBoton: Button = findViewById(R.id.btn_Presionar)
        val tiempoRestante: TextView = findViewById(R.id.tv_Tiempo)
        val btnvolverjugar: Button = findViewById(R.id.btn_volverjugar)

        presionaBoton.setOnClickListener{
            contadorControl += 1
            contadorTexto.setText(contadorControl.toString())
        }

        btnvolverjugar.setOnClickListener {
            contadorControl = 0
            controlTiempo = 15

            presionaBoton.visibility = View.VISIBLE
            btnvolverjugar.visibility = View.GONE
        }

        object : CountDownTimer(15000, 1000) {
            // 15000 milisegundos = 15 segundos, 1000 milisegundos = 1 segundo
            override fun onTick(millisUntilFinished: Long) {
                tiempoRestante.setText("Tiempo restante: " + controlTiempo + "s")
                controlTiempo --
            }

            override fun onFinish() {
                var id_usuario: Int? = intent.extras?.getInt("id")
                val objetoBD = queryUsuario(this@juegoPrueba)
                objetoBD.actualizarPuntaje(id_usuario, contadorControl)

                tiempoRestante.setText("Tiempo restante: 0s")

                val builder = AlertDialog.Builder(this@juegoPrueba)
                builder.setTitle("¡Se acabó el tiempo!")
                builder.setMessage("Obtuviste " + contadorControl + " puntos")

                builder.setPositiveButton("Ok") { dialog, which ->
                    dialog.dismiss()
                }

                val dialog: AlertDialog = builder.create()
                dialog.setCanceledOnTouchOutside(false)
                dialog.show()

                presionaBoton.visibility = View.GONE
                btnvolverjugar.visibility = View.VISIBLE
            }
        }.start()
    }
}