/*
 * main.cpp
 */

#include "orchestra.h"
#include "functions.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// vectors storing all musicians currently under contract to the orchestra
vector<Musician> violin1Section;
vector<Musician> violin2Section;
vector<Musician> violaSection;
vector<Musician> celloSection;
vector<Musician> bassSection;

int main(){

	cout << "STRING SECTION MANAGER" << endl;

	ifstream inputFile;

	bool continueProgram = true; // program will continue running until user terminates it
	while (continueProgram) { // loop of main algorithm

		cout << "Updating roster information . . . " << endl;

		// connect to orchestra roster file and error check
		inputFile.open("orchestraRoster.txt");
			if(!inputFile){
				cerr << "ERROR: Cannot connect to input file \"orchestraRoster.txt\", ending program.";
				return -1;
			}
			else cout << "Roster file opened successfully . . ." << endl;
		inputFile.ignore(256, '\n'); // skip first line of input file (key to interpret the file)
		while(!inputFile.eof()){ // until entire file is read
			string section;
			inputFile >> section;
			if(section == "vln1")
				readMusicianStats(violin1Section, inputFile);
			else if(section == "vln2")
				readMusicianStats(violin2Section, inputFile);
			else if(section == "vla")
				readMusicianStats(violaSection, inputFile);
			else if(section == "vcl")
				readMusicianStats(celloSection, inputFile);
			else if(section == "cb")
				readMusicianStats(bassSection, inputFile);
		} // input file read
		inputFile.close();
		cout << "Roster updated!" << endl;

	int userSelection = main_menu(); // display main menu, prompt user for input
	if(userSelection < 0 or userSelection > 3){ // error check result of main_menu()
		cerr << "ERROR: invalid return in main_menu()" << endl;
		return -1;
	}
	if(userSelection == 0){ // exit program?
		cout << "Exiting program." << endl;
		return 0;
	}
	else if(userSelection == 1) // create new program?
		create_program();
	else if(userSelection == 2) // edit program?
		edit_program();
	else if(userSelection == 3) // edit section roster?
		edit_roster();
	} // end of main program loop
	return 0;
}
