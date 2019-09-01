/*
 * orchestra.cpp
 *
 *  Contains implementation of functions described in "orchestra.h"
 *  	See header file for explanation of function behaviour
 */

#include "orchestra.h"
#include <iostream>

using namespace std;

Musician::Musician(){ // default class constructor
	mastersScheduled = popsScheduled = kidsScheduled = specialsScheduled = 0;
	idNumber = -1;
}

Musician::~Musician(){

}

void Musician::set_name(string newName){
	name = newName;
}

void Musician::set_id(int number){
	idNumber = number;
}

void Musician::add_masters(){
	mastersScheduled++;
}

void Musician::add_masters(int gigs){
	mastersScheduled += gigs;
}

void Musician::add_pops(){
	popsScheduled++;
}

void Musician::add_pops(int gigs){
	popsScheduled += gigs;
}

void Musician::add_kids(){
	kidsScheduled++;
}

void Musician::add_kids(int gigs){
	kidsScheduled += gigs;
}

void Musician::add_specials(){
	specialsScheduled++;
}

void Musician::add_specials(int gigs){
	specialsScheduled += gigs;
}

void Musician::add_gig(int seriesID){
	if(seriesID == 1)
		add_masters();
	else if(seriesID == 2)
		add_pops();
	else if(seriesID == 3)
		add_specials();
	else if(seriesID == 4)
		add_kids();
}

string Musician::get_name(){
	return name;
}

int Musician::get_masters(){
	return mastersScheduled;
}

int Musician::get_pops(){
	return popsScheduled;
}

int Musician::get_specials(){
	return specialsScheduled;
}

int Musician::get_kids(){
	return kidsScheduled;
}

int Musician::get_total(){
	return mastersScheduled + popsScheduled + specialsScheduled + kidsScheduled;
}

int Musician::get_total(int seriesID){
	if(seriesID == 1) return mastersScheduled;
	else if(seriesID == 2) return popsScheduled;
	else if(seriesID == 3) return specialsScheduled;
	else if(seriesID == 4) return kidsScheduled;
	else{
		cerr << "Invalid series ID!" << endl;
	}
	return -1;
}

int Musician::get_id() const {
	return idNumber;
}

void Musician::operator=(const Musician& original){
	this->name = original.name;
	this->kidsScheduled = original.kidsScheduled;
	this->mastersScheduled = original.mastersScheduled;
	this->popsScheduled = original.popsScheduled;
	this->specialsScheduled = original.specialsScheduled;
	this->idNumber = original.idNumber;
}

Gig::Gig(int gigSeries){
	series = gigSeries;
}

Gig::~Gig(){

}

void Gig::set_violin1Count(int count){
	violin1Roster.resize(count);
}

void Gig::set_violin2Count(int count){
	violin2Roster.resize(count);
}

void Gig::set_violaCount(int count){
	violaRoster.resize(count);
}

void Gig::set_celloCount(int count){
	celloRoster.resize(count);
}

void Gig::set_bassCount(int count){
	bassRoster.resize(count);
}

int Gig::get_violin1Count(){
	return violin1Roster.size();
}

int Gig::get_violin2Count(){
	return violin2Roster.size();
}

int Gig::get_violaCount(){
	return violaRoster.size();
}

int Gig::get_celloCount(){
	return celloRoster.size();
}

int Gig::get_bassCount(){
	return bassRoster.size();
}
