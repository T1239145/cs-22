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

struct studentType 
{
    string firstName;
    string lastName;
    int testScore{ 0 };
    char grade{ 0 };
};
//Function Prototypes
studentType testScores[20];      // testScores is an array of structs
void readStudents(studentType testScores[20]);
void showData(studentType testScores[20]);
void showBest(studentType testScores[20]);
char getGrade(int score);//not void getGrade because returning a char

int main()
{
    readStudents(testScores);
    showData(testScores);
    showBest(testScores);
    

}
/************************************************************
*                      ReadStudents                        *
* Reads the students data from the file                    *
*                                                          *
*                                                          *
************************************************************/
void readStudents(studentType testScores[20]) 
{
    string firstName;
    string lastName;
    int testScore;
    ifstream myFile("studentData.txt");         
    int i = 0;

    while (myFile >> firstName >> lastName >> testScore)
    {   
        testScores[i].firstName = firstName;
        testScores[i].lastName = lastName;
        testScores[i].testScore = testScore;
        testScores[i].grade = getGrade(testScore);
        i += 1;
    }
}
/************************************************************
 *                        showData                          *
 *prints each students name in order of first last then     *
 * test score and grade                                     *
 * this assumes first/last name is less than 15 char        *
 * and 20 students                                          *
 ************************************************************/
void showData(studentType testScores[20]) 
{
    
    cout << "Names of students:\n";
    for (int i = 0; i < 20; i++) 
    {
        cout << left << setw(15) << testScores[i].lastName << left << setw(15) << testScores[i].firstName   
            << "Test Score: " << right << setw(3) << testScores[i].testScore
            << "% Grade: " << testScores[i].grade << endl;
    }
    
}

/************************************************************
 *                      getGrade                           *
 * Assigns each number grade read from the file             *
 * a character value                                        *
 *                                                          *
 ************************************************************/
char getGrade(int score)//named char instead of void because returning a specific data type char 
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
/************************************************************
 *                      showBest                            *
 * does a for loop calculating which student has the highest*
 * grade by ascii value                                     *
 *                             *
 ************************************************************/
void showBest(studentType testScores[20])
{
    int highestScore = testScores[0].testScore;
    //finds highest score
    for (int i = 1; i < 20; i++)
    {   
        if (testScores[i].testScore > highestScore)
        {
            highestScore = testScores[i].testScore;
        }
    } 
    
    cout << "========================================================" << endl;
    cout << "The highest score is: " << highestScore << "/100" << endl; \
        cout << "The Student(s) who earned this score :\n";
   //prints students names/incase of more than 1 student with top score
    for (int i = 0; i < 20; i++)
    {
        if (testScores[i].testScore == highestScore)
        {
            cout  << testScores[i].lastName << "," << testScores[i].firstName << endl;
        }
    }
}
