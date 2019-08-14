/*
 * orchestra.h
 *
 * Contains:
 * 		- Musician class interface
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#ifndef ORCHESTRA_H_
#define ORCHESTRA_H_
#define HOW_MANY_SERIES 4 // number of different subscription series being tracked
#define outputWidth 15

using namespace std;

class Musician{
private:
	string name;
	int mastersScheduled, popsScheduled, specialsScheduled, kidsScheduled;
	bool available; // available for current gig?
public:
	Musician(); // constructor
	~Musician(); // destructor
	void set_name(string);
	void set_available(bool);
	void add_masters(); // increment by 1
	void add_masters(int);
	void add_pops(); // increment by 1
	void add_pops(int);
	void add_specials(); // increment by 1
	void add_specials(int);
	void add_kids(); // increment by 1
	void add_kids(int);
	void add_gig(int); // increments gig count, parameter is the series ID for the gig
	string get_name();
	int get_masters();
	int get_pops();
	int get_specials();
	int get_kids();
	int get_total(); // total gigs across all series
	int get_total(int); // total gigs for given series ID
	bool get_available();
};

class Gig{
private:
	int series; // masters = 1, pops = 2, specials = 3, kids = 4
	vector<Musician> violin1Roster, violin2Roster, violaRoster, celloRoster, bassRoster; // section roster for the gig
public:
	Gig(); // default constructor
	/* Gig() class constructor
	 * Parameters:
	 * 		<1> int - series ID number
	 */
	Gig(int);
	~Gig(); // destructor
	void set_violin1Count(int);
	void set_violin2Count(int);
	void set_violaCount(int);
	void set_celloCount(int);
	void set_bassCount(int);
	int get_violin1Count();
	int get_violin2Count();
	int get_violaCount();
	int get_celloCount();
	int get_bassCount();
};


extern vector<Musician> violin1Section, violin2Section, violaSection, celloSection, bassSection;

#endif /* ORCHESTRA_H_ */
