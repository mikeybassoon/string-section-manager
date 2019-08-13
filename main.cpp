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
			else cout << "Roster file opened successfully . . ." << endl;
		inputFile.ignore(256, '\n'); // skip first line of input file (key to interpret the file)
		inputFile.ignore(256, '\n'); // skip second line of input file (warning)
		int linecount = 3; // initialize line counter (for error checking loop)
		while(!inputFile.eof()){ // until entire file is read
			string section;
			inputFile >> section;
			if(section == "vln1")
				saveMusicianStats(violin1Section, inputFile);
			else if(section == "vln2")
				saveMusicianStats(violin2Section, inputFile);
			else if(section == "vla")
				saveMusicianStats(violaSection, inputFile);
			else if(section == "vcl")
				saveMusicianStats(celloSection, inputFile);
			else if(section == "cb")
				saveMusicianStats(bassSection, inputFile);
			else{
				cerr << "ERROR: Invalid section identifier in input file: line " << linecount << endl;
				cerr << "Value given: " << section << endl;
				cerr << "Ending program" << endl;
				return -1;
			}
			linecount++;
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
		create_program(violin1Section, violin2Section, violaSection, celloSection, bassSection);
	else if(userSelection == 2) // edit program?
		edit_program();
	else if(userSelection == 3) // edit section roster?
		edit_roster();


	} // end of main program loop
	return 0;
}
