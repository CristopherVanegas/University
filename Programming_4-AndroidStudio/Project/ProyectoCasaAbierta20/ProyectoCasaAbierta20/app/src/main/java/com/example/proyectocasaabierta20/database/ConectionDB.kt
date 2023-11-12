package com.example.proyectocasaabierta20.database

import android.content.Context
import android.database.sqlite.SQLiteDatabase
import android.database.sqlite.SQLiteOpenHelper

open class ConectionDB (context: Context): SQLiteOpenHelper(context, DATABASE_NAME, null, DATABASE_VERSION) {
    companion object {
        private const val DATABASE_NAME = "Base_Proyecto.db"
        private const val DATABASE_VERSION = 1
    }

    override fun onCreate(dbSQLite: SQLiteDatabase?) {
        // Creación tabla usuario
        var query_CrearUsuario: String =
            "CREATE TABLE Usuarios(\n" +
                    "ID_USUARIO INTEGER PRIMARY KEY AUTOINCREMENT,\n" +
                    "password TEXT NOT NULL,\n" +
                    "first_name TEXT NOT NULL,\n" +
                    "last_name TEXT NOT NULL,\n" +
                    "username TEXT NOT NULL,\n" +
                    "puntos INTEGER NOT NULL,\n" +
                    "genero TEXT NOT NULL\n" + ");"
        dbSQLite?.execSQL(query_CrearUsuario)
    }

    override fun onUpgrade(p0: SQLiteDatabase?, p1: Int, p2: Int) {
        // Función que se ejecuta cuando se actualiza la versión de la BD
        var query_BorrarUsuario: String =
            "DROP TABLE Usuarios;"
        p0?.execSQL(query_BorrarUsuario)
        onCreate(p0)
    }
}