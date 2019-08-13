/*
 * functions.h
 *
 *  Created on: Aug 4, 2019
 *      Author: michaelmacaulay
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

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
 * Parameters:
 * 	<1> vector<Musician> - first violins
 * 	<2> vector<Musician> - second violins
 * 	<3> vector<Musician> - violas
 * 	<4> vector<Musician> - celli
 * 	<5> vector<Musician> - basses
 * No return
 * Side effects:
 * 		<1> Roster file (.txt) created for that program
 * 		<2> Orchestra roster updated with new gig totals for each musician
 */
void create_program(vector<Musician>, vector<Musician>, vector<Musician>,
		vector<Musician>, vector<Musician>);

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
void generate_section_roster(vector<Musician>, int, const int, ofstream&);


#endif /* FUNCTIONS_H_ */
