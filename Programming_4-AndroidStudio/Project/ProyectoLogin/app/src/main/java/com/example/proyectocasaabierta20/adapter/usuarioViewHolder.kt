package com.example.proyectocasaabierta20.adapter

import android.view.View
import android.widget.ImageView
import android.widget.RelativeLayout
import android.widget.TextView
import androidx.recyclerview.widget.RecyclerView
import com.example.proyectocasaabierta20.R
import com.example.proyectocasaabierta20.database.usuario.usuario

class usuarioViewHolder(view:View): RecyclerView.ViewHolder(view) {

    val username = view.findViewById<TextView>(R.id.mostrarUsername)
    val puntaje = view.findViewById<TextView>(R.id.mostrarPuntaje)
    val podio = view.findViewById<ImageView>(R.id.iconPuesto)
    val relativeLayout = view.findViewById<RelativeLayout>(R.id.contenedorPodio)

    fun render(usuarioModel: usuario, idJugador: Int?){
        username.text = usuarioModel.username
        puntaje.text = usuarioModel.puntos.toString()
        if(usuarioModel.podio != null) {
            podio.setImageResource(usuarioModel.podio!!)
        }

        if(idJugador == usuarioModel.id)
        {
            relativeLayout.setBackgroundColor(0xFFFFFF00.toInt())
        }
    }
}