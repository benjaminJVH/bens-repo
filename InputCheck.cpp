#include "InputCheck.h"
#include <array>
#include <string>
#include <iostream>
using namespace std;



bool InputCheck::intInputCheck(bool& intLoop, int intUserInput, const int* numOptions) {

	bool *rtnIntLoop = &intLoop;
	if (cin.fail()) {
		cin.clear();
		string ignoreError;
		getline(cin, ignoreError);
		*rtnIntLoop = false;
	}
	else {
		for (int i = 0; i < *numOptions; i++) {
			if (i == intUserInput) {
				*rtnIntLoop = true;
				return rtnIntLoop;
			}
		}		
		
	}
	cout << "\n\tInvalid Entry.  Please choose available options.\n\n";
	return rtnIntLoop;
}

//bool intMenuInputCheck(bool& ignoreZero, int* numOptions, int intChoice, bool& intMenuInput) {
//	int check = intChoice;
//	if (cin.fail()) {
//		cin.clear();
//		string ignoreError;
//		getline(cin, ignoreError);
//	}	
//	else if (check != 0 && check != 1 && check != 2 && check != 3) {
//		intMenuInput = false;		// redundant, keeping this here anyway for looks
//	}
//	else {
//		intMenuInput = true;
//		return intMenuInput;
//	}
//	cout << "\n\tInvalid input\nPlease choose only available numbers\n";
//	intMenuInput = false;
//	return intMenuInput;
//}
//
//
//// second part of first error handling for mainmenu interface - overloaded function
//bool intMenuInputCheck(int choice, bool& intMenuInput, bool& choiceCheck) {
//	int check = choice;
//	if (cin.fail()) {
//		cin.clear();
//		string ignoreError;
//		getline(cin, ignoreError);
//	}
//	else if (check < 0 || check > 12) {
//		intMenuInput = false;		// redundant, keeping this here anyway for looks
//	}
//	else {
//		intMenuInput = true;
//		return intMenuInput;
//	}
//	cout << "\n\tInvalid input\nPlease choose only available numbers\n";
//	intMenuInput = false;
//	return intMenuInput;
//}
//
//// second unique error handling for swtich cases -
//bool userInputCheck(string& input, bool& userInput) {
//	string wordError;
//	int wordLength;
//	int limitExceeded;
//
//	getline(cin, wordError);
//	wordLength = input.length();
//	limitExceeded = (wordLength - MAX_CHAR_LIMIT);
//
//	for (int i = 0; i < wordError.length(); i++) {
//		if (isspace(wordError.at(i))) {
//			cout << "\nOne word at a time! Please re-enter word." << endl;
//			userInput = false;
//			return userInput;
//		}
//	}
//
//	if (input.length() > MAX_CHAR_LIMIT) {
//		cout << "\nYou exceeded the 21 maximum character limit by " << limitExceeded << "!" << endl;
//	}
//	else {
//		userInput = true;
//		return userInput;
//	}
//	userInput = false;
//	return userInput;
//}
