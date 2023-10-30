package com.example.listapaises.adapter

import android.app.Activity
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.ImageView
import android.widget.TextView
import android.widget.Toast
import androidx.recyclerview.widget.RecyclerView
import androidx.recyclerview.widget.RecyclerView.ViewHolder
import com.example.listapaises.R
import com.example.listapaises.model.Pais2

class Pais2Adapter(var items:ArrayList<Pais2>):RecyclerView.Adapter<Pais2Adapter.PaisViewHolder>() {
    inner class PaisViewHolder(view: View):ViewHolder(view) {
        var imgBandera: ImageView? = null;
        var txtNombre: TextView? = null;
        var txtCapital: TextView? = null;

        init {
            imgBandera = view.findViewById(R.id.imgBandera)
            txtNombre = view.findViewById(R.id.txtNombre)
            txtCapital = view.findViewById(R.id.txtCapital)
            view.setOnClickListener() {
                Toast.makeText(view.context, items[adapterPosition].nombre, Toast.LENGTH_SHORT).show()
            }
        }
    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): PaisViewHolder {
        val view:View = LayoutInflater.from(parent.context).inflate(R.layout.card_pais, parent, false);
        return PaisViewHolder(view);
    }

    override fun getItemCount(): Int {
        return items.size
    }

    override fun onBindViewHolder(holder: PaisViewHolder, position: Int) {
        val pais = items.get(position)
        holder.imgBandera?.setImageResource(pais.imagenBandera)
        holder.txtNombre?.setText(pais.nombre)
        holder.txtCapital?.setText(pais.capital)
    }
}