open class Car(var brand:StringBuilder, var model:StringBuilder) {
    /* Open en una funcion o metodo es para permitir que sea Overrided o sea
       sobre escrita */
    open fun showInfo() {
        println("Marca: $brand, Model: $model");
    }
}

class hotWheels(brand:StringBuilder, model:StringBuilder, var escuderia:StringBuilder) : Car(brand, model) {
    fun mostrarEscuderiaConFormato() {
        println("**** $escuderia ****");
    }

    // Hago override del metodo padre showInfo() //
    override fun showInfo() {
        println("Marca: $brand, Model: $model, Escuderia: $escuderia");
    }
}

fun main(args: Array<String>) {
    println("Hello World!")

    // Try adding program arguments via Run/Debug configuration.
    // Learn more about running applications: https://www.jetbrains.com/help/idea/running-applications.html.
    println("Program arguments: ${args.joinToString()}")
}