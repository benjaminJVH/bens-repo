#include "ProgramControls.h"
#include "MenuMaker.h"
#include "InputCheck.h"
#include <string>

using namespace std;

MenuMaker newMenu;

void ProgramControls::startPCProgram(int menuNum, int optionOmit, bool &backMenu) {
	newMenu.menuStart(menuNum, optionOmit, &backMenu);
}


string ProgramControls::menuDescr(int menuNum, bool &backMenu) {
	string menu;
	string mainMenu = "WELCOME TO THE FORTUNE TELLER 5000,Profile Menu," // 0 - Zero is always Menu header
		"Admin Menu,About Program,Exit Program,";
	string ProfileMenu = "PROFILE MENU,Enter your name,Enter date of birth,Enter your favorite number,go back,"; // 1
	string AdminMenu = "ADMIN MENU,Add Fortune,Remove Fortune,View Fortune(s),go back,"; // 2
	string AboutProgramMenu = "ABOUT PROGRAM,This Program is your program,this program is my program,this program was made for you and me,go back,"; //3

	if (menuNum == 0) {
		menu = mainMenu;
	}
	else if (menuNum == 1) {
		menu = ProfileMenu;
		backMenu = false;
	}
	else if (menuNum == 2) {
		menu = AdminMenu;
		backMenu = false;
	}
	else if (menuNum == 3) {
		menu = AboutProgramMenu;
		backMenu = false;
	}
	else {
		if (backMenu) {
			menu = mainMenu;
		}
		else {
			cout << "\n\t\t\tNo descriptive menu entered.\n\n\t\t\tProgram will now close.\n";
			exit(0);
		}

	}

	return menu;
}

string ProgramControls::errorMessages(int errNum) {
	string errMessage;
	string intErrorMessage_1 = "Invalid Entry. Please choose available options.,";
	string strErrorMessage_1 = "One word at a time! Please re-enter word.,";

	if (errNum == 1) {

		errMessage = intErrorMessage_1;
	}
	else if (errNum == 2) {
		errMessage = strErrorMessage_1;
	}
	else {
		errMessage = "No descriptive message entered.,";

	}

	return errMessage;
}

string ProgramControls::iconSelector(int iconSelect) {
	string iconSelected;
	if (iconSelect == 1) {
		iconSelected = "\n [ ";
	}
	else if (iconSelect == 2) {
		iconSelected = "\n -> ";
	}
	else if (iconSelect == 3) {
		iconSelected = "\n \\ ";
	}
	else {
		iconSelected = "\n <: ";
	}
	return iconSelected;
}

int ProgramControls::omitNumber(int intOmit) {
	int controlNum;

	controlNum = intOmit;// enter a number within the menu option range to omit

	return controlNum;
}

//int ProgramControls::startingIntOption(int optionStart) {
//	int startingOption = 1;
//	return startingOption;
//}

string ProgramControls::replaceOmitNum(int replace) {
	string numReplacement;

	if (replace == 1) {
		numReplacement = "ZOINKS:";
		return numReplacement;
	}
	else {
		numReplacement = "  ";
		return numReplacement;
	}
}

int ProgramControls::MaxChar(int MAX_CHAR_LIMIT) {
	int controlNum = MAX_CHAR_LIMIT;

	return controlNum;
}

bool ProgramControls::loops(int loopNum) {
	bool pcLoop;
	bool intLoop = false;
	bool switchMenuLoop = false;

	if (loopNum == 1) {
		pcLoop = intLoop;
	}
	else if (loopNum == 2) {
		pcLoop = switchMenuLoop;
	}
	else {
		pcLoop = false;
	}

	return pcLoop;
}
