/*
STUDENT NAME:Justin Anderson                            CS-22 Data Structures and Algorithms
SEMESTER: Spring 2024                                      PROFESSOR THURSTON
SECTION:31675
ASSIGNMENT # Project 1 
-------------------------------------------------------------------------------------------
Instructions
-------------------------------------------------------------------------------------------
[COPY FROM CANVAS]
Write a C++ program that reads students’ names and test scores from a text file.
The program should output each student’s name followed by their test score and the grade. 
You will create the data for each student, using fictitious names, scores, and grades.

Student data should be stored in a struct variable of type studentType, which has four components:
studentFirstName and studentLastName of type string, 
testScore of type int (testScore is between 0 and 100), 
and grade of type char. 
Assume that the class has 20 students.
Use an array of 20 structs of type studentType. (1 pt.)

Example function prototypes:

//Function Prototypes
void readStudents(studentType testScores[20]);  Used template given by Instructor
void getGrades(studentType testScores[20]);     works
void showData(studentType testScores[20]);      works 
void showBest(studentType testScores[20]);
*/







#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct studentType {
    string firstName;
    string lastName;
    int testScore;
    char grade;
};

studentType testScores[20];      // testScores is an array of structs
void readStudents(studentType testScores[20]);
void showData(studentType testScores[20]);
void showBest(studentType testScores[20]);
char getGrade(int score);

int main()
{
    readStudents(testScores);
    showData(testScores);
    showBest(testScores);

}
        //function declars each variable needed and reads txt file
void readStudents(studentType testScores[20]) 
{
    string firstName;
    string lastName;
    int testScore;
    char grade;
    ifstream myFile("studentData.txt");         
    int i = 0;

    while (myFile >> firstName >> lastName >> testScore)
    {   
        testScores[i].firstName = firstName;
        testScores[i].lastName = lastName;
        testScores[i].testScore = testScore;
        testScores[i].grade = getGrade(testScore);//returns int value of the testscore and converts into a character
        i += 1;
    }
}
//prints first 15 character first and  last name of students
void showData(studentType testScores[20]) 
{
    cout << "Names of students:\n";
    for (int i = 0; i < 20; i++) 
    {
        cout << "Student Name: " << left << setw(15) << testScores[i].firstName << left << setw(15) << testScores[i].lastName   
            << "Test Score: " << right << setw(3) << testScores[i].testScore
            << "% Grade: " << testScores[i].grade << endl;
    }
    
}

// assigns each student a grade
char getGrade(int score)
{
    if (score >= 90)
        return 'A';
    else if (score >= 80)
        return 'B';
    else if (score >= 70)
        return 'C';
    else if (score >= 60)
        return 'D';
    else
        return 'F';
}

void showBest(studentType testScores[20])
{
    int highestIndex = 0;
/*dosnt work yet need to get it to check entire list probably loop
previous error instead of testscore[i].grade >testscore[highestindex].testscore it would test the asci value of the numbers rather than char
 */
    for (int i = 0; i < 20; i++)
    {   
        if (testScores[i].testScore > testScores[highestIndex].testScore)
        {
            highestIndex = i;
        }
    } 
    cout << "The Student with the highest grade is: " << testScores[highestIndex].firstName << " " <<testScores[highestIndex].lastName << " " << testScores[highestIndex].grade << endl;
    
}