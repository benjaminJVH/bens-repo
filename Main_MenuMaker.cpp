#include <iostream>
#include <string>
#include <array>
#include "MenuMaker.h"
using namespace std;

MenuMaker newMenu;

void makeMenu(const string, const char*, const int*);

int main() {
	int intUserInput = -1;
	// Initialize array of pointer
	const string menuTitle = "\t\tWELCOME THE FORTUNE TELLER 5000\n";
	const char* charMenuOptions[] = { " Enter your name ", " Enter your birth circa ",
							 " Enter your favorite color ", " Exit program " };
	int optionSize = sizeof(*charMenuOptions);
	const int* numOptions = &optionSize;


	newMenu.makeMenu(menuTitle, charMenuOptions, numOptions);



	cin >> intUserInput;

	return 0;
}