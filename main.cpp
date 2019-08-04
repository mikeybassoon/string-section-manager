/*
 * main.cpp
 */

#include "orchestra.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main(){

	// vectors storing all musicians currently under contract to the orchestra
	vector<Musician> violin1Section;
	vector<Musician> violin2Section;
	vector<Musician> violaSection;
	vector<Musician> celloSection;
	vector<Musician> bassSection;

	cout << "STRING SECTION MANAGER" << endl;

	ifstream inputFile;

	bool continueProgram = true; // program will continue running until user terminates it
	while (continueProgram == true) { // loop of main algorithm

		cout << "Updating roster information . . . " << endl;

		// connect to orchestra roster file and error check
		inputFile.open("orchestraRoster.txt");
			if(!inputFile){
				cerr << "ERROR: Cannot connect to input file \"orchestraRoster.txt\", ending program.";
				return -1;
			}
		inputFile.ignore(256, '\n'); // skip first line of input file
		while(true){ // until entire file is read
			string stringRead;

		}
		cout << "Ending program.";
		return 0;
	}
}
