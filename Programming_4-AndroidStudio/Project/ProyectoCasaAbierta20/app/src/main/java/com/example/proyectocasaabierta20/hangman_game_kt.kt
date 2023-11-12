package com.example.proyectocasaabierta20

import android.os.Bundle
import android.os.Handler
import android.os.Looper
import android.text.Editable
import android.text.TextWatcher
import android.view.animation.Animation
import android.view.animation.AnimationUtils
import android.widget.Button
import android.widget.EditText
import android.widget.TableRow
import android.widget.TextView
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity
import java.io.IOException
import java.io.InputStream
import java.util.*

class hangman_game_kt : AppCompatActivity() {

    // Declare variables
    private lateinit var txtWordToBeGuessed: TextView
    private lateinit var wordToBeGuessed: String
    private lateinit var wordDisplayedString: String
    private lateinit var wordDisplayedCharArray: CharArray
    private lateinit var myListOfWord: ArrayList<String>
    private lateinit var edtInput: EditText
    private lateinit var txtLettersTried: TextView
    private lateinit var lettersTried: String
    private val MESSAGE_WITH_LETTERS_TRIED = "Letters tried:"
    private lateinit var txtTriesLeft: TextView
    private lateinit var triesLeft: String
    private val WINNING_MESSAGE = "You won!"
    private val LOSING_MESSAGE = "You lost!"
    private lateinit var rotateAnimation: Animation
    private lateinit var scaleAnimation: Animation
    private lateinit var scaleAndRotateAnimation: Animation
    private lateinit var trReset: TableRow
    private lateinit var trTriesLeft: TableRow

    private fun revealLetterInWord(letter: Char) {
        var indexOfLetter = wordToBeGuessed.indexOf(letter)

        // loop if index is positive or 0
        while (indexOfLetter >= 0) {
            wordDisplayedCharArray[indexOfLetter] = wordToBeGuessed[indexOfLetter]

            // replace the underscore to a char at position indexOfLetter in wordToBeGuessed
            indexOfLetter = wordToBeGuessed.indexOf(letter, indexOfLetter + 1)
        }

        // update the string as well
        wordDisplayedString = String(wordDisplayedCharArray)
    }

    private fun displayWordOnScreen() {
        var formattedString = ""
        for (character in wordDisplayedCharArray) {
            // character traverse wordDisplayedCharArray
            formattedString += "$character "
        }
        txtWordToBeGuessed.text = formattedString
    }

    private fun initializeGame() {
        // 1. WORD
        // shuffle array list and get first element, and then remove it
        Collections.shuffle(myListOfWord) // shuffle
        wordToBeGuessed = myListOfWord[0] // first word
        myListOfWord.removeAt(0) // avoid repeating the word before resetting game

        // initialize char array
        wordDisplayedCharArray = wordToBeGuessed.toCharArray()

        // add underscores
        for (i in 1 until wordDisplayedCharArray.size - 1) {
            wordDisplayedCharArray[i] = '_'
        }

        // reveal all occurrences of first character
        revealLetterInWord(wordDisplayedCharArray[0])

        // reveal all occurrences of last character
        revealLetterInWord(wordDisplayedCharArray[wordDisplayedCharArray.size - 1])

        // initialize a string from this char array (for search purposes)
        wordDisplayedString = String(wordDisplayedCharArray)

        // display word
        displayWordOnScreen()

        // 2. INPUT
        // clear input field
        edtInput.setText("")

        // 3. Letters tried
        // initialize string for letters tried with a space
        lettersTried = " "

        // display on screen
        txtLettersTried.text = MESSAGE_WITH_LETTERS_TRIED

        // 4. Tries left
        // initialize the string for tries left
        triesLeft = " \uD83D\uDC80 \uD83D\uDC80 \uD83D\uDC80 \uD83D\uDC80 \uD83D\uDC80"
        txtTriesLeft.text = triesLeft
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.hangman_game)

        // initialize variables
        myListOfWord = ArrayList()
        txtWordToBeGuessed = findViewById(R.id.txtWordToBeGuessed)
        edtInput = findViewById(R.id.edtInput)
        txtLettersTried = findViewById(R.id.txtLettersTried)
        txtTriesLeft = findViewById(R.id.txtTriesLeft)
        rotateAnimation = AnimationUtils.loadAnimation(this, R.anim.rotate)
        scaleAnimation = AnimationUtils.loadAnimation(this, R.anim.scale)
        scaleAndRotateAnimation = AnimationUtils.loadAnimation(this, R.anim.scale_and_rotate)
        scaleAndRotateAnimation.fillAfter = true
        trReset = findViewById(R.id.trReset)
        trTriesLeft = findViewById(R.id.trTriesLeft)

