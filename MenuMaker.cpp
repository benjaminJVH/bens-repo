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

	cout << "\n\t\t\t" << menuTitle << "\n" << endl;
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


//void MenuMaker::makeSwitchMenu(int intUserInput, const bool ignoreOptionZero, const string menuTitle, const char* charMenuOptions[],
//	const int* numOptions) {
//	const string menuTitle;
//	const string exitMenu = "Exit Menu";
//	const string userProfile_Title = "USER PROFILE";
//	const char* userProfile[] = { " Enter your name: ", " Enter your berf date: ", " What is your fave color?: " };	
//	const string aboutProgram_Title = "ABOUT PROGRAM";
//	const char* userProfile[] = { " This program is brought to you by Ben'jamin' V. " };
//	const string adminMenu_Title = "ADMIN MENU";
//	const char* adminMenu[] = { " Add a fortune ", " View fortunes ", " Delete fortune " };		
//
//
//	do {
//		if (intUserInput == )
//
//
//	} while ();
//
//}