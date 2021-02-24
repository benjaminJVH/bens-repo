#include "MenuMaker.h"
#include "ProgramControls.h"
#include <string>
#include <iostream>

using namespace std;

ProgramControls newProgram;

int start_count = -1;
int counter;
void MenuMaker::menuStart(int menuNum, int crtlNum, bool backMenu) {
	
	string menu = newProgram.menuDescr(menuNum, backMenu);
	int controlNum = newProgram.omitNumber(crtlNum);
	string replacementNum = "";
	if (controlNum != 0) {
		replacementNum = newProgram.replaceOmitNum(1);
	}

	makeMenu(menu, controlNum, replacementNum, backMenu);
}

void MenuMaker::makeMenu(string menu, int omitNumber, string replacementNum, bool backMenu) {
	counter = start_count;
	string menuRead = menu;
	string delim = ",";
	string item = "Nothing";
	int start, end, s_Int, e_Int, omit, goBack;
	int menuLen = menuRead.length();
	start = 0;
	end = start;
	omit = omitNumber;
	size_t menuItemCounter = start;
	
	for (int i = 0; i < 1 + menuLen; i++) {
		menuItemCounter = menuRead.find(",", start);
		s_Int = menuItemCounter;
		e_Int = s_Int;		

		if (menuItemCounter > menuLen) {
			backMenu = true;			
			break;
		}
		else {
			counter++;
			end = e_Int - start;
			item = menuRead.substr(start, end);
			menuFormatter(counter, item, omit, replacementNum);
		}
		start = s_Int += 1;
	}
	optionsNum();
}

int MenuMaker::optionsNum() {
	int numOptions = counter;
	return  numOptions;
}

void MenuMaker::menuFormatter(int counter, string item, int omit, string replacementStr) {
	if (!counter <= 0) {
		if (counter == omit) {
			cout << " " << replacementStr << " " << item << endl;
		}
		else {
			cout << " " << counter << ": " << item << endl;
		}
	}

	else {
		cout << "\n\t\t\t" << item << "\n" << endl;
	}
}
