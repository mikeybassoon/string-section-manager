/*
 * functions.cpp
 *
 *  Created on: Aug 4, 2019
 *      Author: michaelmacaulay
 */

#include "orchestra.h"
#include "functions.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void saveMusicianStats(vector<Musician>& section, ifstream& inputFile){
	int vectorIndex;
	int masters, pops, specials, kids;
	string title;
	string name;
	inputFile >> masters >> pops >> specials >> kids; // read gigs scheduled
	inputFile >> title; // read musician's title
	getline(inputFile, name, '\n'); // read musician name
	section.resize(section.size() + 1); // increase section size by 1
	vectorIndex = section.size() - 1; // find last index of section vector
	// record stats to new position in the vector
	section[vectorIndex].add_masters(masters);
	section[vectorIndex].add_pops(pops);
	section[vectorIndex].add_specials(specials);
	section[vectorIndex].add_kids(kids);
	section[vectorIndex].set_title(title);
	section[vectorIndex].set_name(name);
}

int main_menu(){
	int selection; // stores user selection
	bool exit = false; // exit flag for selection loop
	cout << "Main Menu" << endl;
	cout << "Please select from the following options:" << endl;
	cout << "1. Create new program" << endl;
	cout << "2. View/edit existing program" << endl;
	cout << "3. View/edit section roster" << endl;
	cout << "0. Exit program" << endl;
	while(!exit){
		cout << "Enter your selection: ";
		cin >> selection;
		if(selection >= 0 and selection <= 3)
			return selection;
		else cout << "Invalid selection, please try again." << endl;
	}
	return -1; // if program failed to execute properly
}

void create_program(){
	int seriesID = 0; // holds integer to identify what series we are working with
	string gigName; // holds user input name for concert cycle

	cout << "Creating new program . . ." << endl;
	cout << "What series is this program on?" << endl;
	cout << "1. Masterworks" << endl;
	cout << "2. Pops" << endl;
	cout << "3. Specials" << endl;
	cout << "4. Kids" << endl;
	cout << "5. Return to main menu" << endl;
	cout << "Enter your selection: ";
	while(seriesID < 1 or seriesID > 5){ // until user provides valid response
		cin >> seriesID; // get user input
		if(seriesID < 1 or seriesID >5){ // invalid selection?
			cout << endl << "Invalid selection, please try again: ";
		}
	}
	if(seriesID == 5) return; // return to main menu if prompted by user

	cout << endl << "Please enter a name for this concert (no spaces): ";
	cin >> gigName; // get concert cycle name from user
	cout << endl << "Creating roster file for this concert. . . " << endl;

	ofstream concertRoster; // connects to roster file for the concert
	concertRoster.open(gigName + ".txt"); // create roster file
	if(!concertRoster)
		cerr << "ERROR: cannot create concert roster file " << gigName << ".txt!" << endl;

	// generate the roster
	// set string counts
	int userInput; // will hold user input integer values
	Gig thisGig(seriesID); // create new instance of Gig class
	cout << "Enter number of 1st violins on gig: ";
	cin >> userInput;
	thisGig.set_violin1Count(userInput); // set vln 1 count
	cout << endl << "Enter number of 2nd violins on gig: ";
	cin >> userInput;
	thisGig.set_violin2Count(userInput); // set vln 2 count
	cout << endl << "Enter number of violas on gig: ";
	cin >> userInput;
	thisGig.set_violaCount(userInput); // set vla count
	cout << endl << "Enter number of cellos on gig: ";
	cin >> userInput;
	thisGig.set_celloCount(userInput); // set vcl count
	cout << endl << "Enter number of basses on gig: ";
	cin >> userInput;
	thisGig.set_bassCount(userInput); // set cb count

	// print header for concert cycle roster
	concertRoster << "Concert Cycle Roster";
	if(seriesID == 1) concertRoster << endl << "Masterworks - ";
	else if(seriesID ==2) concertRoster << endl << "Pops - ";
	else if(seriesID == 3) concertRoster << endl << "Specials - ";
	else if(seriesID == 4) concertRoster << endl << "Kids - ";
	else cerr << "ERROR: invalid value for seriesID! Value given: " << seriesID << ". Ending program."<< endl;
	concertRoster << gigName << endl; // print name of gig next to series name
	// print string count
	concertRoster << "String count: " << thisGig.get_violin1Count() << "/" <<thisGig.get_violin2Count() << "/"
			<< thisGig.get_violaCount() << "/" << thisGig.get_celloCount() << "/" << thisGig.get_bassCount() << endl << endl;




	// generate sections (add to output file as you go)

	// should there be a generic "generate section" function that you pass gigs to?

	// set 1st violin section
	// set 2nd violin section
	// set viola section
	// set cello section
	// set bass section






	concertRoster.close(); // close concert roster file
	cout << "Concert roster file " << gigName << ".txt saved." << endl;

	ofstream orchestraRoster;
	orchestraRoster.open("orchestraRoster.txt");
	if(!orchestraRoster)
		cerr << "ERROR: cannot connect to orchestra roster file!" << endl;


	// update full orchestra roster






	orchestraRoster.close();
	cout << "Orchestra master roster file saved." << endl;
	cout << "Returning to main menu. . ." << endl;
}

void edit_program(){
	cout << "This function is currently non-functional" << endl;
}

void edit_roster(){
	cout << "This function is currrently non-functional" << endl;
}
