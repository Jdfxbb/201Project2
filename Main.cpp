/*********************************************

Name: Joshua Ford
Course: CS 201R
Program: Program 2
Due Date: 14 February 2016
Description: Write a program to output student data in a legible, concise table.
Inputs:	input file("grade1.txt"), user selections
Outputs: output file("finalgrade.txt"), console prompts
Algorithm:	
1. Open input and output file
2. Iterate input file and add all students to array of size 100
3. Repeat until quit:
	a. Print menu to console
	b. Write selected data to file
	c. Close files

*********************************************/

#include <iostream>
#include "TermGrade.h"
#include <fstream>
#include <iomanip>
using namespace std;

// prototypes
void tableOut(int option, TermGrade list[], int counter);
//PRE: User selection
//POST: Output file written
//RETURNS: None
int getChoice();
//PRE: None
//POST: User selection made
//RETURNS: int user selection 1-3
void ABcount(int& A, int& B, TermGrade list[], int counter);
//PRE: Student array created
//POST: A and B values updated
//RETURNS: None

void main()
{
	cout << "Term Grade Evaluator" << "\n" << endl;

	// open input and output files
	ifstream fin("grade1.txt");
	
	TermGrade studentList[100];
	TermGrade student;

	// for incrementing studentList[]
	int k = 0;

	// read data into array
	while (student.ReadData(fin))
	{
		studentList[k] = student;
		k++;
	}

	// main program loop
	while (true)
	{
		int choice = getChoice();

		// execute user selection
		switch (choice)
		{
		case 1: tableOut(1, studentList, k);
			break;
		case 2: tableOut(2, studentList, k);
			break;
		case 3: tableOut(3, studentList, k);
			break;
		case 4: cout << "Goodbye\n\n";
			break;

		// in case a non 1-4 int gets by getChoice()
		default: "Something went wrong, please try again";
			break;
		}

		// quit condition
		if (choice == 4)
			break;
		else cout << "File written successfully\n\n";
	}

	// close files
	fin.close();
}

int getChoice()
{
	int choice;

	// initiallize menu
	cout << "Select an option below: " << "\n" << endl;
	cout << "1. Grades after Exam 2 \n \n";
	cout << "2. Grades after Final Exam \n \n";
	cout << "3. All of the above \n \n";
	cout << "4. Quit \n \n" << "---> ";

	// get user selection
	cin >> choice;
	cout << "\n";

	// check for type and range
	while (cin.fail() || (choice < 1 || choice > 4))
	{
		cin.clear();
		cin.ignore();
		cout << "Please select an option above. \n \n --->";
		cin >> choice;
		cout << "\n";
	}

	return choice;

}

void tableOut(int option, TermGrade list[], int counter)
{
	ofstream fout("finalgrade.txt");
	// initialize A and B count
	int A = 0;
	int B = 0;
	// initialize option3 condition
	bool allData = false;

	// if true, for loop passes through option 1 and option 2
	if (option == 3)
	{
		allData = true;
	}

	// decimal precision for percentages
	fout << setprecision(2) << fixed;

	for (int n = 0; n < (counter - 1); n++)
	{
		// student id column
		fout << setw(6) << left << list[n].getID()

			// score columns
			<< setw(4) << right << list[n].getAssn()
			<< setw(4) << right << list[n].getEx1() << setw(4)
			<< list[n].getEx2();

		if (option == 1 || allData == true)
		{
			// mid semester score column
			fout << setw(16) << right << "After exam 2 " << setw(6)
				<< list[n].MidsemesterScore() << setw(2) << "%";
			if (allData == false)
			{
				fout << endl;
			}
		}

		if (option == 2 || allData == true)
		{
				// score columns
			fout << setw(5) << right << list[n].getFinal()

					// final score columns
					<< setw(20) << right << "After final exam " << setw(6)
					<< list[n].FinalScore()

					// letter grade columns
					<< setw(2) << "%" << setw(20) << right << "Overall grade is "
					<< setw(1) << list[n].LetterGrade() << endl;
		}
	}
	// count A's and B's
	ABcount(A, B, list, counter);

	// output A's and B's
	fout << "Number of A's: " << A << endl;
	fout << "Number of B's: " << B << endl;

	fout.close();
}

void ABcount(int& A, int& B, TermGrade list[], int counter)
{
	for (int n = 0; n < (counter - 1); n++)
	{
		if (list[n].LetterGrade() == 'A')
			A++;
		else if (list[n].LetterGrade() == 'B')
			B++;
	}
}
