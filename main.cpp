// Your code here
#include <iostream>
#include <vector>
#include <string>
#include <helperfunc.h>

using namespace std;

int main() {

    // DEFINITIONS OF VARIABLES & VECTORS
    string wordToGuess;
    string inputLetter;
    int guessLimit = 6;
    vector<string> dashes;
    vector<string> guessedLetters;
    vector<string> guessedWord;

    // Welcome the user and ask for a word which can be guessed. Generates dashes for UI.
    cout << "Welcome to hangman!" << endl;
    cout << "Have a friend enter a word to guess: ";
    getline(cin, wordToGuess);
    
    // New code to try and turn inputted word into uppercase
    
    transform(wordToGuess.begin(), wordToGuess.end(), wordToGuess.begin(), ::toupper);
    
    game::createDashes(dashes, guessedWord, wordToGuess);

    // While loop will continue to run until the user has ran out of guesses or the user guesses the
    // word correctly
    system("clear");
    while (dashes != guessedWord && guessLimit > 0) {

        system("clear");
        game::outputStats(guessLimit, guessedLetters);

        for (int i = 0; i < dashes.size(); i++) {
            cout << dashes[i] << " ";
        }
        cout << endl;

        cout << "Enter ONE letter: ";
        getline(cin, inputLetter);
        
        transform(inputLetter.begin(), inputLetter.end(), inputLetter.begin(), ::toupper);

        while (inputLetter.length() > 1) {
            cout << "Please make sure you only enter ONE letter!" << endl << "Enter ONE letter: ";
            getline(cin, inputLetter);
        }

        game::checkInput(dashes, wordToGuess, inputLetter, guessedWord, guessLimit, guessedLetters);
    }
    system("clear");
    game::outputStats(guessLimit, guessedLetters);

    for (int i = 0; i < dashes.size(); i++) {
        cout << dashes[i] << " ";
    }
    cout << endl;

    if (dashes == guessedWord) {
        cout << "Congratulations on completing the game! The word was " << wordToGuess << endl;
    }
    else {
        cout << "It looks like you didn't guess correctly! The word was " << wordToGuess << endl;
    }

    return 0;
}
