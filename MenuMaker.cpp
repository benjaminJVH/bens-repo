#include "MenuMaker.h"
#include <string>
#include <iostream>

using namespace std;

void MenuMaker::makeMenu(const bool ignoreOptionZero, const string menuTitle, const char* charMenuOptions[], const int* numOptions) {
	int options = *numOptions;
	int displMenu = 0;
	int igZero = 0;

	if (ignoreOptionZero) {
		displMenu = 1;
		igZero = 1;
	}
	else {
		options += 1;
		displMenu = 0;
		igZero = 1;
	}

	cout << "\t\t" << menuTitle << "\n" << endl;
	for (int i = 0, x = 1; i < *numOptions; i++, x++, displMenu++) {
		if (!ignoreOptionZero) {
			if (x >= options) {
				x = 0;
			}
		}

		cout << " " << displMenu << " " << charMenuOptions[x - igZero] << "\n";
	}
	cout << "\n <: ";
}

/*


bool ErrorCatcher::userInputCheck(string& input, bool& userInput) {
	string wordError;
	int const MAX_CHAR_LIMIT = 21;
	int wordLength;
	int limitExceeded;

	getline(cin, wordError);
	wordLength = input.length();
	limitExceeded = (wordLength - MAX_CHAR_LIMIT);

	for (int i = 0; i < wordError.length(); i++) {
		if (isspace(wordError.at(i))) {
			cout << "\nOne word at a time! Please re-enter word." << endl;
			userInput = false;
			return userInput;
		}
	}

	if (input.length() > MAX_CHAR_LIMIT) {
		cout << "\nYou exceeded the 21 maximum character limit by " << limitExceeded << "!" << endl;
	}
	else {
		userInput = true;
		return userInput;
	}
	userInput = false;
	return userInput;
}
int ErrorCatcher::wordCounterTracker(bool& userInput, int& wordCount) {
	if (userInput) wordCount++; return wordCount;
}


*/