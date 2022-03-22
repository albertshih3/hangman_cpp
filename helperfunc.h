// helperfunc.h header file
// contains helper functions for the main program

#ifndef helperfunc.h
#define helperfunc.h

#include <iostream>
#include <string>
#include <vector>

namespace game {

    // createDashes function creates the dashes to output when we enter a word
    void createDashes(std::vector<std::string>& dashes, std::vector<std::string>& guessedWord, std::string& wordToGuess) {
        for (int i = 0; i < wordToGuess.length(); i++) {
            dashes.push_back("_");
        }
        for (int i = 0; i < wordToGuess.length(); i++) {
            guessedWord.push_back("-");
        }
        for (int i = 0; i < dashes.size(); i++) {
            std::cout << dashes[i] << " ";
        }
        std::cout << std::endl;
    }

    // checkInput checks the inputted letter against the actual word.
    void checkInput(std::vector<std::string>& dashes, std::string& wordToGuess, std::string& inputLetter, std::vector<std::string>& guessedWord, int& guessLimit, std::vector<std::string>& guessedLetters) {
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
            std::cout << "Incorrect! Please try again (-1 lives)" << std::endl;
        }
    }

    // outputStats collects the stats of the game and can be used to output game stats when needed
    void outputStats(int& guessLimit, std::vector<std::string>& guessedLetters) {
        std::cout << "-=- Game Stats -=-" << std::endl;
        std::cout << "Guesses Remaining: " << guessLimit << std::endl;
        std::cout << "Guessed Letters: ";
        for (int i = 0; i < guessedLetters.size(); i++) {
            std::cout << guessedLetters.at(i) << " ";
        }
        std::cout << std::endl;
    }

}

#endif
