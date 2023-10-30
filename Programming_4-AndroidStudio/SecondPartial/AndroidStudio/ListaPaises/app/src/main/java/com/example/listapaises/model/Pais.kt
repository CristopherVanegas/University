package com.example.listapaises.model

class Pais {
    var imagenBandera: Int = 0
    var nombre: String = ""
    var capital:String = ""

    constructor(imagenBandera: Int, nombre: String, capital: String) {
        this.imagenBandera = imagenBandera
        this.nombre = nombre
        this.capital = capital
    }
}