/*
Name: Benjamin VanderHart
Class CIS 227 2021 / Winter
Assignment 0
Date 1/18/2021

ver 1.0.1.0

This program will execute the following functions:

- input will be provided by user

Selection 1: Calculates the hypotenuse.
Selection 2: Calculates the area of a trapezoid.
Selection 3: Calculates the volume of a rectangle;

Selection 0: ends progam and exits to command.
*/

// Need iostream for input
#include <iostream>
// Need math.h to do mathing
#include <math.h>
// Need this for strings
#include <string>
// standard namespace
using namespace std;

// This variable will be used as user input and determines what function will be executed
int option;
// These variables will be used throughout
double a, b, c, height, result;
// This is to store errors that are caught
string ignoreLine;
// Common error message when an exception occurs
string errMessage = "Option unavailable.";
// Booleans used for loops
bool badChoice = false;
bool quitProgram = false;
bool goodInput;

// This funciton will calculate the hypotenuse of a triangle
double calcHypotenuse(double a, double b) {
	double side1, side2, r;
	side1 = a;
	side2 = b;
	r = hypot(side1, side2);
	return r;
}

// This function will calculate the area of a trapezoid
double calcTrapezoid(double a, double b, double h) {
	double base1, base2, height, r;
	base1 = a;
	base2 = b;
	height = h;
	r = (base1 + base2) * height / 2;
	return r;
}

// This function will calculate the volume of a rectangle
double calcRectangleVolume(double a, double b, double c) {
	double side1, side2, side3, r;
	side1 = a;
	side2 = b;
	side3 = c;
	r = (side1 * side2 * side3);
	return r;
}

// prints result of functions
void printResult(int option, double result) {
	if (option == 1) {
		cout << "\nThe hypotenuse is: " << result << endl;
	}
	else if (option == 2) {
		cout << "\nThe area of the trapezoid is: " << result << endl;
	}
	else {
		cout << "\nThe volume of the rectangle is: " << result << endl;
	}
}

// The inputCheck function supports error handing if the user input is invalid  
// Both functions utilizes goodInput, which checks for valid user input when ask to provide a number for calcuation.
//  There are two inputCheck functions:

// This function provides badChoice boolean for menu error handling support, in addition to goodInput for math input
// error handling
bool inputCheck() {
	goodInput = false;
	if (cin.fail()) {
		cin.clear();
		getline(cin, ignoreLine);
		badChoice = true;
		throw option;
		return badChoice;
	}
	else {
		goodInput = true;
		return goodInput;
	}
}

// This funciton is overloaded with int option to differentiate it from first inputCheck function.
// This function utilizes booleans: quitProgram - if the user wants to exit after using the program
// and in addition to goodInput for math input error handling.

bool inputCheck(int option) {
	goodInput = false;
	if (cin.fail()) {
		cin.clear();
		getline(cin, ignoreLine);
		quitProgram = false;
		try {
			throw option;
		}
		catch (int e) {
			cout << errMessage << endl;
			return quitProgram;
		}
	}
	else {
		goodInput = true;
		return goodInput;
	}
}

// This is where the program begins
int main() {
	goodInput = false;

	cout << "\tWELCOME TO GEOMETRY CALCULATIONS MADE EASE - E\n";

	// This is the menu and will be executed at least once utilizing the do while loop. 
	while (!quitProgram) {
		do {

			try {
				cout << "\n\t\tPlease choose option by number \n\t1 - Calculate hypotenuse of a triangle\n\t2 - Calculate area of a trapezoid\n"
					"\t3 - Calculate volume of a rectangle\n\t0 - Exit program" << endl;
				cin >> option;

				// This portion calls funciton below and checks to see if input is valid				
				inputCheck();

				// This portion checks to see if input provided meets the options that are available.
				if (option < 0 || option > 3) {
					badChoice = true;
					throw option;
				}
				else {
					badChoice = false;
				}

			}
			catch (int e) {
				cout << errMessage << endl;
			}
			catch (...) {
				cout << errMessage << endl;
			};

			// This comparison expression determines if the option the user input is valid. Otherwise, will be asked to chose again.
		} while (badChoice);

		// This switch is used for menu choice		
		switch (option) {

			// This option will quit and exit program
		case 0:
			quitProgram = true;
			break;

			// Option for Hypotenuse
		case 1:
			goodInput = false;
			cout << "Hypotenuse Calculator" << endl;
			while (!goodInput) {
				cout << "Please first value: " << endl;
				cin >> a;
				inputCheck(option);
			}
			goodInput = false;
			while (!goodInput) {
				cout << "Please enter second value: " << endl;
				cin >> b;
				inputCheck(option);
			}
			result = calcHypotenuse(a, b);
			// calls print option to display result
			printResult(option, result);
			break;

			// Option for trapezoid
		case 2:
			goodInput = false;
			cout << "Area of trapezoid calculator" << endl;
			while (!goodInput) {
				cout << "Please enter base 1 value: " << endl;
				cin >> a;
				inputCheck(option);
			}
			goodInput = false;
			while (!goodInput) {
				cout << "Please enter base 2 value: " << endl;
				cin >> b;
				inputCheck(option);
			}
			goodInput = false;
			while (!goodInput) {
				cout << "Please enter height value: " << endl;
				cin >> height;
				inputCheck(option);
			}
			result = calcTrapezoid(a, b, height);
			// calls print option to display result
			printResult(option, result);
			break;

			// Option for rectangle
		case 3:
			goodInput = false;
			cout << "Volume of recatngle calculator" << endl;
			while (!goodInput) {
				cout << "Please enter side 1 value: " << endl;
				cin >> a;
				inputCheck(option);
			}
			goodInput = false;
			while (!goodInput) {
				cout << "Please enter side 2 value: " << endl;
				cin >> b;
				inputCheck(option);
			}
			goodInput = false;
			while (!goodInput) {
				cout << "Please enter side 3 value: " << endl;
				cin >> c;
				inputCheck(option);
			}
			result = calcRectangleVolume(a, b, c);
			// calls print option to display result
			printResult(option, result);
			break;

			// This default option catches all other selections made by user and provides error messange
		default:
			goodInput = false;
			cout << errMessage << endl;
			break;
		}

		// This funtion will pause the program before it quits and exits.
		if (quitProgram) {
			cout << "Goodbye" << endl;
			system("pause");
			return 0;
		}
	}
}