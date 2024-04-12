/*
1 -Update the comment boxes at the top of each function in the.cpp files.
2-Fix the syntax and logic errors in the program.
3-Modify the console output to include ASCII art 
representations of the cards dealt instead of text 
output messages.Include code to read the ASCII art text 
file into memory(an array works best) and display the card art
in addition to the card name and suit.The program logic should 
remain the same otherwise.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<string> readCard();
void print(const vector<string>& cardArt);


int main(){
	vector<string> cardArt = readCard();
	print(cardArt);
	return 0;
}

//1-declares vector cardArt as a string,line also declared string
//2-opens file,if file dosnt open user will be notified
//3-getline function reads each string value line till eof
//4-cardArt.push_back(line); stores each line in the vector cardArt
//5-closes file and returns vector cardArt

vector<string> readCard(){
	vector<string> cardArt; //vector to store  declares string
	string line;
	ifstream myFile("CardASCII_Art.txt");

	
	if (myFile.fail()) {
		cout << "unable to open file! " << endl;
		return cardArt;
	}
		while (getline(myFile, line))
		{
			cardArt.push_back(line);
		}
		myFile.close();
		return cardArt;
}

//
//
void print(const vector <string>& cardArt){
	for (const auto& line : cardArt)
	{
		cout << line << endl;

	}
}