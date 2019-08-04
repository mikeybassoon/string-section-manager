/*
 * orchestra.cpp
 *
 *  Created on: Aug 4, 2019
 *      Author: michaelmacaulay
 */

#include "orchestra.h"
#include <iostream>

using namespace std;

Musician::Musician(){ // default class constructor
	mastersScheduled = popsScheduled = kidsScheduled = specialsScheduled = 0;
}

Musician::~Musician(){

}

void Musician::set_title(string newTitle){
	title = newTitle;
}

void Musician::set_name(string newName){
	name = newName;
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

string Musician::get_title(){
	return title;
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

Gig::Gig(string gigSeries, string gigDate){
	series = gigSeries;
	date = gigDate;
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
