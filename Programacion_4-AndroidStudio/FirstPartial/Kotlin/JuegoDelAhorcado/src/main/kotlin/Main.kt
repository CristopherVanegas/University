/**
 * Hangman Game
 * Est. Cristopher Vanegas - Cod2022291831
 * 2 Sep 2023
 */

import kotlin.random.Random;

// Words to guess
val words = mutableListOf(
    "Apple",
    "Computer",
    "Dog",
    "Cat",
    "Ball",
    "University",
    "Mountain",
    "Developer",
    "Excursion",
    "Turtle"
)

var word = StringBuilder("");                         // Word to play
var spaces = StringBuilder("");                   // String to complete
var charUsed = mutableListOf<Char>();         // Character keeper, avoid repeated characters
var attemps : Int = 0;                            // Attemps counter
const val MaxAttemps : Int = 5;                 // Attemps to play
var char : Char = '0';                              // Char to read the character input
var flag : Boolean = false;                      // Flag to continue playing


fun main() {
    game();
}

fun game() {
    do {
        // code //
        initializeWordAndSpaces();

        do {
            showIncompleteWord();
            printAttemps();
            char = askForCharacter();
            addCharacter(char);

            if (word.equals(spaces)) {
                break;
            }
        } while (attemps < MaxAttemps)
    } while (youLost());
}

fun addCharacter(c : Char) {
    // Search if the char has not been used //
    if (c in charUsed) {
        println(" > Character already used, use another!");
        // If not //
    }
    else {
        // Iterates word and keep indices to future char change //
        keepChar(c);
        for (i in word.indices) {
            flag = true;
            // If its equal then its replaced by c //
            if (word[i] == c) {
                spaces[i] = c;
                flag = false;
            }
        }
        // attemps++ if char did not fill //
        if (flag == false) {
            attemps++;
        }
    }
}

fun keepChar(c : Char) : Unit {
    charUsed.add(c);
}

fun upgradeSpaces(i : Int, c : Char) : Unit {
    spaces[i] = c;
}

fun printAttemps() {
    println(" [Attemps] $attemps");
}

fun youLost() : Boolean {
    do {
        println(" You Lost! Do you want to play again? (Y / N)");
        // Converts line to lowercase and then takes the first char //
        char = readln().lowercase().single();
    } while (char != 'y' && char != 'n')

    return if (char == 'y') true else false;
}

fun showIncompleteWord() : Unit {
    println(word);
    for (char in spaces) {
        print(char);
    }
}

fun initializeWordAndSpaces() {
    // Initialize word //
    val randInt : Int = Random.nextInt(0, (words.size - 1));
    word = StringBuilder(words[randInt].lowercase());
    spaces = StringBuilder("");

    // Initialize spaces //
    for (i in word.indices) {
        spaces.append("_");
    }

    // Initialize Attemps //
    attemps = 0;
}

fun askForCharacter() : Char {
    var c : String = "";
    do {
        print(" [] Please, enter just a character you think it fills the word spaces: ")
        c = readln().lowercase().toString();
    } while (c == "");

    return c[0];
}

