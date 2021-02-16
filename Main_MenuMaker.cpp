#include <iostream>
#include <string>
#include "MenuMaker.h"
#include "InputCheck.h"
using namespace std;

MenuMaker newMenu;
InputCheck newIntInputCheck;

void makeMenu(const string, const char*, const int*);

int main() {

	const bool ignoreOptionZero = true;  // use this as a switch to use 0 or 1 as the starting option
	const int MAX_CHAR_LIMIT = 0;	     // use this to limit the amount of characters a user can input; 0 indicates maximum limit;

	bool intLoop = false;
	int intUserInput = -1;
	
	// edit these strings to create a custom menu.  The charMenuOptions array will automatically count the entries and assign each entry a number
	// the number correspond with the the description of the entry
	const string menuTitle = "WELCOME TO THE FORTUNE TELLER 5000";
	const char* charMenuOptions[] = { " To enter your name ", " To enter your date of birth ", " To enter your favorite number ",
										" Tell me my fortune ", " Exit program " };
	const string errorMessage_1 = "Invalid Entry. Please choose available options.";

	int optionSize = (sizeof(charMenuOptions) / sizeof(const char*));
	const int* numOptions = &optionSize;

	do {
		newMenu.makeMenu(ignoreOptionZero, menuTitle, charMenuOptions, numOptions);
		cin >> intUserInput;
		newIntInputCheck.intInputCheck(intLoop, ignoreOptionZero, intUserInput, numOptions, errorMessage_1);
	} while (!intLoop);

	cout << "Test completed.";
	return 0;
}

/*

Since I was out as the result of technical issues last night there will be no assignment due next week.
All of the sample code has been released to the github site and we will be reviewing it next week for class.  I will be offering this week an extra credit assignment for 25 points. This is an individual assignment; however, you are welcome to collaborate with your classmates in any way you see fit.

The Program - Fortune Teller
Create a program the takes 3 points of input from a user..

1) The users name
2) The users birth date
3) The users favorite number

Use that information to present the user with

1) Their astrological sign
2) A random fortune (rand() function)
3) Returns the users first initial in responses for example "J, as a Taurus you will experience many adventures this year (as long as the theatres are open)."
Entering the word "ZOINKS" will exit the program;

An administrator must be able to add fortunes to the program without having to recompile, and while the program is running.




*/