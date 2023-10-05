class Persona() {
    /* Atributos */
    private var name = StringBuilder();
    private var surname = StringBuilder();
    private var age: Int = 0;

    /* Metodo Especial Secundario | Constructor Secundario */
    constructor(name:StringBuilder, surname:StringBuilder, age:Int) : this() {
        this.name = name;
        this.surname = surname;
        this.age = age;
    }

    /* Metodos */
    // Metodo publico //
    fun saludar(): Unit {
        println("Oh, Hi!\nMy full name is $name $surname! I'm $age years old!");
    }
}

class Car(var brand:StringBuilder, var model:StringBuilder) {
    fun showInfo() : Unit {
        println("Brand: $brand, Model: $model");
    }
}

// Constructor primario sin utilizar var para inicializar atributos //
class Car2(brand:StringBuilder, model:StringBuilder) {
    private var brand = StringBuilder()
    private var model = StringBuilder()

    // Inicializa las variables con los parametros captados //
    init {
        this.brand = brand
        this.model = model
    }

    fun showInfo() : Unit {
        println("Brand: $brand, Model: $model");
    }
}

fun main(args: Array<String>) {
    var person1 = Persona(StringBuilder("Cristopher"), StringBuilder("Vanegas"), 19);
    person1.saludar();

    var TeslaModelS = Car(StringBuilder("Tesla"), StringBuilder("S"));
    TeslaModelS.showInfo();

    var TeslaModelS2 = Car2(StringBuilder("Tesla"), StringBuilder("S2"));
    TeslaModelS2.showInfo();
}