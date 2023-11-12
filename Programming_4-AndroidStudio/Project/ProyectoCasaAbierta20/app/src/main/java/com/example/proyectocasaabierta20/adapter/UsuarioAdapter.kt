package com.example.proyectocasaabierta20.adapter

import android.view.LayoutInflater
import android.view.ViewGroup
import androidx.recyclerview.widget.RecyclerView
import com.example.proyectocasaabierta20.R
import com.example.proyectocasaabierta20.database.usuario.usuario

class UsuarioAdapter(private val podioJugadores: List<usuario>, val idJugador: Int?): RecyclerView.Adapter<usuarioViewHolder>(){
    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): usuarioViewHolder {
        val LayoutInflater = LayoutInflater.from(parent.context)
        return  usuarioViewHolder(LayoutInflater.inflate(R.layout.item_list, parent,false))
    }

    override fun onBindViewHolder(holder: usuarioViewHolder, position: Int) {
        val item = podioJugadores[position]
        when(position){
            0->item.podio = R.drawable.medalla_oro
            1->item.podio = R.drawable.medalla_plata
            2->item.podio = R.drawable.medalla_bronce
        }
        holder.render(item, idJugador)
    }

    override fun getItemCount(): Int = podioJugadores.size

}
