#include <iostream>
#include <string>
#include "MenuMaker.h"
#include "InputCheck.h"
#include "assert.h"
using namespace std;

MenuMaker newMenu;
InputCheck newIntInputCheck;

bool switchMenu;
string sendErrorMessage;
//void makeMenu(const string, const char*, const int*);
void menuPrep();
void mainMenu();
int testString(string, int&);

int main() {

	menuPrep();
	mainMenu();

	return 0;
}

void mainMenu() {

	const bool ignoreOptionZero = false;  // use this as a switch to use 0 or 1 as the starting option
	const int MAX_CHAR_LIMIT = 0;	     // use this to limit the amount of characters a user can input; 0 indicates maximum limit;	
	// edit these strings to create a custom menu.  The charMenuOptions array will automatically count the entries and assign each entry a number
	// the number correspond with the the description of the entry	
	bool intLoop = false;
	int intUserInput = -1;
	


	do {
		//newMenu.makeMenu(ignoreOptionZero, menuTitle, charMenuOptions, numOptions);
		cin >> intUserInput;
		//newIntInputCheck.intInputCheck(intLoop, ignoreOptionZero, intUserInput, numOptions, sendErrorMessage);
	} while (!intLoop);

	cout << "Test completed";
	switchMenu = true;
}

void menuPrep() {
	int tested = 0;
	int& tester = tested;
	string strMenu = "";
	switchMenu = false;
	string menuTitle;
	// *** ERROR MESSAGES ***
	const string intErrorMessage_1 = "Invalid Entry. Please choose available options.";
	const string strErrorMessage_1 = "One word at a time! Please re-enter word.";
	//*****Menu Description Items *****
	string mainMenuTitle = "MAIN MENU\n\n\tWELCOME TO THE FORTUNE TELLER 5000";
	const char* charMainMenu[] = { " Create User Profile ", " About Program ", " Admin Menu ",
										" Exit Program " };

	sendErrorMessage = intErrorMessage_1;
	menuTitle = mainMenuTitle;
	int optionSize = (sizeof(charMainMenu) / sizeof(const char*));	
	//const int* numOptions = &optionSize;
	const char* charMenuOptions[1];// = { *charMainMenu };	
	for (int i = 0; i < optionSize; i++) {
		//charMenuOptions[0] = charMainMenu[i];
		strMenu = charMainMenu[i];
		testString(strMenu, tested);
			
		//cout << "charMenuOptions = : " << i << " " << strMenu << endl;// charMenuOptions[0] << endl;		
	}

	cout << "\n<: ";

}


int testString(string strMenu, int &tested) {
	cout << "charMenuOptions = : " << tested << " " << strMenu << endl;
	cout << "tester: " << tested << endl;
	tested++;
	return tested;
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