#include "InputCheck.h"
#include <array>
#include <string>
#include <iostream>
using namespace std;

int InputCheck::intInputCheck(bool& intLoop, int& intUserInput, int numOptions, int startingOption, string errorMessage_1, bool &backMenu) {	
	int numSize = numOptions;
	bool skip = false;
	bool* skipOptionItr = &skip;
	bool* rtnIntLoop = &intLoop;

	strIgnoreError(*rtnIntLoop, intUserInput, *skipOptionItr);	
	if (!*skipOptionItr) {
		for (; startingOption <= numSize; startingOption++) {
			if (startingOption == intUserInput) {
				*rtnIntLoop = false;
				return intUserInput;
			}else if(backMenu){
				//exit(0);
				return 0;
			}
		}
	}

	cout << "\n\t" << errorMessage_1 << "\n\n";
	return intUserInput;
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

//second unique error handling for swtich cases

bool InputCheck::stringInputCheck(string& strUserInput, int numOptions, bool& stringLoop, const int* MAX_CHAR_LIMIT,
	const string strErrorMessage_1) {
	string wordError;
	int wordLength;
	int limitExceeded;

	getline(cin, wordError);
	wordLength = strUserInput.length();
	limitExceeded = (wordLength - *MAX_CHAR_LIMIT);

	for (int i = 0; i < wordError.length(); i++) {
		if (isspace(wordError.at(i))) {
			cout << "\n" << strErrorMessage_1 << endl;
			stringLoop = false;
			return stringLoop;
		}
	}

	if (wordLength > *MAX_CHAR_LIMIT) {
		cout << "\n" << "You have exceeded the " << MAX_CHAR_LIMIT << " maximum character limit by " << limitExceeded << "!" << endl;
	}
	else {
		stringLoop = true;
		return stringLoop;
	}
	stringLoop = false;
	return stringLoop;
}
