/*
 * functions.cpp
 *
 *  Created on: Aug 4, 2019
 *      Author: michaelmacaulay
 */

#include "orchestra.h"
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
}

