// Con "open" se habilita la posibilidad de que sea heredada //
open class Person() {
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

class Teacher : Person {
    constructor(name:StringBuilder, surname:StringBuilder, age:Int) : super(name, surname, age)

    fun takeAssistance() {
        println(" [ Teacher ] Assistance Done!");
    }
}

class Student : Person {
    constructor(name: StringBuilder, surname: StringBuilder, age: Int) : super(name, surname, age)

    fun GoToU() {
        println(" [ Student ] Going to university!");
    }
}

    fun main(args: Array<String>) {
    var Teacher1 = Teacher(StringBuilder("Antonio"), StringBuilder("Nicolas"), 48);
    Teacher1.saludar();
    Teacher1.takeAssistance();

    var Student1 = Student(StringBuilder("Cristopher"), StringBuilder("Vanegas"), 19);
    Student1.GoToU();
}