/*
STUDENT NAME:Justin Anderson                            CS-22 Data Structures and Algorithms
SEMESTER: Spring 2024                                      PROFESSOR THURSTON
SECTION:cs 22 31675
ASSIGNMENT #Programming Assignment 5: Linked List Programming and Analysis
-------------------------------------------------------------------------------------------
Instructions
-------------------------------------------------------------------------------------------
[COPY FROM CANVAS]
1) Read the census data file (CensusData.csv Download CensusData.csv)  (used in a prior assignment) and store each state's data (name and other fields too) as a struct in a singly linked list.
     THIS IS ALREADY DONE FOR YOU AND STORES EACH NEW NODE AT THE HEAD OF THE LIST RATHER THAN THE TAIL. AFTER READING THE
     COMPLETE FILE THE HEAD WILL POINT TO THE LAST RECORD IN THE FILE. (0 pts.)

2) Write the state name, the memory address of the current node containing that state, and the memory address of the "next" node, to a line in a text output file named CensusNodes.txt (separate each of these three values by a comma). The last line you write at this point in the program will be "End of Original Node List".
THE DISPLAY FUNCTION CAN BE USED TO CREATE A FUNCTION TO WRITE THIS DATA. COPY THIS FUNCTION AND CREATE A NEW FUNCTION NAMED "writeList" TO WRITE THE DATA TO THE FILE. (1 pt.)

3) Once you've read the file with the data and created the linked list, prompt the user to enter a single letter of the alphabet and display the states in the linked list beginning with that letter. Restrict the choices to valid letters which you should store in a variable (such as an array of characters or a string) as you read in the data.
COPY THE displayList FUNCTION TO A NEW FUNCTION NAMED displayPartialList (1 pt.)

4) Ask the user to confirm their wish to remove the states from the linked list. Write a function named deleteNode to perform the node deletion. (3 pts.)

5) Write the state name(s) and node addresses of each remaining node in the linked list to its own line in the same output text file as the original addresses (CensusNodes.txt).  The last line you write in this file should be "End of Updated Node List". (1 pt.)

Here is an example of how the CensusNodes.txt file should be formatted (your memory addresses will likely be different). Notice how the states beginning with the letter 'D' have been removed from the list and the pointer to the next node points to the state beginning with the letter 'F'. (Don't print the lines beginning with "..." which is just explanatory text in the example below.) Because the list creation function added new nodes to the head of the linked list, your states will be in reverse alphabetical order, which is OK:

6) Run your program twice removing the same states from the original list (first rename the first CensusNodes.txt file to CensusNodes.sav; do this in Windows, not in your program) and compare the new output file, CensusNodes.txt to CensusNodes.sav and answer the following questions:

Are the node addresses different or the same between the two different runs of the program?
If so, how do you explain why they are the same or different?
Are the node addresses in the linked lists adjacent to each other in memory in each of the files or not?
Why would the addresses be adjacent if they are, or why would they not be adjacent if they are not?
Write your answers in a text file named CensusNodesAnalysis.txt (5 pts.)
*/


#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;

//comments about each data type defined, either a separate line or at the end of a line


//Function Prototypes
void writeList(ListNode* ptr);
void displayPartialList(ListNode*& head);
void deleteNode(ListNode*& list);
void  writeUpdatedList(ListNode* head);

// Global Variable Declarations

int main()
{
    // Local variable declarations

    // Function calls, place comment at the end of the function call line to describe function purpose
    std::cout << endl << "End of Original Node List " << endl;
    writeList(censusList);

    displayPartialList(censusList);
    std::cout << endl << "End of Updated Node List " << endl;

    deleteNode(censusList);

    writeUpdatedList(censusList);
    std::cout << endl << "Updated Node List file " << endl;
    return 0;

}



/************************************************************
 *                       writeList
 * Function description
 * opens file CensusNodes.txt and prints data into file
 * while loop prints up to 55 can be reduced or expanded to include more lines
 ************************************************************/
void writeList(ListNode* ptr)
{

    int j = 0;
    //declares designated file
    ofstream outBound;
    // open file
    outBound.open("CensusNodes.txt");
    //error code in case of failure
    if (!outBound)
    {

        std::cout << " File could not open.";
        return;
    }
    else
    {
        outBound << "STATE, CURRENT NODE ADDRESS, NEXT NODE ADDRESS" << endl;
        while (ptr != nullptr && j < 55)
        {
            outBound << ptr->value.state << ", "
                << ptr << ", " << ptr->next << endl;
            ptr = ptr->next;
            j++;
        }

        outBound << "End of Original Node List " << endl;
    }
    outBound.close();

}


