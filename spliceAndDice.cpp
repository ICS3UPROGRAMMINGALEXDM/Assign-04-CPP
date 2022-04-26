#include <iostream>
#include <list>
#include <string>
#include <list>
#include <vector>
#include "h-files/colors.h"

using std::string;
using std::stoi;
using std::cin;
using std::cout;
using std::endl;


// initializing variables
string uString, finalString, newString, uSize, uCopies, answer, charArr;
int copies, size, arryLength;
bool errorLoop = true, answerLoop = true;



void splitString() {
	arryLength = uString.length();
	charArr[arryLength];
	charArr = uString;
	for (int counter = 0; counter < uString.length(); counter++) {
		newString = newString + charArr[counter];
		cout << newString << endl;
		
	}

}


int main()
{
	do {
        cout << BOLDWHITE << "Enter a word or phrase to be Splice&Diced: ";
        cin >> uString;
        while (errorLoop){
        	cout << "Enter how many characters long you want the Splice&Diced word to be: ";
        	cin >> uSize;
        	
        	cout << "Enter how many times you want the Splice&Diced word to repeat: ";
        	cin >> uCopies;
        	try{
        		size = stoi(uSize);
        		copies = stoi(uCopies);
				if ()
					splitString();
				
        	} catch (...) {
        		cout << "Please ensure size and copies are vaild integers" << endl;
        	}
        }
	} while(answer == "y");
}