/*
NAMEJustin Anderson                    CS-22 DATA STRUCTURES AND ALGORITHMS
SEMESTER    Spring 2024                     PROFESSOR THURSTON
SECTION#cs 22 31675
ASSIGNMENT #5Programming Assignment 5: Linked List Programming and Analysis
Instructions
[COPY FROM CANVAS]
*/
// This program illustrates building a linked list.
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string> //added (JA)
using namespace std;

struct censusData
    {
        string state, totPop, adultPop, percentPop;
    };

censusData  censusRecord;

struct ListNode // ListNode is a struct--a C++ struct can have multiple functions but C only allowed a constructor function.
                // The C language has struct data types, but not classes. C++ has classes usually with member functions.
  {
     censusData value;
     ListNode *next;
     // Constructor
     ListNode(censusData value1, ListNode *next1 = nullptr) // Constructor function inside (inline in) the struct definition
     {
       value = value1;  // value is a census record
       next = next1;
     }
  };
                                                                                                                  
// Function prototypes
int size(ListNode *);
void displayList(ListNode *);
void writeList(ListNode  *ptr);
void displayPartialList(ListNode*& head);
void deleteNode(ListNode*& list);
void  writeUpdatedList(ListNode *head);

int main()
{
   ListNode *censusList = nullptr;    // List of numbers
   string stateLetters;              // string to store first letters of states

   // Open the file
   ifstream censusFile("censusData.csv");
  

   if (!censusFile)
   {
        std::cout << "Error in opening the file of numbers.";
        exit(1);
   }
   // Read the file into a linked list
   while (!censusFile.eof())
   {
    getline(censusFile, censusRecord.state, ',');
    getline(censusFile, censusRecord.totPop, ',');
    getline(censusFile, censusRecord.adultPop, ',');
    getline(censusFile, censusRecord.percentPop);
    if (censusFile.eof())
        break;          
    // getline sets eof flag after reading beyond end of file
 //SOME DEBUGGING CODE TO SEE WHAT'S READ
     // cout << "censusRecord.state=" << censusRecord.state << endl;
   // cout << "censusRecord.totPop=" << censusRecord.totPop << endl;
   //   cout << "censusRecord.adultPop=" << censusRecord.adultPop << endl;
//      cout << "censusRecord.percentPop=" << censusRecord.percentPop << endl;
//      getchar();

    // ADD A LINE OF CODE BELOW TO APPEND THE FIRST LETTER OF THE STATE NAME TO THE stateLetters STRING
    // IF IT IS A LETTER NOT READ YET

      // Create a node to hold this number (adds to the head of the list each time)
      censusList = new ListNode(censusRecord, censusList);
    }

   // Print the list
   std::cout << endl << "The contents of the list are: " << endl;
   displayList(censusList);

   // Print the size of the list
   std::cout << endl << "The number of items in the list is: "
       << size(censusList) << endl;

  // cout << endl;
 
   std::cout  << endl <<  "End of Original Node List " << endl;
     writeList(censusList);

   displayPartialList(censusList);
   std::cout << endl <<  "End of Updated Node List " << endl;

   deleteNode(censusList);

   writeUpdatedList(censusList);
   std::cout << endl << "Updated Node List file " << endl;
   //writeUpdatedList(censusList);
   /////////////////////////////////////////////
   //
   // INSERT CODE BELOW FOR ASSIGNMENT 5
   //
   /////////////////////////////////////////////


   return 0;
}

//*****************************************
// length computes the number of nodes in *
// a linked list                          *
//*****************************************
int size(ListNode *ptr)
{
  if (ptr == nullptr)
    return 0;
  else
   return 1 + size(ptr->next);
}

//*******************************************
// displayList prints all the values stored *
// in the list                              *
//*******************************************
void displayList(ListNode *ptr)
{
  if (ptr != nullptr)
    {
      std::cout  << "node address=" << ptr << ", next node address=" << ptr->next << ", "
            << ptr-> value.state << endl;;
      displayList(ptr->next);
    }
}

void writeList(ListNode *ptr)
{
    
    int j = 0;
    //declares designated file
    ofstream outBound;
    // open file
    outBound.open("CensusNodes.txt");

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
                << ptr << ", " <<  ptr->next << endl;
            ptr = ptr->next;
            j++;
        }

        outBound << "End of Original Node List " << endl;
    }
    outBound.close();
    
}


void displayPartialList(ListNode*& head)
{
    std::cout << endl;
    std::cout << "Updated Node List" << endl;

    char input;//variable to store 
    //char validInput[] = "ACDFGHIKLMNOPRSTUVW";// not needed
    char inValidInput[] = "BEJQXYZ"; // invalid input characters 
    bool notValidInput = false;

    while (!notValidInput)// programs keeps prompting user as long as input is invalid/ends if valid
    {
        bool isInvalid = false;

        std::cout << "To Display States, Enter The First Character: ";
        std::cin >> input;
        input = toupper(input);
        //checks to see if input is any invalid chars
        for (int i = 0; i < 7; ++i)
        {
            if (inValidInput[i] == input)
            {
                isInvalid = true;
                break;
            }
        }

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
    //ListNode* current = head;
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
void deleteNode(ListNode*& list) {
    char input;
    std::cout << endl;
    std::cout << " Enter The Letter Of The State To Delete" << endl;
    std::cin >> input;
    input = toupper(input);
    

    ListNode* prev = nullptr;
    ListNode* current = list;
    while (current != nullptr) {
        if (toupper(current->value.state[0]) == input) {
            // Node matches, remove it
            if (prev == nullptr) {
                // Special case: removing the head
                ListNode* temp = current;
                current = current->next;
                list = current;
                delete temp;
            }
            else {
                prev->next = current->next;
                delete current;
                current = prev->next;
            }
        }
        else {
            // Move to the next node
            prev = current;
            current = current->next;
        }
    }

}

void writeUpdatedList(ListNode* head)
{
   // int j = 0;

    ofstream outBound("CensusNodes.txt", ios::app);
    // ios::app used to not overwrite previous code
    //outBound.open("CensusNodes.txt", ios::app);
    //ListNode* ptr = head;
    outBound << endl << "Updated Node List" << endl;
    if (!outBound)
    {

        std::cout << " File could not open.";
        return;
    }
    else 
    {
    
        ListNode* current = head;
        while (current ) {
            outBound << current->value.state << ", " 
                << current << ", " << current->next << endl;
            current = current->next;
           
        }
        outBound << endl << " End OF Updated Node List" << endl;
       
    }
    outBound.close();
}
//dfg dosnt work      ACDFGHIKLMNOPRSTUVW"
//letters that work w 