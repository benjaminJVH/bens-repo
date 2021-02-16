#include "InputCheck.h"
#include <array>
#include <string>
#include <iostream>
using namespace std;

bool InputCheck::intInputCheck(bool& intLoop, const bool ignoreOptionZero, int& intUserInput, const int* numOptions, string errorMessage_1) {

	int optionZero = 0;
	int numSize = *numOptions;
	bool skip = false;
	bool* skipOptionItr = &skip;
	bool* rtnIntLoop = &intLoop;

	if (ignoreOptionZero) {
		optionZero = 1;
		numSize += 1;
	}
	else {
		optionZero = 0;
	}

	strIgnoreError(*rtnIntLoop, intUserInput, *skipOptionItr);

	if (!*skipOptionItr) {
		for (; optionZero < numSize; optionZero++) {
			if (optionZero == intUserInput) {
				*rtnIntLoop = true;
				return rtnIntLoop;
			}
		}
	}


	cout << "\n\t" << errorMessage_1 << "\n\n";
	return rtnIntLoop;
}

bool InputCheck::strIgnoreError(bool& rtnIntLoop, int& intUserInput, bool& skipOptionItr) {

	if (cin.fail()) {
		skipOptionItr = true;
		cin.clear();
		string ignoreError;
		getline(cin, ignoreError);
		rtnIntLoop = false;
		return skipOptionItr;
	}
}
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
