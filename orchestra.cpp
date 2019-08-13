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

void Musician::set_available(bool status){
	available = status;
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

bool Musician::get_available(){
	return available;
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
