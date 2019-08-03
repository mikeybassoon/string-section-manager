/*
 * functions.cpp
 *
 *  Created on: Jul 11, 2019
 *      Author: michaelmacaulay
 */

#include "orchestra.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/* void MakeUnavailable
 *
 * Inputs:			2 (bool array, int size of array)
 *
 * Postcondition:	Entries in bool array will be set to false
 */
void MakeUnavailable(bool sectionArray[], int arraySize){
	for(int i = 0; i < arraySize; i++){
		sectionArray[i] = false;
	}
}

/* void PrintAvailableNames
 *
 * inputs:	3 (string array of names for a section, bool array of availabilities for the same section, int array size)
 *
 * postcondition: a numbered list of names printed to the console, with numbers corresponding to their index
 *
 */
void PrintAvailableNames(string name[], bool available[], int arraySize){
	for(int i = 0; i < arraySize; i++){ // for each musician in the section
		if(available[i] == true) cout << i << ". " << name[i] << endl; // print their name and number if they are available
	}
}

/* musician ReadMusician
 *
 * Purpose:	Reads a single musician's stats from a roster file
 *
 * Input:	input file stream buffer
 *
 */

/* int SumOfArray
 *
 * inputs:	2 - an int array to be summed, and the number of entries in the array
 *
 * output:	The sum of the array entries
 */
int SumOfArray(int array[], int numberOfSeries){
	int sum = 0;
	for(int j = 0; j < numberOfSeries; j++) sum += array[j]; // add each entry in the array to sum
	return sum;
}

/* int newSumOfArray
 *
 * Purpose:	To be used in place of SumOfArray once program is switched over to vectors
 *
 * inputs:	vector<int> to be summed
 *
 * output:	The sum of the array entries
 */
int newSumOfArray(vector<int>& vectorToSum){
	int sum = 0;
	for(int& x : vectorToSum) sum += x;
	return sum;
}

/*int FindLowest
 *
 * Inputs:		5 (integer array of gigs scheduled on a given series, int array of total gigs scheduled to date,
 * 				bool array of each musician's availability for the gig, int size of array, int series counter)
 *
 * Output:		int (index of the smallest value contained in the array)
 *
 * Algorithm:	Disregard any musicians flagged as unavailable
 * 				Check entry in the relevant gig count array to see if it is the lowest observed
 * 					If it is, record the gig count and store its index position
 * 					If it is tied for lowest, break the tie using total gigs scheduled on all series
 * 				Return index position of least-used musician
 */
int FindLowest(int gigArray[], int totalGigArray[], bool available[], int arraySize){
	int lowestIndex = -1; // set lowestIndex to negative int to signal if no musicians are available
	int lowestGigCount = 200; // stores lowest gig count currently recorded, set arbitrarily large as default
	int lowestTotalGigCount = 200; // stores lowest TOTAL gig count across all series, arbitrarily large as default

	if(available[0] == true){
		lowestGigCount = gigArray[0]; // if first musician is available, set their gig counter to lowest
		lowestTotalGigCount = totalGigArray[0];
		lowestIndex = 0;
	}
	for(int i = 1; i < 20; i ++){ // for each remaining musician in array
		if (available[i] == true && gigArray[i] < lowestGigCount){ // if musician read has fewer gigs, set their gig count and index to lowest
			lowestGigCount = gigArray[i];
			lowestTotalGigCount = totalGigArray[i];
			lowestIndex = i;
		}
		else if (available[i] == true && gigArray[i] == lowestGigCount){ // if musician read ties for fewest gig, compare overall gig totals
			if (totalGigArray[i] < lowestTotalGigCount){
				lowestTotalGigCount = totalGigArray[i];
			}
		}
	}
	return lowestIndex;
}
