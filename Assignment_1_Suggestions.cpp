// Assignment_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <iomanip> //for precision
#include "Assignment_1.h"

//namespace declarations
using namespace std;

//User Inputs
double dUserSideOne, dUserSideTwo, dUserSideThree;

//Outputs
double answer = 0.0;

//main function
int main() {
	//local variables
	bool bMainLoop = false;
	bool tryAgain = false;
	bool intOnly = true;
	char cContinue;
	char cUserChoice;
	Area_App areaCalculator;

	cout << "\t\t***Units Calculator***\nTo choose a calculation, please enter the coordinating number\n" << endl;

	//begin loop for calculator
	do {
		tryAgain = false;
		//user chooses which formula to use
		cout << "1 - for hypotenuse of a triangle\n2 - for area of a trapezoid\n3 - for volume of a rectangle\n0 - " <<
			"to exit program" << endl;

		cin >> cUserChoice;

		//option 1 -- triangle hypotenuse
		if (cUserChoice == '1') {
			cout << "Enter the length of side one:" << endl;
			cin >> dUserSideOne;
			cout << "Enter the length of side two:" << endl;
			cin >> dUserSideTwo;

			//return hypotenuse
			answer = areaCalculator.Triangle(dUserSideOne, dUserSideTwo);
			cout << "Your hypotenuse is " << setprecision(3) << answer << " units long." << endl;
		}

		//option 2 -- area of trapezoid
		else if (cUserChoice == '2') {
			cout << "Enter length of the first base:" << endl;
			cin >> dUserSideOne;
			cout << "Enter length of the second base:" << endl;
			cin >> dUserSideTwo;
			cout << "Enter the height:" << endl;
			cin >> dUserSideThree;

			//return area
			answer = areaCalculator.Trapezoid(dUserSideOne, dUserSideTwo, dUserSideThree);
			cout << "Your trapezoid's area is " << setprecision(3) << answer << " units squared." << endl;
		}

		//option 3 -- volume of rectangle
		else if (cUserChoice == '3') {
			cout << "Enter the length:" << endl;
			cin >> dUserSideOne;
			cout << "Enter the width: " << endl;
			cin >> dUserSideTwo;
			cout << "Enter the height: " << endl;
			cin >> dUserSideThree;

			//return volume
			answer = areaCalculator.Rectangle(dUserSideOne, dUserSideTwo, dUserSideThree);
			cout << "Your rectangle has a volume of " << setprecision(3) << answer << " cubic units. " << endl;
		}
		else if (cUserChoice == '0') {
			tryAgain = true;
			bMainLoop = false;
		}

		//invalid input
		else {
			cout << "\nInvalid choice, please try again...\n" << endl;
			tryAgain = true;
			bMainLoop = true;

		}
		if (!tryAgain) {
			//prompt user for continue
			cout << "Would you like to try another object?(Y/N)" << endl;
			cin >> cContinue;
			cContinue = toupper(cContinue);

			if (cContinue == 'Y') {
				bMainLoop = true;
			}
			else {
				bMainLoop = false;
			}

		}

	} while (bMainLoop == true);

	//end program
	cout << "\nThank you for using our program!\n" << "Program has ended." << endl;
	return 0;
}