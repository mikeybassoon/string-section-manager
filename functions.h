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
 * No side effect
 */
int main_menu();

void create_program(); // requires definition

void edit_program(); // requires definition

void edit_roster(); // requires definition


#endif /* FUNCTIONS_H_ */
