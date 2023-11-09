package com.example.hangman_game_java;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.text.Editable;
import android.text.TextWatcher;
import android.view.View;
import android.view.animation.Animation;
import android.view.animation.AnimationUtils;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TableRow;
import android.widget.TextView;
import android.widget.Toast;

import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.Scanner;

import kotlin.collections.UCollectionsKt;

public class MainActivity extends AppCompatActivity {

//    Declare variables
    TextView txtWordToBeGuessed;
    String wordToBeGuessed;
    String wordDisplayedString;
    char[] wordDisplayedCharArray;
    ArrayList<String> myListOfWord;
    EditText edtInput;
    TextView txtLettersTried;
    String lettersTried;
    final String MESSAGE_WITH_LETTERS_TRIED = "Letters tried:";
    TextView txtTriesLeft;
    String triesLeft;
    final String WINNING_MESSAGE = "You won!";
    final String LOSING_MESSAGE = "You lost!";
    Animation rotateAnimation;
    Animation scaleAnimation;
    Animation scaleAndRotateAnimation;
    TableRow trReset;
    TableRow trTriesLeft;

    void revealLetterInWord(char letter) {
        int indexOfLetter = wordToBeGuessed.indexOf(letter);

//        loop if index is positive or 0
        while (indexOfLetter >= 0) {
            wordDisplayedCharArray[indexOfLetter] = wordToBeGuessed.charAt(indexOfLetter); // replace the underscore to a char at position indexOfLetter in wordToBeGuessed
            indexOfLetter = wordToBeGuessed.indexOf(letter, indexOfLetter + 1);
        }

//        update the string as well
        wordDisplayedString = String.valueOf(wordDisplayedCharArray);
    }
    void displayWordOnScreen() {
        String formattedString = "";
        for (char character: wordDisplayedCharArray) {  // character traverse wordDisplayedCharArray
            formattedString += character + " ";   // character added to formattedString
        }
        txtWordToBeGuessed.setText(formattedString);
    }
    void initializeGame () {
//        1. WORD
//        shuffle array list and get first element, and then remove it
        Collections.shuffle(myListOfWord); // shuffle
        wordToBeGuessed = myListOfWord.get(0); // first word
        myListOfWord.remove(0); // avoid repeating the word before resetting game

//        initialize char array
        wordDisplayedCharArray = wordToBeGuessed.toCharArray();

//        add underscores
        for (int i = 1; i < wordDisplayedCharArray.length - 1; i++) {
            wordDisplayedCharArray[i] = '_';
        }

//        reveal all occurrences of first character
        revealLetterInWord(wordDisplayedCharArray[0]);

//        reveal all occurrences of last character
        revealLetterInWord(wordDisplayedCharArray[wordDisplayedCharArray.length - 1]);

//        initialize a string from this char array (for search purposes)
        wordDisplayedString = String.valueOf(wordDisplayedCharArray);

//        display word
        displayWordOnScreen();

//        2. INPUT
//        clear input field
        edtInput.setText("");

//        3. Letters tried
//        initialize string for letters tried with a space
        lettersTried = " ";

//        display on screen
        txtLettersTried.setText(MESSAGE_WITH_LETTERS_TRIED);

//        4. Tries left
//        initialize the string for tries left
        triesLeft = " \uD83D\uDC80 \uD83D\uDC80 \uD83D\uDC80 \uD83D\uDC80 \uD83D\uDC80";
        txtTriesLeft.setText(triesLeft);
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

//       initialize variables
        myListOfWord = new ArrayList<String>();
        txtWordToBeGuessed = (TextView) findViewById(R.id.txtWordToBeGuessed);  // casting from VIEW to TEXTVIEW
        edtInput = (EditText) findViewById(R.id.edtInput); // casting from VIEW to EDITTEXT
        txtLettersTried = (TextView) findViewById(R.id.txtLettersTried);
        txtTriesLeft = (TextView) findViewById(R.id.txtTriesLeft);
        rotateAnimation = AnimationUtils.loadAnimation(this, R.anim.rotate);
        scaleAnimation = AnimationUtils.loadAnimation(this, R.anim.scale);
        scaleAndRotateAnimation = AnimationUtils.loadAnimation(this, R.anim.scale_and_rotate);
        scaleAndRotateAnimation.setFillAfter(true);
        trReset = (TableRow) findViewById(R.id.trReset);
        trTriesLeft = (TableRow) findViewById(R.id.trTriesLeft);

//        traverse database file and populate array list
        InputStream myInputStream = null; // information from input
        Scanner in = null;
        String aWord = "";
        try {
            myInputStream = getAssets().open("database_file.txt");  // gets the entire file
            in = new Scanner(myInputStream);    // initialize the scanner
            while (in.hasNext()) {  // iterates if it has next word
                aWord = in.next();  // sWord is asigned the first word
                myListOfWord.add(aWord);    // added aWord to myListOfWord
            }
        } catch (IOException e) {
            Toast.makeText(MainActivity.this,
                    e.getClass().getSimpleName() + ": " + e.getMessage(),
                    Toast.LENGTH_SHORT).show();
        } finally {
            // close scanner
            if (in != null) in.close();

            // close InputStream
            try {
                if (myInputStream != null) myInputStream.close();
            } catch (IOException e) {
                Toast.makeText(MainActivity.this,
                        e.getClass().getSimpleName() + ": " + e.getMessage(),
                        Toast.LENGTH_SHORT).show();
            }
        }

//        initialize game
        initializeGame();

//        setup the text changed listener for the edit text
        edtInput.addTextChangedListener(new TextWatcher() {
            @Override
            public void beforeTextChanged(CharSequence s, int start, int count, int after) {
            }
            @Override
            public void onTextChanged(CharSequence s, int start, int before, int count) {
                if (s.length() != 0) {
                    checkIfLetterIsInWord(s.charAt(0));
                }
            }
            @Override
            public void afterTextChanged(Editable s) {
            }
        });

//        Reset Game
        Button btnReset = (Button) findViewById(R.id.btnReset);
        btnReset.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                // start animation
                trReset.startAnimation(rotateAnimation);

                // clearAnimations on table row
                trTriesLeft.clearAnimation();

                // Aquí puedes realizar las acciones que deseas cuando se haga clic en el botón
                // Por ejemplo, puedes llamar a una función para reiniciar el juego
                initializeGame();
            }
        });
    } /* end of onCreate method */

    void checkIfLetterIsInWord(char letter) {
//        if the letter was found inside the word to be guessed.
        if (wordToBeGuessed.indexOf(letter) >= 0) { // if found the letter
            // if the letter was NOT displayed yet
            if (wordDisplayedString.indexOf(letter) < 0) {
//                animate
                txtWordToBeGuessed.startAnimation(scaleAnimation);

//                replace the underscores with that letter
                revealLetterInWord(letter);

//                update the changes on screen
                displayWordOnScreen();

                // check if the game is won
                if (!wordDisplayedString.contains("_")) {
                    trTriesLeft.startAnimation(scaleAndRotateAnimation);
                    txtTriesLeft.setText(WINNING_MESSAGE);
                }
            }
        }
//        otherwise, if the letter was NOT found inside the word to be guessed
        else {
            // decrease the number of tries left, and we'll shot it on screen
            decreaseAndDisplayTriesLeft();

            // check if the game is lost
            if (triesLeft.isEmpty()) {
                trTriesLeft.startAnimation(scaleAndRotateAnimation);
                txtTriesLeft.setText(LOSING_MESSAGE);
                txtWordToBeGuessed.setText(wordToBeGuessed);
            }
        }

//        display the letter that was tried
        if (lettersTried.indexOf(letter) < 0) {
            if (lettersTried.length() == 1) lettersTried += letter;
            else lettersTried += ", " + letter;

            String messageToBeDisplayed = MESSAGE_WITH_LETTERS_TRIED + lettersTried;
            txtLettersTried.setText(messageToBeDisplayed);
        }

    } /* end of checkIfLetterIsInWord() method */

    void decreaseAndDisplayTriesLeft() {
//        if there are still some tries left
        if (!triesLeft.isEmpty()) {
//            animate
            trTriesLeft.startAnimation(scaleAnimation);

//            take out the last 2 characters from this string
            triesLeft = triesLeft.substring(0, triesLeft.length() - 3);
            txtTriesLeft.setText(triesLeft);
        }
    }
}












