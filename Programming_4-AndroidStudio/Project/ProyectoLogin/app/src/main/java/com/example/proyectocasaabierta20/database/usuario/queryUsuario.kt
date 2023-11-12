package com.example.proyectocasaabierta20.database.usuario

import android.content.Context
import android.database.sqlite.SQLiteDatabase
import com.example.proyectocasaabierta20.database.ConectionDB
import com.example.proyectocasaabierta20.database.usuario.usuario

class queryUsuario(context: Context): ConectionDB(context) {
    fun agregarUsuario(usuarioNombre: String, usuarioApellido: String, usuario: String, usuarioContrasenia: String, usuarioGenero: String){

        // Prepara el query
        val sentencia = "INSERT INTO Usuarios (password, first_name, last_name, username, puntos, genero) VALUES (" +
                        "\"$usuarioContrasenia\", \"$usuarioNombre\", \"$usuarioApellido\", \"$usuario\", 0, \"$usuarioGenero\");"

        // Instacia la base de datos
        val basededatos: SQLiteDatabase =  writableDatabase

        try{
            basededatos.execSQL(sentencia)
        }catch(ex: Exception){
            // Controlar errores si es necesario
        }
    }

    fun buscarUsuario(usuario: String?, usuarioContrasenia: String?): usuario {
        var usuarioEncontrado = usuario()

        val sentencia = "SELECT * FROM Usuarios " +
                        "WHERE username = \"$usuario\" AND password = \"$usuarioContrasenia\""

        // Instacia la base de datos
        val basededatos: SQLiteDatabase =  readableDatabase
        val cursor = basededatos.rawQuery(sentencia, null)

        try{
            if (cursor.moveToFirst()) {
                val _id = cursor.getColumnIndexOrThrow("ID_USUARIO")
                val _password = cursor.getColumnIndexOrThrow("password")
                val _first_name = cursor.getColumnIndexOrThrow("first_name")
                val _last_name = cursor.getColumnIndexOrThrow("last_name")
                val _username = cursor.getColumnIndexOrThrow("username")
                val _puntos = cursor.getColumnIndexOrThrow("puntos")
                val _genero = cursor.getColumnIndexOrThrow("genero")

                val id = cursor.getInt(_id)
                val password = cursor.getString(_password)
                val first_name = cursor.getString(_first_name)
                val last_name = cursor.getString(_last_name)
                val username = cursor.getString(_username)
                val puntos = cursor.getInt(_puntos)
                val genero = cursor.getString(_genero)

                val usuario = usuario()

                usuario.id = id
                usuario.password = password
                usuario.first_name = first_name
                usuario.last_name = last_name
                usuario.username = username
                usuario.puntos = puntos
                usuario.genero = genero

                usuarioEncontrado = usuario
            }
        }catch(ex: Exception){
            // Controlar errores si es necesario
        }

        return usuarioEncontrado
    }

    fun buscarSoloUsuario(usuario: String): String {
        var usuarioEncontrado = ""

        val sentencia = "SELECT username FROM Usuarios " +
                "WHERE username = \"$usuario\""

        // Instacia la base de datos
        val basededatos: SQLiteDatabase =  readableDatabase
        val cursor = basededatos.rawQuery(sentencia, null)

        try{
            if (cursor.moveToFirst()) {
                val _username = cursor.getColumnIndexOrThrow("username")
                val username = cursor.getString(_username)

                usuarioEncontrado = username
            }
        }catch(ex: Exception){
            // Controlar errores si es necesario
        }

        return usuarioEncontrado
    }

    fun mandarDatosRecyclerView(): List<usuario>{
        val listaUsuarioRecyclerView = mutableListOf<usuario>()

        val sentencia = "SELECT ID_USUARIO, username, puntos FROM Usuarios ORDER BY puntos DESC LIMIT 3;"

        val basededatos: SQLiteDatabase =  readableDatabase
        val cursor = basededatos.rawQuery(sentencia, null)

        try{
            if (cursor.moveToFirst()) {
                val _id = cursor.getColumnIndexOrThrow("ID_USUARIO")
                val _username = cursor.getColumnIndexOrThrow("username")
                val _puntaje = cursor.getColumnIndexOrThrow("puntos")
                do {
                    val username = cursor.getString(_username)
                    val puntaje = cursor.getInt(_puntaje)
                    val id = cursor.getInt(_id)
                    var usuarioTemp = usuario()
                    usuarioTemp.username = username
                    usuarioTemp.puntos = puntaje
                    usuarioTemp.id = id

                    listaUsuarioRecyclerView.add(usuarioTemp)
                }while (cursor.moveToNext())
            }
        }catch(ex: Exception){
            // Controlar errores si es necesario
        }

        return listaUsuarioRecyclerView
    }

    fun actualizarPuntaje(idJugador: Int?, puntos: Int){
        val sentencia = "UPDATE Usuarios SET puntos = puntos + $puntos WHERE ID_USUARIO = $idJugador"
        val basededatos: SQLiteDatabase =  writableDatabase

        try {
            basededatos.execSQL(sentencia)
        }catch(ex: Exception){
            // Controlar errores si es necesario
        }
    }
}