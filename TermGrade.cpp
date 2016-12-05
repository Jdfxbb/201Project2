#include "TermGrade.h"

TermGrade::TermGrade()
{
	// initialize member variables
	studentID = 0;
	assignment = 0;
	exam1 = 0;
	exam2 = 0;
	final = 0;
}

bool TermGrade::ReadData(istream& in)
{
	// check if end of file, if not then get data
	if (in.eof())
		return false;
	else 
	{
		// input is good, return true
		in >> studentID >> assignment >> exam1 >> exam2 >> final;
		return true;
	}
}

double TermGrade::MidsemesterScore() const
{
	// multiply scores by weights and divide by total weight %
	return ((assignment * 0.20) + (exam1 * 0.25) + (exam2 * 0.25)) / 0.7;
}

double TermGrade::FinalScore() const
{
	//multiply each assignment by weight and add
	return (assignment * 0.2) + (exam1 * 0.25) + (exam2 * 0.25) + (final * 0.3);
}

char TermGrade::LetterGrade() const
{
	double grade = FinalScore();
	// letter grade conditions
	if (grade >= 90)
		return 'A';
	else if (grade >= 80)
		return 'B';
	else if (grade >= 70)
		return 'C';
	else return 'D';
}

int TermGrade::getID()
{
	return studentID;
}

int TermGrade::getAssn()
{
	return assignment;
}

int TermGrade::getEx1()
{
	return exam1;
}

int TermGrade::getEx2()
{
	return exam2;
}

int TermGrade::getFinal()
{
	return final;
}