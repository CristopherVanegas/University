var str : String = "Programación 4";

fun main(args: Array<String>) {
    println("Iterando el string \"$str\"");

    for (idx in 0 until str.length) {
        val char = str[idx];
        print("$char ");
        continue;
    }

    str = "";
    println("\n > String vacío: " + str);
}