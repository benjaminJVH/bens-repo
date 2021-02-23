#include "ProgramControls.h"
#include "MenuMaker.h"
#include "InputCheck.h"
#include <string>

using namespace std;

MenuMaker newMenu;

void ProgramControls::startPCProgram() {
	newMenu.menuStart(0, 0); // enter the menu by number and option to omit and / or not replace
}


string ProgramControls::menuDescr(int menuNum) {
	string menu;
	string mainMenu = "WELCOME TO THE FORTUNE TELLER 5000,Profile Menu," // 0
		"Admin Menu,About Program,Exit Program,";
	string ProfileMenu = "PROFILE MENU,Enter your name,Enter date of birth,Enter your favorite number,"; // 1
	string AdminMenu = "ADMIN MENU,Add Fortune,Remove Fortune,View Fortune(s),"; // 2
	string AboutProgramMenu = "ABOUT PROGRAM,This Program is your program, this program is my program, this program was made for you and me,"; //3

	if (menuNum == 0) {
		menu = mainMenu;
	}
	else if (menuNum == 1) {
		menu = ProfileMenu;
	}
	else if (menuNum == 2) {
		menu = AdminMenu;
	}
	else if (menuNum == 3) {
		menu = AboutProgramMenu;
	}
	else {
		menu = "No descriptive menu entered.";
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
		errMessage = "No descriptive message entered";
	}

	return errMessage;
}


int ProgramControls::omitNumber(int intOmit) {
	int controlNum;

	controlNum = intOmit;// enter a number within the menu option range to omit

	return controlNum;
}

string ProgramControls::replaceOmitNum() {
	string numReplacement = "ZOINKS";
	return numReplacement;
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
