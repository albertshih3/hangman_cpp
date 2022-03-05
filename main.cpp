// Your code here
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// createDashes function creates the dashes to output when we enter a word
void createDashes(vector<string>& dashes, vector<string>& guessedWord, string& wordToGuess) {
    for (int i = 0; i < wordToGuess.length(); i++) {
        dashes.push_back("_");
    }
    for (int i = 0; i < wordToGuess.length(); i++) {
        guessedWord.push_back("-");
    }
    for (int i = 0; i < dashes.size(); i++) {
        cout << dashes[i] << " ";
    }
    cout << endl;
}

// checkInput checks the inputted letter against the actual word.
void checkInput(vector<string>& dashes, string& wordToGuess, string& inputLetter, vector<string>& guessedWord, int& guessLimit, vector<string>& guessedLetters) {
    bool found;
    for (int i = 0; i < wordToGuess.length(); i++) {
        if (inputLetter.at(0) == wordToGuess.at(i)) {
            dashes.at(i) = inputLetter;
            guessedWord.at(i) = inputLetter;
            found = true;
        }
    }
    guessedLetters.push_back(inputLetter);
    if (found == false) {
        guessLimit = guessLimit - 1;
        cout << "Incorrect! Please try again (-1 lives)" << endl;
    }
}

// outputStats collects the stats of the game and can be used to output game stats when needed
void outputStats(int& guessLimit, vector<string>& guessedLetters) {
    cout << "-=- Game Stats -=-" << endl;
    cout << "Guesses Remaining: " << guessLimit << endl;
    cout << "Guessed Letters: ";
    for (int i = 0; i < guessedLetters.size(); i++) {
        cout << guessedLetters.at(i) << " ";
    }
    cout << endl;
}

int main() {

    // DEFINITIONS OF VARIABLES & VECTORS
    string wordToGuess;
    string inputLetter;
    int guessLimit = 6;
    vector<string> dashes;
    vector<string> guessedLetters;
    vector<string> guessedWord;


    start:
    // Welcome the user and ask for a word which can be guessed. Generates dashes for UI.
    cout << "Welcome to hangman!" << endl;
    cout << "Have a friend enter a word to guess: ";
    getline(cin, wordToGuess);
    createDashes(dashes, guessedWord, wordToGuess);

    // While loop will continue to run until the user has ran out of guesses or the user guesses the
    // word correctly
    system("clear");
    while (dashes != guessedWord && guessLimit > 0) {

        system("clear");
        outputStats(guessLimit, guessedLetters);

        for (int i = 0; i < dashes.size(); i++) {
            cout << dashes[i] << " ";
        }
        cout << endl;

        cout << "Enter ONE letter: ";
        getline(cin, inputLetter);

        while (inputLetter.length() > 1) {
            cout << "Please make sure you only enter ONE letter!" << endl << "Enter ONE letter: ";
            getline(cin, inputLetter);
        }

        checkInput(dashes, wordToGuess, inputLetter, guessedWord, guessLimit, guessedLetters);
    }
    system("clear");
    outputStats(guessLimit, guessedLetters);

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
