package com.example.proyectocasaabierta20.database.usuario

class usuario {
    var id: Int = 0
        get(){
            return field
        }
        set(_id){
            field = _id
        }

    var password: String? = null
        get(){
            return field
        }
        set(_password){
            field = _password
        }

    var first_name: String? = null
        get(){
            return field
        }
        set(_nombre){
            field = _nombre
        }

    var last_name: String? = null
        get(){
            return field
        }
        set(_apellido){
            field = _apellido
        }

    var username: String? = null
        get(){
            return field
        }
        set(_usuario){
            field = _usuario
        }

    var puntos: Int = 0
        get(){
            return field
        }
        set(_puntos){
            field = _puntos
        }

    var genero: String? = null
        get() {
            return field
        }
        set(_genero){
            field = _genero
        }

    var podio: Int? = null
        get() {
            return field
        }
        set(_podio){
            field = _podio
        }
    constructor(id: Int, first_name: String?, last_name: String?, username: String?, puntos: Int, genero: String?, podio: Int?) {
        this.id = id
        this.first_name = first_name
        this.last_name = last_name
        this.username = username
        this.puntos = puntos
        this.genero = genero
        this.podio = podio
    }

    constructor()
}