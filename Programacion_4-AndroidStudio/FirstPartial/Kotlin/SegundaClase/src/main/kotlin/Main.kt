fun main(args: Array<String>) {
    val valor : Float = 10.15F;
    println("El valor final de $valor + iva es ${calcularIva(valor)}")
}

fun calcularIva(precio : Float) : Float /* Con :Float digo que tipo de dato volvera */
{
    val iva : Float = 0.12F;
    val r = precio + (precio * iva);

    return r;
}

fun concat() {
    var nombre : String = "Cristopher";
    var apellido : String = "Vanegas";
    val date : Int = 21;

    println("Nombre completo $nombre" + "$apellido" + "$date");
}

