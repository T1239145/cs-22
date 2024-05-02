//chpt 2

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void topPattern(int, int);
void bottomPattern(int, int);
void printSpaces(int);
void writeData();
	/*
	 desired output with 4 input
						  * 

						 * * 

					    * * * 

				       * * * * 

                        * * * 

                         * * 

                          *
	*/
	int main() {
		//declaration of variables
		int input = (0);

			//console and user input
		std::cout << " Please Enter A Number Between 4 - 12 " << std::endl;
		std::cin >> input;
		//calls topPattern to print as many rows as input 
		//chat gpt a 2nd input provides both arguments for A and originalA
		topPattern(input,input);
		//calls bottomPattern will have 1 less row than input
		bottomPattern(input,input);
		//writes data to txt file 
		writeData();

		return 0;
	}


	void printSpaces(int spaces) {
		if (spaces == 0)
			return;
		std::cout << " ";
		printSpaces(spaces - 1);
	}

	void topPattern(int A, int originalA) {
		/*prints top half of image. if 4 is inserted 
					      * 

						 * * 

					    * * * 

				       * * * * 
		 */
		if (A == 0) {
			return;
		}
		//dictates the number of rows being called 
		topPattern(A - 1,originalA);

		std::cout << std::endl;
		//chat gpt line 63 prints spaces for indentation
		printSpaces(originalA-A);
		

		//prints * in each row 
		for (int i = 0; i < A; ++i) {
			//std::cout << " ";
			std::cout << "* ";
		}
		std::cout << std::endl;	
	}
	//could use setw and left to align rows
	void bottomPattern(int B,int originalB) {
		/*		BottomPattern if input is 4
			* * *
			 * *
	          *
		*/
		if (B == 0) {
			return;
		}
		

		std::cout << std::endl;
		/*
		to offset the same endline being repeated as topPattern
		int i = 1, tested for 4,8,12
		*/
		printSpaces(originalB - B + 1);//+1 is used to indent the bottom 
		//prints * in each row
		for (int i = 1; i < B; i++) {
			std::cout << "* ";
		}
		std::cout << std::endl;
		//dictates the number of rows being called at the bottom of function
		bottomPattern(B - 1,originalB);
		

	}

	//VariableAddresses.txt
	
	void writeData()
	{
		//int j = 0;

		ofstream outBound;

		outBound.open("VariableAddresses.txt");

		if (!outBound) {
			std::cout << " File could not open. ";
			return;
		}
		else
		{ //	display of txt file number of lines(input)
			outBound << "Number Of Lines = ";
			//"variableName" address = &variableName
			// ex: i =1 address = 0x61fae8
		}
		outBound.close();
	}