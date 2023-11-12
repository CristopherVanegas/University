package com.example.proyectocasaabierta20

import android.content.Intent
import android.graphics.drawable.Drawable
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button
import android.widget.ImageView
import android.widget.TextView
import androidx.recyclerview.widget.GridLayoutManager
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView
import com.example.proyectocasaabierta20.adapter.UsuarioAdapter
import com.example.proyectocasaabierta20.database.usuario.queryUsuario
import com.example.proyectocasaabierta20.database.usuario.usuario

class ActivityProfile : AppCompatActivity() {
    private lateinit var usuarioProvider: List<usuario>
    private lateinit var recyclerView: RecyclerView
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.profile_activity)
        val tvMostrarNombre: TextView = findViewById(R.id.tvMostrarNombres)
        val tvMostrarApellido: TextView = findViewById(R.id.tvMostrarApellidos)
        val imgPerfilPersona: ImageView = findViewById(R.id.imgPerfilPersona)
        val botonJugarYa: Button = findViewById(R.id.btnJuegaYa)
        val cerrarSession: Button = findViewById(R.id.cerrarSesion)

        recyclerView = findViewById(R.id.listaJugadores)
        var id_usuario: Int? = intent.extras?.getInt("id")
        var nombre_persona: String? = intent.extras?.getString("nombres_persona")
        var apellido_persona: String? = intent.extras?.getString("apellidos_persona")
        var imagen_persona: String? = intent.extras?.getString("genero")

        var llamarFunSql = queryUsuario(this)
        usuarioProvider = llamarFunSql.mandarDatosRecyclerView()
        initRecyclerView()

        tvMostrarNombre.text = nombre_persona
        tvMostrarApellido.text = apellido_persona

        if(imagen_persona == "hombre"){
            imgPerfilPersona.setImageResource(R.drawable.perfil_hombre)
        }else{
            imgPerfilPersona.setImageResource(R.drawable.perfil_mujer)
        }

        botonJugarYa.setOnClickListener {
            var i: Intent = Intent(this, juegoPrueba::class.java)
            i.putExtra("id", id_usuario)
            startActivity(i)
        }

        cerrarSession.setOnClickListener{
            var i: Intent = Intent(this, ActivityLogin::class.java)
            val sharedPreferences = getSharedPreferences("sesion", MODE_PRIVATE)
            val editor = sharedPreferences.edit()
            editor.putString("nombreUsuario", "")
            editor.putString("usuarioPassword", "")
            editor.putBoolean("sesionActiva", false)
            editor.apply()
            startActivity(i)
        }
    }

    fun initRecyclerView(){
        var id_usuario: Int? = intent.extras?.getInt("id")
        recyclerView.layoutManager = LinearLayoutManager(this)
        recyclerView.adapter = UsuarioAdapter(usuarioProvider, id_usuario)
    }

    override fun onResume() {
        super.onResume()
        var llamarFunSql = queryUsuario(this)
        usuarioProvider = llamarFunSql.mandarDatosRecyclerView()

        initRecyclerView()
    }
}