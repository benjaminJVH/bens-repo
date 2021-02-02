#include <iostream>
#include <array>
#include <string>
#include "WordArray.h"

using namespace std;

void mainMenu();
bool mainMenuInputCheck(int, bool&);
bool userInputCheck(string&, bool&);
int wordCounterTracker(bool&, int&);
void displayArray();

WordArray obj_WordArray;
int const MAX_CHAR_LIMIT = 21;


int main() {
	cout << "\n\n\t\t\t\tASSIGNMENT 2\n\tBrought to you by Group 2: Dustin 'D-dawg' B. & Ben'jamin' V.\n";
	mainMenu();
	return 0;
}

void mainMenu() {
	int choice, wordCount;
	string input, pluarl;
	bool mainMenuInput, userInput;

	choice = -1;
	input = "";
	wordCount = 12;
	mainMenuInput = false;
	userInput = false;

	cout << "\n\t\t\tWelcome to the Word Array Program";
	cout << "\n\tPlease choose option by entering the coordinating number\n";

	do {
		cout << "\n1 - Add to the Word Array\n2 - View the Word Array\n3 - Remove an entry from Word Array\n0 - Exit program\n";
		cout << "\nEnter number: ";

		cin >> choice;
		mainMenuInputCheck(choice, mainMenuInput);
		if (!mainMenuInput) {
			cout << "\n\tInvalid input\nPlease choose only available numbers\n";
			string ignoreError;
			getline(cin, ignoreError);
		}
	} while (!mainMenuInput);

	do {
		switch (choice) {

		case 1:
			while (wordCount > 1) {
				wordCounterTracker(userInput, wordCount);
				if (wordCount == 1) {
					pluarl = "word";
				}
				else {
					pluarl = "words";
				}

				cout << "\nAdd 12 words to the Word Array (21 char limit) " << "\t\t" << wordCount << " " << pluarl << " remaining\nWord: ";
				cin >> input;
				userInputCheck(input, userInput);
				if (userInput) {
					obj_WordArray.toWordArray(input, wordCount);
				}
			}
			break;

		case 2:
			cout << "\nViewing Word Array Contents\n";
			system("pause");
			break;

		case 3:
			cout << "\nDeleting user choice word from array";

			break;

		case 0:
			cout << "\nExiting program . . . goodbye!\n";
			userInput = true;
			break;

		default:
			userInput = true;
			break;
		}
	} while (!userInput);
}

bool mainMenuInputCheck(int choice, bool& mainMenuInput) {
	int check = choice;
	if (cin.fail()) {
		cin.clear();
		mainMenuInput = false;
		return mainMenuInput;
	}
	else if (check != 0 && check != 1 && check != 2 && check != 3) {
		mainMenuInput = false;
		return mainMenuInput;
	}
	else {
		mainMenuInput = true;
		return mainMenuInput;
	}
}

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

void displayArray() {

}

int wordCounterTracker(bool& userInput, int& wordCount) {
	if (userInput) wordCount--; return wordCount;
}



/*

Assignment Details

•	Use at least on class
•	Read a list of 12 words into an array
•	Prompt the user for which word in the array to display
•	Use a command line argument to present the user with information about your program.
•	Exit the program on user request




*/