/************************************************************
 *                     displayPartialList
 * Function description
 * shows updated list in the console terminal
 * user input a valid char
 * ex c is entered and turned into C
 * all states beggining with the value C will be placed at the top of the list and shown to the user
 chatgpt lines 141-183
 *
 *
 ************************************************************/
void displayPartialList(ListNode*& head)
{
    std::cout << endl;
    std::cout << "Updated Node List" << endl;
    //variable declaration
    char input; //stores input 
    char inValidInput[] = "BEJQXYZ"; // invalid input characters 
    bool notValidInput = false;
    // programs keeps prompting user as long as input is invalid/ends if valid
    while (!notValidInput)
    {
        bool isInvalid = false;
        //prompts user to enter a char value  and change the input to a uppercase variable
        std::cout << "To Display States, Enter The First Character: ";
        std::cin >> input;
        input = toupper(input);
        //checks to see if input is any invalid chars
        for (int i = 0; i < 8; ++i)
        {
            if (inValidInput[i] == input)
            {
                isInvalid = true;
                break;
            }
        }
        // error message if invalid choice is chosen
        if (isInvalid)
        {
            std::cout << "The Letter " << input << " Is Not Valid. Please select a valid letter." << endl;
        }
        else
        {
            notValidInput = true;
        }
    }

    // Proceed to display the list
    std::cout << "\n";
    std::cout << "States beginning with the letter '" << input << "':" << endl;
    std::cout << "\n";

    bool found = false;
    ListNode* current = head;
    while (current != nullptr)
    {
        if (toupper(current->value.state[0]) == input)
        {
            std::cout << "node address=" << current << ", next node address=" << current->next << ", "
                << current->value.state << endl;
            found = true;
        }
        current = current->next;
    }

    ListNode* firstPart = nullptr;
    ListNode* secondPart = nullptr;
    current = head;
    // Separate the nodes based on the starting letter of the state name
    while (current != nullptr)
    {
        ListNode* next = current->next;
        if (toupper(current->value.state[0]) == input)
        {
            current->next = firstPart;
            firstPart = current;
        }
        else
        {
            current->next = secondPart;
            secondPart = current;
        }
        current = next;
    }

    // Concatenate the two parts to update the linked list
    head = firstPart;
    while (firstPart != nullptr && firstPart->next != nullptr)
    {
        firstPart = firstPart->next;
    }
    if (firstPart != nullptr)
    {
        firstPart->next = secondPart;
    }

    head = firstPart;
    // Display the updated linked list
    current = head;
    while (current != nullptr)
    {
        cout << "node address=" << current << ", next node address=" << current->next << ", "
            << current->value.state << endl;
        current = current->next;
    }




}
/************************************************************
 *                   deleteNode
 * Function description
 *delete a node from the linked list basted on user input
 * compares the input variable to the first letter in each state
 *
 *chatgpt line 215-238
 ************************************************************/
void deleteNode(ListNode*& list) {
    //variable declaration
    char input;
    //output to user
    std::cout << endl;
    std::cout << " Enter The Letter Of The State To Delete" << endl;
    std::cin >> input;
    input = toupper(input);


    ListNode* prev = nullptr;
    ListNode* current = list;
    while (current != nullptr) {
        //checks to see if input matches the first letter of state
        if (toupper(current->value.state[0]) == input) {
            // Node matches, remove it
            if (prev == nullptr) {
                // Special case: removing the head
                ListNode* temp = current;
                current = current->next;
                list = current;//updates the head 
                delete temp;
            }
            else {
                prev->next = current->next;//skips over current
                delete current;
                current = prev->next;//moves to next node 
            }
        }
        else {
            // Move to the next node
            prev = current;
            current = current->next;
        }
    }

}
/************************************************************
 *                             writeUpdatedList
 * Function description
 * writes the updated linked list after node deletion to the file
 * does not overwrite previous data
 *
 ************************************************************/

void writeUpdatedList(ListNode* head)
{


    ofstream outBound("CensusNodes.txt", ios::app);
    // ios::app used to not overwrite previous code

    outBound << endl << "Updated Node List" << endl;
    if (!outBound)
    {

        std::cout << " File could not open.";
        return;
    }
    else
    {
        //writes updated contents of link list to file
        ListNode* current = head;
        while (current) {
            outBound << current->value.state << ", "
                << current << ", " << current->next << endl;
            current = current->next;

        }
        outBound << endl << " End OF Updated Node List" << endl;

    }
    outBound.close();
}