package com.example.listapaises.adapter

import android.app.Activity
import android.content.Context
import android.content.Intent
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.BaseAdapter
import android.widget.ImageView
import android.widget.TextView
import android.widget.Toast
import androidx.recyclerview.widget.RecyclerView
import com.example.listapaises.R
import com.example.listapaises.model.Pais
import com.example.listapaises.model.PaisListActivity

class PaisAdapter( var actividad:Activity, var items:ArrayList<Pais>): BaseAdapter() {
    override fun getCount(): Int {
        return items.size
    }

    override fun getItem(p0: Int): Any {
        return items.get(p0)
    }

    override fun getItemId(p0: Int): Long {
        return p0.toLong()
    }

    override fun getView(p0: Int, p1: View?, p2: ViewGroup?): View {
        var view: View
        var viewHolder:ViewHolder
        if ( p1 == null ) {
            var layoutInflater:LayoutInflater = actividad.getSystemService(Context.LAYOUT_INFLATER_SERVICE) as LayoutInflater
            view = layoutInflater.inflate(R.layout.item_pais_personalizado, null)
            viewHolder = ViewHolder(view)
            view.tag = viewHolder
        } else {
            view = p1
            viewHolder = p1.tag as ViewHolder
        }

        var pais:Pais = items.get(p0)
        viewHolder.imgBandera?.setImageResource(pais.imagenBandera)
        viewHolder.txtNombre?.setText(pais.nombre)
        viewHolder.txtCapital?.setText(pais.capital)

        view.setOnClickListener {
            Toast.makeText(actividad, pais.nombre, Toast.LENGTH_SHORT).show()
        }

        return view
    }

    inner class ViewHolder( view:View ) {
        var imgBandera: ImageView? = null;
        var txtNombre: TextView? = null;
        var txtCapital: TextView? = null;

        init {
            imgBandera = view.findViewById(R.id.imgBandera)
            txtNombre = view.findViewById(R.id.txtNombre)
            txtCapital = view.findViewById(R.id.txtCapital)
        }
    }

}