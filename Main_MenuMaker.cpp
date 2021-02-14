#include <iostream>
#include <string>

#include "MenuMaker.h"
using namespace std;

MenuMaker newMenu;

void makeMenu(const string, const char*, const int*);

int main() {
	int intUserInput = -1;
	// Initialize array of pointer
	const string menuTitle = "WELCOME THE FORTUNE TELLER 5000";
	const char* charMenuOptions[] = { " Exit program ", " Enter your name ",
							 " Enter your date of birth ", " Enter your favorite color ", " Tell me my fortune " };
	int optionSize = sizeof(*charMenuOptions);
	const int* numOptions = &optionSize;
	cout << "\nthis is the optionSize: " << *numOptions << endl;

	newMenu.makeMenu(menuTitle, charMenuOptions, numOptions);



	cin >> intUserInput;

	return 0;
}