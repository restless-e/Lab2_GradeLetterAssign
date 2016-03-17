// Lab2_GradeLetterAssignment.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <string>
//#include <cmath>

using namespace std;
int main()
{
	string gradeInput;
	char letter = 'f';
	char modifier = ' '; // = '=';
	float gradeValue = 0.0;
	string rerun;

	cout << "Input your grade received" << endl;
	cin >> gradeInput;

	letter = gradeInput[0];

	if (gradeInput[1] != ' ')
		modifier = gradeInput[1];

	// confirmed flat values for letters. ie. A = 4, B = 3, etc.
	// then perform modification of values based on '-' or '+'
	switch (letter) {
	case 'A':
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
	case 'F':
	case 'f':
		gradeValue = 0.0;
		break;
	default:
		gradeValue = 0.0;
		break;
	}

	// perform modification of values based on '-' or '+'
	if (gradeInput[1] != ' ' && letter != 'f', 'F', 'A', 'a' )//|| letter != 'a', 'A')
	{
		if (modifier == '+')
			gradeValue = gradeValue + 0.3;
		if (modifier == '-')
			gradeValue = gradeValue - 0.3;
	}

	cout << "Your grade value is: " << gradeValue << endl;

	cout << "Run grade calculation again?: Y/N" << endl;
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