        // traverse database file and populate array list
        var myInputStream: InputStream? = null // information from input
        var inStream: Scanner? = null
        var aWord = ""
        try {
            myInputStream = assets.open("database_file.txt")  // gets the entire file
            inStream = Scanner(myInputStream)    // initialize the scanner
            while (inStream.hasNext()) {  // iterates if it has next word
                aWord = inStream.next()  // sWord is assigned the first word
                myListOfWord.add(aWord)    // added aWord to myListOfWord
            }
        } catch (e: IOException) {
            Toast.makeText(
                this,
                "${e.javaClass.simpleName}: ${e.message}",
                Toast.LENGTH_SHORT
            ).show()
        } finally {
            // close scanner
            inStream?.close()

            // close InputStream
            try {
                myInputStream?.close()
            } catch (e: IOException) {
                Toast.makeText(
                    this,
                    "${e.javaClass.simpleName}: ${e.message}",
                    Toast.LENGTH_SHORT
                ).show()
            }
        }

        // initialize game
        initializeGame()

        // setup the text changed listener for the edit text
        edtInput.addTextChangedListener(object : TextWatcher {
            override fun beforeTextChanged(s: CharSequence?, start: Int, count: Int, after: Int) {}

            override fun onTextChanged(s: CharSequence?, start: Int, before: Int, count: Int) {
                if (!s.isNullOrBlank() && s.isNotEmpty()) {
                    checkIfLetterIsInWord(s[0])
                }
            }

            override fun afterTextChanged(s: Editable?) {}
        })

        // Limpia edtInput luego de ingresar una letra
        val handler = Handler(Looper.getMainLooper())

        edtInput.addTextChangedListener(object : TextWatcher {
            override fun beforeTextChanged(s: CharSequence?, start: Int, count: Int, after: Int) {
                // No es necesario implementar nada aquí
            }

            override fun onTextChanged(s: CharSequence?, start: Int, before: Int, count: Int) {
                // No es necesario implementar nada aquí
            }

            override fun afterTextChanged(s: Editable?) {
                if (s?.length ?: 0 > 0) {
                    // Realiza tu lógica para verificar si la letra está en la palabra
                    checkIfLetterIsInWord(s!![0])

                    // Establece un retraso de 1 segundo para borrar el texto
                    handler.removeCallbacksAndMessages(null) // Cancela cualquier retraso pendiente
                    handler.postDelayed({
                        edtInput.text.clear()
                    }, 250) // 1000 milisegundos = 1 segundo
                }
            }
        })

        // Reset Game
        val btnReset: Button = findViewById(R.id.btnReset)
        btnReset.setOnClickListener {
            // start animation
            trReset.startAnimation(rotateAnimation)

            // clearAnimations on table row
            trTriesLeft.clearAnimation()

            // Aquí puedes realizar las acciones que deseas cuando se haga clic en el botón
            // Por ejemplo, puedes llamar a una función para reiniciar el juego
            initializeGame()
        }
    } /* end of onCreate method */

    private fun checkIfLetterIsInWord(letter: Char) {
        // if the letter was found inside the word to be guessed.
        if (wordToBeGuessed.indexOf(letter) >= 0) {
            // if the letter was NOT displayed yet
            if (wordDisplayedString.indexOf(letter) < 0) {
                // animate
                txtWordToBeGuessed.startAnimation(scaleAnimation)

                // replace the underscores with that letter
                revealLetterInWord(letter)

                // update the changes on screen
                displayWordOnScreen()

                // check if the game is won
                if (!wordDisplayedString.contains("_")) {
                    trTriesLeft.startAnimation(scaleAndRotateAnimation)
                    txtTriesLeft.text = WINNING_MESSAGE
                }
            }
        }
        // otherwise, if the letter was NOT found inside the word to be guessed
        else {
            // decrease the number of tries left, and we'll show it on the screen
            decreaseAndDisplayTriesLeft()

            // check if the game is lost
            if (triesLeft.isEmpty()) {
                trTriesLeft.startAnimation(scaleAndRotateAnimation)
                txtTriesLeft.text = LOSING_MESSAGE
                txtWordToBeGuessed.text = wordToBeGuessed
            }
        }

        // display the letter that was tried
        if (lettersTried.indexOf(letter) < 0) {
            lettersTried += if (lettersTried.length == 1) letter else ", $letter"
            val messageToBeDisplayed = "$MESSAGE_WITH_LETTERS_TRIED $lettersTried"
            txtLettersTried.text = messageToBeDisplayed
        }
    } /* end of checkIfLetterIsInWord() method */

    private fun decreaseAndDisplayTriesLeft() {
        // if there are still some tries left
        if (!triesLeft.isEmpty()) {
            // animate
            trTriesLeft.startAnimation(scaleAnimation)

            // take out the last 2 characters from this string
            triesLeft = triesLeft.substring(0, triesLeft.length - 3)
            txtTriesLeft.text = triesLeft
        }
    }
}
