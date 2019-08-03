/*
 * orchestra.h
 *
 *  Created on: Jul 11, 2019
 *      Author: michaelmacaulay
 */

#include <iostream>
#include <string>
#ifndef ORCHESTRA_H_
#define ORCHESTRA_H_
#define HOW_MANY_SERIES 4

using namespace std;



class Musician{
public:
	string title;
	string name;
	int mastersScheduled, popsScheduled, specialsScheduled, kidsScheduled;
};

vector<Musician> violin1;
vector<Musician> violin2;
vector<Musician> viola;
vector<Musician> cello;
vector<Musician> bass;

void MakeUnavailable(bool[], int);
int FindLowest(int[], int[], bool[], int);
void PrintAvailableNames(string[], bool[], int);
Musician ReadMusician(ifstream);
int SumOfArray(int[], int);

#endif /* ORCHESTRA_H_ */
