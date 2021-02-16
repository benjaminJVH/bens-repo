#include <iostream>
#include <string>
#include "MenuMaker.h"
#include "InputCheck.h"
using namespace std;

MenuMaker newMenu;
InputCheck newIntInputCheck;

void makeMenu(const string, const char*, const int*);

int main() {
	bool intLoop = false;
	int intUserInput = -1;
	const bool ignoreZero = true;

	const string menuTitle = "WELCOME TO THE FORTUNE TELLER 5000";
	const char* charMenuOptions[] = { " Enter your name ", " Enter your date of birth ", " Enter your favorite color ", 
										" Tell me my fortune ", " Exit program "};

	int optionSize = sizeof(charMenuOptions) / sizeof(const char*);
	const int* numOptions = &optionSize;
	do {
		newMenu.makeMenu(ignoreZero, menuTitle, charMenuOptions, numOptions);
		cin >> intUserInput;
		newIntInputCheck.intInputCheck(intLoop, intUserInput, numOptions);
	} while (!intLoop);
	cout << "Test completed.";
	return 0;
}