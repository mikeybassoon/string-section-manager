/*
 * functions.cpp
 *
 * Contains primary functions used by main.cpp
 */

#include "orchestra.h"
#include "functions.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <iomanip>
#include <cassert>

using namespace std;

void readMusicianStats(vector<Musician>& section, ifstream& inputFile){
	int vectorIndex;
	int masters, pops, specials, kids;
	string name;
	inputFile >> masters >> pops >> specials >> kids; // read gigs scheduled

	// skip whitespace
	char x;
	do{
		inputFile.get(x);
	} while(x != '.');

	getline(inputFile, name, '\n'); // read musician name
	section.resize(section.size() + 1); // increase section size by 1
	vectorIndex = section.size() - 1; // find last index of section vector

	// record stats to new position in the vector
	section[vectorIndex].add_masters(masters);
	section[vectorIndex].add_pops(pops);
	section[vectorIndex].add_specials(specials);
	section[vectorIndex].add_kids(kids);
	section[vectorIndex].set_id(vectorIndex);
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
		if(selection >= 0 and selection <= 3) // valid selection?
			return selection;
		else cout << "Invalid selection, please try again." << endl;
	}
	return -1; // if program failed to execute properly
}

void create_program(){
	int seriesID; // holds integer to identify what series we are working with
	string gigName; // holds user input name for concert cycle
	cout << "Creating new program . . ." << endl;
	cout << "What series is this program on?" << endl;
	cout << "1. Masterworks" << endl;
	cout << "2. Pops" << endl;
	cout << "3. Specials" << endl;
	cout << "4. Kids" << endl;
	cout << "5. Return to main menu" << endl;
	cout << "Enter your selection: ";
	while(seriesID < 1 or seriesID > 5){ // until user provides valid input
		cin >> seriesID; // get user input
		if(seriesID < 1 or seriesID >5){ // invalid input?
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

	cout << "First Violins" << endl << endl; // let user know what section

	concertRoster << "First Violins" << endl << endl;
	generate_section_roster(violin1Section, thisGig.get_violin1Count(), seriesID, concertRoster);

	cout << endl << "Second Violins" << endl << endl; // let user know what section

	concertRoster << endl << "Second Violins" << endl << endl;
	generate_section_roster(violin2Section, thisGig.get_violin2Count(), seriesID, concertRoster);

	cout << endl << "Viola" << endl << endl; // let user know what section

	concertRoster << endl << "Viola" << endl << endl;
	generate_section_roster(violaSection, thisGig.get_violaCount(), seriesID, concertRoster);

	cout << endl << "Cello" << endl << endl; // let user know what section

	concertRoster << endl << "Cello" << endl << endl;
	generate_section_roster(celloSection, thisGig.get_celloCount(), seriesID, concertRoster);

	cout << endl << "Bass" << endl << endl; // let user know what section

	concertRoster << endl << "Bass" << endl << endl;
	generate_section_roster(bassSection, thisGig.get_bassCount(), seriesID, concertRoster);

	concertRoster.close(); // close concert roster file
	cout << "Concert roster file " << gigName << ".txt saved." << endl;


	// update the orchestra roster file
	ofstream orchestraRoster;
	orchestraRoster.open("orchestraRoster.txt");
	if(!orchestraRoster)
		cerr << "ERROR: cannot connect to orchestra roster file!" << endl;

	orchestraRoster << setw(outputWidth) << left << "Instrument";
	orchestraRoster << setw(outputWidth) << left << "Masterworks";
	orchestraRoster << setw(outputWidth) << left << "Pops";
	orchestraRoster << setw(outputWidth) << left << "Specials";
	orchestraRoster << setw(outputWidth) << left << "Kids";
	orchestraRoster << setw(outputWidth) << left << "Name" << endl;

	// print first violins
	print_section(violin1Section, orchestraRoster, "vln1");

	// print second violins
	print_section(violin2Section, orchestraRoster, "vln2");

	// print violas
	print_section(violaSection, orchestraRoster, "vla");

	// print cellos
	print_section(celloSection, orchestraRoster, "vcl");

	// print basses
	print_section(bassSection, orchestraRoster, "cb");

	orchestraRoster.close();
	cout << "Orchestra master roster file saved." << endl;
	cout << "Returning to main menu. . ." << endl;
}

void print_section(vector<Musician>& section, ofstream& file, const string& sectionName){
	for(auto i = 0; i < section.size(); i++){ // for all musicians in section
		file << setw(outputWidth) << left << sectionName;
		file << setw(outputWidth) << left << section[i].get_masters();
		file << setw(outputWidth) << left << section[i].get_pops();
		file << setw(outputWidth) << left << section[i].get_specials();
		file << setw(outputWidth) << left << section[i].get_kids();
		file << "." << section[i].get_name() << endl;
	}
}

void edit_program(){
	cout << "This function (edit_program) is currently non-functional" << endl;
}

void edit_roster(){
	cout << endl << "View/edit roster" << endl;

	cout << "Please select an action:" << endl;
	cout << "1. " << endl;

	cout << "Please select a section:" << endl;
	cout << "1. First Violins" << endl;
	cout << "2. Second Violins" << endl;
	cout << "3. Violas" << endl;
	cout << "4. Cellos" << endl;
	cout << "5. Basses" << endl;
	cout << "6. Return to previous menu" << endl;
	int selection; // set default selection value to invalid value value
	bool exit = false; // set loop exit flag to false
	while(not exit){
		cout << "Please enter your selection: ";
		cin >> selection; // get user selection
		if(selection >= 1 and selection <= 6) // valid selection?
			break; // exit menu loop
		else cout << endl << "Invalid selection, please try again." << endl;
	}
	if(selection == 1){
		cout << endl << "First Violins" << endl;
		display_roster(violin1Section);
	}
	else if(selection == 2){
		cout << endl << "Second Violins" << endl;
		display_roster(violin2Section);
	}
	else if(selection == 3){
		cout << endl << "Violas" << endl;
		display_roster(violaSection);
	}
	else if(selection == 4){
		cout << endl << "Cellos" << endl;
		display_roster(celloSection);
	}
	else if(selection == 5){
		cout << endl << "Basses" << endl;
		display_roster(bassSection);
	}
	else if(selection == 6) return; // return to previous menu if prompted
	else cerr << "ERROR: invalid selection!" << endl;
}

void display_roster(vector<Musician>& section){
	for(int i = 0; i < section.size(); i++){ // for each musician in section
		cout << i + 1 << ". " << section[i].get_name() << endl; // print musician name
	}
	cout << endl; // add blank space before returning
}

void generate_section_roster(vector<Musician>& section, int stringCount, const int seriesID, ofstream& file){
	if (stringCount < 1) return; // end func if no one in section
	int musiciansScheduled = 0; // # of musicians added to section for this gig
	int selection; // stores user selection
	bool next; // flag to move on from current menu

	// make a copy of the section vector
	vector<Musician> copy;
	copy.resize(section.size()); // set size equal to size of original vector
	for(auto i = 0; i < copy.size(); i++){ // for each entry in the copy vector
		copy[i] = section[i];
	}

	// select a section principal
	for(auto i = 0; i < copy.size(); i++){ // for each musician in section
		cout << i + 1 << ". " << copy[i].get_name() << endl;
	}
	cout << "Please select a section principal: ";
	cin >> selection; // get user choice

	file << setw(23) << left << "Principal: " << copy[selection - 1].get_name() << endl; // add musician name to gig roster
	section[copy[selection - 1].get_id()].add_gig(seriesID); // increment musician's gig count in original vector
	copy.erase(copy.begin() + selection - 1); // remove musician from available list
	musiciansScheduled++; // increment # of scheduled musicians
	cout << endl;

	if(stringCount == musiciansScheduled) // section full?
		return;

	// select assistant principal
	for(auto i = 0; i < copy.size(); i++){ // for each musician in section
		cout << i + 1 << ". " << copy[i].get_name() << endl;
	}
	cout << endl << "Please select an assistant principal: ";
	cin >> selection; // get user choice
	file << setw(23) << left << "Assistant Principal: " << copy[selection - 1].get_name() << endl; // add musician name to gig roster
	section[copy[selection - 1].get_id()].add_gig(seriesID); // increment musician's gig count
	copy.erase(copy.begin() + selection - 1); // remove musician from available list
	musiciansScheduled++; // increment # of scheduled musicians
	cout << endl;

	if(musiciansScheduled == stringCount)  // section full?
		return;

	// prompt user to select musicians who are unavailable
	next = false; // set flag to continue menu loop
	cout << endl << "Are any musicians unavailable for this gig?" << endl;
	while(!next){ // until exit flag set
		for(auto i = 0; i < copy.size(); i++){ // for all musicians in section
			cout << i + 1 << ". " << copy[i].get_name() << endl;
		}
		cout << copy.size() + 1 << ". No, all of these musicians are available." << endl;
		cout << "Please make a selection: ";
		cin >> selection; // get user selection
		if(selection >= 1 and selection <= copy.size()){ // valid selection made?
			copy.erase(copy.begin() + selection - 1); // remove musician from available list
			cout << endl << "Anyone else unavailable?" << endl;
		}
		else if(selection == copy.size() + 1) // user selects 'all musicians available'?
			next = true; // set exit flag
		else{
			cout << "I didn't understand your selection, sorry!" << endl;
			cout << "Are any of these musicians unavailable for this gig?" << endl;
		}

	} // exit loop on user selection

	next = false; // disable loop exit flag
	cout << endl << "Are there any musicians you want on this gig for sure?" << endl;
	while(!next){ // until exit flag set
		for(auto i = 0; i < copy.size(); i++){ // for all musicians in section
			cout << i + 1 << ". " << copy[i].get_name() << endl;
		}
		cout << copy.size() + 1 << ". No, select the rest of the section automatically." << endl;
		cout << "Please make a selection: ";
		cin >> selection; // get user selection
		if(selection >= 1 and selection <= copy.size()){ // valid selection made?
			file << setw(23) << " ";
			file << copy[selection - 1].get_name() << endl; // add musician name to gig roster
			section[copy[selection - 1].get_id()].add_gig(seriesID); // increment musician's gig count
			copy.erase(copy.begin() + selection - 1); // remove selected musician from available list
			musiciansScheduled++; // increment # of scheduled musicians
			if(musiciansScheduled == stringCount) return; // return if section full
			cout << endl << "Anyone else you want to include?" << endl;
		}
		else if(selection == copy.size() + 1) // user selects 'all musicians available'?
			next = true; // set exit flag
		else{
			cout << "I didn't understand your selection, sorry!" << endl;
			cout << "Are there any musicians you want on this gig for sure?" << endl;
		}

	} // exit loop on user selection

	while(musiciansScheduled < stringCount){ // until section is full
		if(copy.size() == 0){ // no musicians remain available?
			assignExtras(stringCount - musiciansScheduled, file); // fill unfilled spots with extras
			return; // end section
		}

		int winningIndex = 0; // winning index is first musician in list by default
		int winningSeriesGigs = copy[0].get_total(seriesID); // number of gigs on this series winning musician has
		int winningTotalGigs = copy[0].get_total(); // number of total gigs this season the winning musician has

		for(auto i = 1; i < copy.size(); i++){ // for each musician available in section
			// run compare function between current and winning index
			if(copy[i].get_total(seriesID) < winningSeriesGigs){ // new winner?
				winningIndex = i; // record index position
				winningSeriesGigs = copy[i].get_total(seriesID); // record gigs played on this series
				winningTotalGigs = copy[i].get_total(); // record total gigs played
			}
			else if(copy[i].get_total(seriesID) == winningSeriesGigs){ // gigs on series tied?
				if(copy[i].get_total() < winningTotalGigs){ // new winner?
					winningIndex = i; // record index position
					winningSeriesGigs = copy[i].get_total(seriesID); // record gigs played on this series
					winningTotalGigs = copy[i].get_total(); // record total gigs played
				}
				else if(copy[i].get_total() == winningTotalGigs){ // total gigs tied?
					if( (rand() % 2) == 1) // flip a coin
						winningIndex = i; // 50% chance of winningIndex being set to i
				}
			}
		} // end of loop - new winner identified
		file << setw(23) << " ";
		file << copy[winningIndex].get_name() << endl; // print winner name to roster
		copy.erase(copy.begin() + winningIndex); // remove winner from available list
	} // exit loop when section full
}

void assignExtras(const int number, ofstream& file){
	for(int i = 0; i < number; i++) // for every unfilled slot on roster
		file << "SUB/EXTRA MUSICIAN" << endl;
}
