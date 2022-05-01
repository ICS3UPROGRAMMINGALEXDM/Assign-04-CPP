// Copyright (c) 2022 Alex De Meo All rights reserved
//
// Created By: Alex De Meo
// Date: 04s//22
// Description: Gets a string from the user, then asks how long they want the
// sub strings to be, along with how many times this sub string is repeated.
// The program will then loop through according to the users "order" and display
// The final string.
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include "h-files/colors.h"

using std::string;
using std::stoi;
using std::cin;
using std::cout;
using std::endl;
using std::stof;


// initializing variables
int arryLength;
float copies, size;
bool errorLoop = true, answerLoop = true;

// function is used to loop through the array and create the final string to be
// displayed to the user
void looping(string uString, string charArr) {
	cout << charArr[0] << endl;
    string finalString, newString;
    // resetting variables
    finalString = "";
    newString = "";
    // inner loop is meant to meet the size requirements,
    // outer loop is for copies
    for (int counter1 = 1; counter1 <= copies; counter1++) {
        for (int counter = 0; counter < size; counter++) {
            newString += charArr[counter];
        }
        // updating the final string
        finalString += newString;
        // updating the new string
        newString = "";
    }
    // Displaying the results
    cout << endl << "The Splice&Diced result is..." << BOLDYELLOW <<
    endl << finalString << endl << endl;
}

// this function puts each character of the string into an array
void splitString(string uString, string charArr) {
    arryLength = uString.length();
    charArr[arryLength];
    charArr = uString;
}


int main() {
    string uString, uSize, uCopies, answer, charArr;
    do {
        // resetting booleans
        errorLoop = true;
        answerLoop = true;
        // asking for a string
        cout << BOLDWHITE << "Enter a word or phrase to be Splice&Diced: ";
        // this makes sure the whole line is taken by the cin funtion and won't
        // be messed up by a space that is entered
        std::getline(cin >> std::ws, uString);
        // calls function to put into an array
        splitString(uString, charArr);
        while (errorLoop) {
            // get size
            cout << BOLDWHITE << "Enter how many characters " <<
            "long you want the Splice&Diced word to be: ";
            cin >> uSize;
            // get amount of copies
            cout << "Enter how many times you want " <<
            "the Splice&Diced word to repeat: ";
            cin >> uCopies;
            try {
                // converting to floats
                size = stof(uSize);
                copies = stof(uCopies);
                // checks to ensure that copies and size aren't out of range.
                // also checks to make sure that no
                // extra decimal spaces were entered
                if (
                    size < 1 || copies < 1 ||
                    size > uString.length() ||
                    copies != static_cast<int>(copies) ||
                    size != static_cast<int>(size)) {
                    cout << BOLDMAGENTA << "Make sure copies " <<
                    "and size are greater than 0. AND that " <<
                    "size is NOT greater than the " <<
                    "amount of characters in the" <<
                    " word/phrase. Ensure all numbers are whole." << endl;
                } else {
                    errorLoop = false;
                    // calls the function to create final string
                    looping(uString, charArr);
                    while (answerLoop) {
                        cout << BOLDWHITE <<
                        "Would you like to Splice&Dice another word? (y/n): ";
                        cin >> answer;
                        // this allows the user to restart or end the program
                        if (answer == "n") {
                            cout << "Okay" << endl;
                            answerLoop = false;
                        } else if (answer == "y") {
                            answerLoop = false;
                        } else {
                            cout << "I'm not sure I understand." <<
                            " Please try again." << endl;
                        }
                    }
                }
            } catch (...) {
                cout << BOLDRED <<
                "Please ensure size and copies " <<
                "are vaild and positive integers" <<
                BOLDWHITE << endl;
            }
        }
    } while (answer == "y");
}
