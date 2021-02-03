//
//Assignment 2 - Benjamin V & Dustin B
//	Date: 02/01/2021
//	


// imported libs
#include <iostream>
#include <array>
#include <string>
#include "WordArray.h"

using namespace std;


// declared functions - some overloaded
void mainMenu();
bool intMenuInputCheck(int, bool&);
bool intMenuInputCheck(int, bool&, bool&);
bool userInputCheck(string&, bool&);
int wordCounterTracker(bool&, int&);

// global objs and vars
WordArray obj_WordArray;
int const MAX_CHAR_LIMIT = 21;


// main function w/ 1 argument to display on main menu page - one call to mainmenu for a clean main look.
int main(int argc, char* argv[]) {

	if (argc == 1) {
		cout << "This program is a product of group 2.  Date: 02/01/2021" << endl;
	}
	cout << "\n\n\t\t\t\tASSIGNMENT 2\n\tBrought to you by Group 2: Dustin 'D-dawg' B. & Ben'jamin' V.\n";
	mainMenu();
}


// main - where local vars are declared
void mainMenu() {
	int choice, wordCount, displayChoice;
	string input, plural;
	string arrWords[12];
	bool mainMenuInput, userInput, menuLoop, arrayEmpty;

	choice = -1;
	displayChoice = -1;
	input = "";
	wordCount = 0;
	mainMenuInput = false;
	userInput = false;
	arrayEmpty = true;
	menuLoop = true;

	cout << "\n\t\t\tWelcome to the Word Array Program";
	while (menuLoop) {
		cout << "\n\tPlease choose option by entering the coordinating number\n";
		do {
			cout << "\n1 - Add to the Word Array\n2 - View the Word Array\n3 - Remove an entry from Word Array\n0 - Exit program\n";
			cout << "\nEnter number: ";
			cin >> choice;
			intMenuInputCheck(choice, mainMenuInput);  // calls error handler
		} while (!mainMenuInput);

		do {
			switch (choice) {

			case 1:
				if (!arrayEmpty) {
					cout << "\nCannot add additional words to array, contents already full\n" << endl;
				}
				else {
					while (wordCount < 11) {
						wordCounterTracker(userInput, wordCount); // counts wordcount
						if (wordCount == 11) {
							plural = "word";
						}
						else {
							plural = "words";
						}
						cout << "\nAdd 12 words to the Word Array (" << MAX_CHAR_LIMIT << " char limit) " << "\t\t" << (12 - wordCount) <<
							" " << plural << " remaining\nWord: ";
						cin >> input;
						userInputCheck(input, userInput); // error handling
						if (userInput) {
							arrWords[wordCount] = input; // puts words into array
						}
					}
					arrayEmpty = false;
				}
				break;

			case 2:
				if (arrayEmpty) {
					cout << "\nArray is empty, use option 1 to fill array\n";
					userInput = true;
					break;
				}
				else {
					cout << "\nViewing Word Array Contents\n";
					do {
						cout << "\nPlease choose from available options\n1 - View all contents of Word Array\n";
						cout << "2 - Display a single word by entering a number 1 thru 12\n3 - Display range of words " <<
							"by entering beginning and ending numbers\n0 - Go back to previous menu\n" << endl;
						cout << "Enter number: ";
						cin >> choice;
						intMenuInputCheck(choice, mainMenuInput); // error handling
					} while (!mainMenuInput);
					if (choice == 1) {
						obj_WordArray.viewArray(arrWords, 12);  // calls object array to view its contents
					}
					else if (choice == 2) {
						bool choiceCheck = true;
						do {
							cout << "\nEnter number to display coordinating word\n";
							cin >> choice;
							intMenuInputCheck(choice, mainMenuInput, choiceCheck);  //error handling
							obj_WordArray.viewArray(choice, arrWords, 12);
						} while (!mainMenuInput);
					}
					else if (choice == 3) {
						cout << "\nOption not available at this time\n";  // for future work
						wordCount = -1;
					}
					else {
						userInput = true;
						break;
					}
				}
				break;

			case 3:
				cout << "\nRemoving entry from array\n";
				cout << "Option not available at this time\n"; // for future work				
				userInput = true;
				menuLoop = true;
				wordCount = -1;
				break;

			case 0:
				cout << "\nExiting program . . . goodbye!\n";
				userInput = true;
				menuLoop = false;
				break;

			default:
				userInput = true;   // this may be used for future work
				menuLoop = false;
				break;
			}
		} while (!userInput);
	}
}

// error handling for first menu interface 1 of 2 similar function - non-overloaded

bool intMenuInputCheck(int choice, bool& intMenuInput) {
	int check = choice;
	if (cin.fail()) {
		cin.clear();
		string ignoreError;
		getline(cin, ignoreError);
	}
	else if (check != 0 && check != 1 && check != 2 && check != 3) {
		intMenuInput = false;		// redundant, keeping this here anyway for looks
	}
	else {
		intMenuInput = true;
		return intMenuInput;
	}
	cout << "\n\tInvalid input\nPlease choose only available numbers\n";
	intMenuInput = false;
	return intMenuInput;
}


// second part of first error handling for mainmenu interface - overloaded function
bool intMenuInputCheck(int choice, bool& intMenuInput, bool& choiceCheck) {
	int check = choice;
	if (cin.fail()) {
		cin.clear();
		string ignoreError;
		getline(cin, ignoreError);
	}
	else if (check < 0 || check > 12) {
		intMenuInput = false;		// redundant, keeping this here anyway for looks
	}
	else {
		intMenuInput = true;
		return intMenuInput;
	}
	cout << "\n\tInvalid input\nPlease choose only available numbers\n";
	intMenuInput = false;
	return intMenuInput;
}

// second unique error handling for swtich cases -
bool userInputCheck(string& input, bool& userInput) {
	string wordError;
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

// simple function to keep track of word count and also used for iteration 

int wordCounterTracker(bool& userInput, int& wordCount) {
	if (userInput) wordCount++; return wordCount;
}



/*

Assignment Details

•	Use at least on class
•	Read a list of 12 words into an array
•	Prompt the user for which word in the array to display
•	Use a command line argument to present the user with information about your program.
•	Exit the program on user request




*/