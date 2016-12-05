#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class TermGrade
{
public:

	TermGrade();

	bool ReadData(istream& in);
	//PRE: Input file must be open
	//POST: TermGrade object stored to array
	//RETURNS: true if data is read, otherwise false

	double MidsemesterScore() const;
	//PRE: Assignment, exam1, exam2 initialized
	//POST: None
	//RETURNS: double weighted grade
	double FinalScore() const;
	//PRE: Assignment, exam1, exam2, final initialized
	//POST: None
	//RETURNS: double final weighted grade
	char LetterGrade() const;
	//PRE: Assignment, exam1, exam2, final initialized
	//POST: None
	//RETURNS: Char letter grade

	// getters
	int getID(); 
	// returns student ID
	int getAssn(); 
	// returns assignment score
	int getEx1(); 
	// returns exam1 score
	int getEx2(); 
	// returns exam2 score
	int getFinal(); 
	// returns final score

private:

	int studentID;
	int assignment;
	int exam1;
	int exam2;
	int final;
};