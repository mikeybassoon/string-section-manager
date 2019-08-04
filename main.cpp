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
			string section;
			int vectorIndex;
			int masters, pops, specials, kids;
			string title;
			string name;
			inputFile >> section;
			inputFile >> masters >> pops >> specials >> kids;
			inputFile >> title;
			getline(inputFile, name, '\n');
			if(section == "vln1"){
				violin1Section.resize(violin1Section.size() + 1); // increase section size by 1
				vectorIndex = violin1Section.size() - 1; // find last index of section vector
				violin1Section[vectorIndex].add_masters(masters);
				violin1Section[vectorIndex].add_pops(pops);
				violin1Section[vectorIndex].add_specials(specials);
				violin1Section[vectorIndex].add_kids(kids);
				violin1Section[vectorIndex].set_title(title);
				violin1Section[vectorIndex].set_name(name);
			}
			else if(section == "vln2"){
				violin2Section.resize(violin2Section.size() + 1); // increase section size by 1
				vectorIndex = violin2Section.size() - 1; // find last index of section vector
				violin2Section[vectorIndex].add_masters(masters);
				violin2Section[vectorIndex].add_pops(pops);
				violin2Section[vectorIndex].add_specials(specials);
				violin2Section[vectorIndex].add_kids(kids);
				violin2Section[vectorIndex].set_title(title);
				violin2Section[vectorIndex].set_name(name);
			}
			else if(section == "vla"){
				violaSection.resize(violaSection.size() + 1); // increase section size by 1
				vectorIndex = violaSection.size() - 1; // find last index of section vector
				violaSection[vectorIndex].add_masters(masters);
				violaSection[vectorIndex].add_pops(pops);
				violaSection[vectorIndex].add_specials(specials);
				violaSection[vectorIndex].add_kids(kids);
				violaSection[vectorIndex].set_title(title);
				violaSection[vectorIndex].set_name(name);
			}
			else if(section == "vcl"){
				celloSection.resize(celloSection.size() + 1); // increase section size by 1
				vectorIndex = celloSection.size() - 1; // find last index of section vector
				celloSection[vectorIndex].add_masters(masters);
				celloSection[vectorIndex].add_pops(pops);
				celloSection[vectorIndex].add_specials(specials);
				celloSection[vectorIndex].add_kids(kids);
				celloSection[vectorIndex].set_title(title);
				celloSection[vectorIndex].set_name(name);
			}
			else if(section == "cb"){
				bassSection.resize(bassSection.size() + 1); // increase section size by 1
				vectorIndex = bassSection.size() - 1; // find last index of section vector
				bassSection[vectorIndex].add_masters(masters);
				bassSection[vectorIndex].add_pops(pops);
				bassSection[vectorIndex].add_specials(specials);
				bassSection[vectorIndex].add_kids(kids);
				bassSection[vectorIndex].set_title(title);
				bassSection[vectorIndex].set_name(name);
			}
		} // input file read
		cout << "Roster updated!" << endl;

		cout << endl << "Please select from the following options:" << endl;
		cout << "1. Create new program" << endl;
		cout << "2. View/edit existing program" << endl;
		cout << "3. View/edit section roster" << endl;
		cout << "9. Exit program" << endl;
	} // end of main program loop
	return 0;
}
