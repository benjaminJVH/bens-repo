#include "ProgramControls.h"
#include "InputCheck.h"
#include "MenuMaker.h"
#include <iostream>
#include <string>
using namespace std;

ProgramControls PCProgram;
InputCheck newInt_InputCheck;
MenuMaker executeMenu;

void executeProgram(string);

int main(int argc, char* argv[]) {
	string icon = "\n <:";
	executeProgram(icon);
	return 0;
}

void executeProgram(string icon) {
	int intUserInput = -1;
	bool intLoop = PCProgram.loops(1);
	string sendErrorMessage = PCProgram.errorMessages(1);
	do {
		PCProgram.startPCProgram();
		int numOptions = executeMenu.optionsNum();
		cout << icon;
		cin >> intUserInput;
		newInt_InputCheck.intInputCheck(intLoop, intUserInput, numOptions, sendErrorMessage);
	} while (!intLoop);

}
///*
//
//Since I was out as the result of technical issues last night there will be no assignment due next week.
//All of the sample code has been released to the github site and we will be reviewing it next week for class.  I will be offering this week an extra credit assignment for 25 points. This is an individual assignment; however, you are welcome to collaborate with your classmates in any way you see fit.
//
//The Program - Fortune Teller
//Create a program the takes 3 points of input from a user..
//
//1) The users name
//2) The users birth date
//3) The users favorite number
//
//Use that information to present the user with
//
//1) Their astrological sign
//2) A random fortune (rand() function)
//3) Returns the users first initial in responses for example "J, as a Taurus you will experience many adventures this year (as long as the theatres are open)."
//Entering the word "ZOINKS" will exit the program;
//
//An administrator must be able to add fortunes to the program without having to recompile, and while the program is running.
//
//
//
//
//*/