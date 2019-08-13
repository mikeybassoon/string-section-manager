/*
 * functions.cpp
 *
 * Contains primary functions used by main.cpp
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

void create_program(vector<Musician> violin1Section, vector<Musician> violin2Section,
		vector<Musician> violaSection, vector<Musician> celloSection, vector<Musician> bassSection){
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
	else if(seriesID == 2) concertRoster << endl << "Pops - ";
	else if(seriesID == 3) concertRoster << endl << "Specials - ";
	else if(seriesID == 4) concertRoster << endl << "Kids - ";
	else cerr << "ERROR: invalid value for seriesID! Value given: " << seriesID << ". Ending program."<< endl;
	concertRoster << gigName << endl; // print name of gig next to series name
	// print string count
	concertRoster << "String count: " << thisGig.get_violin1Count() << "/" <<thisGig.get_violin2Count() << "/"
			<< thisGig.get_violaCount() << "/" << thisGig.get_celloCount() << "/" << thisGig.get_bassCount() << endl << endl;

	// generate sections (add to output file as you go)

	cout << "First Violins" << endl; // let user know what section

	concertRoster << "First Violins" << endl << endl;
	generate_section_roster(violin1Section, thisGig.get_violin1Count(), seriesID, concertRoster);

	cout << "Second Violins" << endl; // let user know what section

	concertRoster << "Second Violins" << endl << endl;
	generate_section_roster(violin2Section, thisGig.get_violin2Count(), seriesID, concertRoster);

	cout << "Viola" << endl; // let user know what section

	concertRoster << "Viola" << endl << endl;
	generate_section_roster(violaSection, thisGig.get_violaCount(), seriesID, concertRoster);

	cout << "Cello" << endl; // let user know what section

	concertRoster << "Cello" << endl << endl;
	generate_section_roster(celloSection, thisGig.get_celloCount(), seriesID, concertRoster);

	cout << "Bass" << endl; // let user know what section

	concertRoster << "Bass" << endl << endl;
	generate_section_roster(bassSection, thisGig.get_bassCount(), seriesID, concertRoster);

	concertRoster.close(); // close concert roster file
	cout << "Concert roster file " << gigName << ".txt saved." << endl;
	/*
	ofstream orchestraRoster;
	orchestraRoster.open("orchestraRoster.txt");
	if(!orchestraRoster)
		cerr << "ERROR: cannot connect to orchestra roster file!" << endl;


	// update full orchestra roster






	orchestraRoster.close();
	cout << "Orchestra master roster file saved." << endl;
	*/
	cout << "Returning to main menu. . ." << endl;
}

void edit_program(){
	cout << "This function (edit_program) is currently non-functional" << endl;
}

void edit_roster(){
	cout << "This function (edit_roster) is currrently non-functional" << endl;
}

void generate_section_roster(vector<Musician> section, int stringCount, const int seriesID, ofstream& file){
	int musiciansScheduled = 0; // # of musicians added to section for this gig
	int selection; // stores user selection

	for(auto i:section){ // for entire section
		i.set_available(true); // make all musicians available
	}

	// select a section principal
	if(stringCount > 0){
		for(int i = 0; i < section.size(); i++){
			cout << i << ". " << section[i].get_name() << endl;
		}
		cout << "Please select a section principal: ";
		cin >> selection; // get user choice
		section[selection].set_available(false); // make musician unavailable
		file << "Principal: " << section[selection].get_name() << endl; // add to gig roster
		section[selection].add_gig(seriesID); // increment musician's gig count
		musiciansScheduled++; // increment # of scheduled musicians
	}
	// select assistant principal
	if(stringCount > 1){
		for(int i = 0; i < section.size(); i++){
			if(section[i].get_available() == true){
				cout << i << ". " << section[i].get_name() << endl;
			}
		}
		cout << "Please select an assistant principal: ";
		cin >> selection; // get user choice
		section[selection].set_available(false); // make musician unavailable
		file << "Assistant Principal: " << section[selection].get_name() << endl; // add to gig roster
		section[selection].add_gig(seriesID); // increment musician's gig count
		musiciansScheduled++; // increment # of scheduled musicians
	}
	// prompt user to select musicians who are unavailable
	if(musiciansScheduled < stringCount){

	}
	// loop: musicians unavailable?
	// loop: force include any musicians?
	// fill section until full
	// if empty spaces, print "sub/extra"
}
