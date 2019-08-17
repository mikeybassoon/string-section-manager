/*
 * functions.h
 *
 *  Created on: Aug 4, 2019
 *      Author: michaelmacaulay
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include "orchestra.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/* void saveMusicianStats()
 * Purpose: Reads a single line from input file (orchestra roster)
 * 		Stores that information as a new musician record in a section vector
 * Parameters:
 * 		<1> vector for the appropriate section
 * 		<2> input file buffer
 * No return
 * Side effect: Stores following:
 * 		<1> Musician name
 * 		<2> Musician title (e.g. concertmaster, principal)
 * 		<3> Number of masters, pops, specials and kids concerts that musician is
 * 			currently scheduled for
 */
void saveMusicianStats(vector<Musician>&, ifstream&);

/* int main_menu()
 * Purpose: displays main program menu and returns user selection
 * No parameters
 * Returns an int representing a valid user selection
 * 		If function executes incorrectly, returns -1
 * No side effect
 */
int main_menu();

/* void create_program()
 * Purpose: generates a roster for a new program
 * Parameters: none
 * No return
 * Side effects:
 * 		<1> Roster file (.txt) created for that program
 * 		<2> Orchestra roster updated with new gig totals for each musician
 */
void create_program();

/* void print_section()
 * Purpose: prints specified section to master orchestra roster
 * Parameters:
 * 	<1> vector<Musician> - the section to be printed
 * 	<2> ofstream& - the output file (orchestraRoster.txt)
 * 	<3> string& - the section name (as it appears in the output file)
 * Preconditions:
 * 	<1> section name must be vln1, vln2, vla, vcl, or cb
 * No return
 * Side effects:
 * 	<1> Each musician, along with their associated statistics, printed to output file
 */
void print_section(vector<Musician>&, ofstream&, const string&);

void edit_program(); // requires definition

void edit_roster(); // requires definition

/* void generate_section_roster()
 * Purpose: Fills section roster for a program
 * Parameters:
 * 	<1> vector<Musician> - available musicians in a particular section
 * 	<2> int - count for that section
 * 	<3> int - series ID for the program
 * 	<4> ofstream - output file stream
 * No return
 * Side effects:
 * 	<1> Section roster for program added to program roster output file
 * 		(with one blank line below the roster list)
 * 	<2> Gig total statistics updated for all musicians
 */
void generate_section_roster(vector<Musician>&, int, const int, ofstream&);

/* void assignExtras()
 * Purpose: Fills remaining slots in section with extra musicians
 * Parameters:
 * 	<1> const int - number of extras needed
 * 	<2> ofstream - concert roster file
 * No return
 * Side effects:
 * 	<1> All vacant spots in section on roster file will be marked as a substitute or extra musician
 */
void assignExtras(const int, ofstream&);


#endif /* FUNCTIONS_H_ */
