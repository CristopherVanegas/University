package com.example.prueba2.adapter

import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.TextView
import android.widget.Toast
import androidx.recyclerview.widget.RecyclerView
import androidx.recyclerview.widget.RecyclerView.ViewHolder
import com.example.prueba2.R
import com.example.prueba2.model.Estudiante

class EstudianteAdapter(var items:ArrayList<Estudiante>, private val onItemClick: (Int) -> Unit):
    RecyclerView.Adapter<EstudianteAdapter.EstudianteViewHolder>() {

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): EstudianteViewHolder {
        val view: View = LayoutInflater.from(parent.context).
        inflate(R.layout.card_estudiante, parent, false)
        return EstudianteViewHolder(view);
    }
    override fun onBindViewHolder(holder: EstudianteViewHolder, position: Int) {
        val est = items.get(position)
        holder.txtInicialNombre?.setText(est.nombre[0].toString())
        holder.txtNombre?.setText(est.nombre)
        holder.txtFacultad?.setText(est.facultad)
        holder.itemView.setOnClickListener {// SetOnclickListener onItemClick returns position to lambda function parameter constructor
            onItemClick.invoke(position)
        }
    }
    override fun getItemCount(): Int {
        return items.size
    }
    inner class EstudianteViewHolder(view: View):ViewHolder(view){
        var txtInicialNombre: TextView? = null;
        var txtNombre: TextView? = null;
        var txtFacultad: TextView? = null;
        init{
            txtInicialNombre = view.findViewById(R.id.txtInicialNombre)
            txtNombre = view.findViewById(R.id.txtNombre)
            txtFacultad = view.findViewById(R.id.txtFacultad)
            view.setOnClickListener(){
                Toast.makeText(view.context, items[adapterPosition].nombre, Toast.LENGTH_SHORT).show()
            }
        }
    }
}