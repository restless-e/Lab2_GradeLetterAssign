// Lab2_GradeLetterAssignment.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
int main()
{
	string gradeInput;
	char letter = 'f';
	char modifier = ' '; // = '=';
	float gradeValue = 0.0;
	string rerun;
	bool f_OrUnknown = false; // bool used to ensure any non-normally graded letter will remain at 0.0 grade value.

	cout << "Input your grade received" << endl;
	cin >> gradeInput;

	//if combined grade (such as B+) is entered, this will pull the first part only
	letter = gradeInput[0];

	// checks for a non-blank modifier (ie "B+") if only finds first letter (ie "B") will skip.
	if (gradeInput[1] != ' ')
		modifier = gradeInput[1];

	// confirmed flat values for letters. ie. A = 4, B = 3, etc.
	// switch sets gradeValue according to input. F and anything unordinary will be 0.
	switch (letter) {
	case 'A': // double cases used to check for letter cases (uppercase/lowercase)
	case 'a':
		gradeValue = 4.0;
		break;
	case 'B':
	case 'b':
		gradeValue = 3.0;
		break;
	case 'C':
	case 'c':
		gradeValue = 2.0;
		break;
	case 'D':
	case 'd':
		gradeValue = 1.0;
		break;
	default: // non-A/B/C/D values will be assumed at '0' points.
		gradeValue = 0.0;
		f_OrUnknown = true;
		break;
	}

	if (gradeInput[1] != ' ' && f_OrUnknown != true) //If letter modifier exist, typically - or +, modify the value of the grade. Except for special cases: a+/f-anything.
	{
		switch (f_OrUnknown)
		{
		case false:
			if (modifier == '+')
				if (letter != 'A' && letter != 'a')
				{
					gradeValue = gradeValue + 0.3;
				}
			if (modifier == '-')
				gradeValue = gradeValue - 0.3;
			break;
		default:
			break;
		}
	}

	cout << "Your grade value is: " << fixed << setprecision(1) << gradeValue << endl; //outputs modified grade value with precision of 1 decemial.

	cout << "Run grade calculation again?: Y/N" << endl; // asks to run again, Y/y will rerun, anything else will exit.
	cin >> rerun;

	if (rerun == "y" || rerun == "Y")
	{
		system("cls");
		main();
	}
	else {
		return 0;
	}
}
