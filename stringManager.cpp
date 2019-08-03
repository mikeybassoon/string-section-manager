/* stringManager.cpp Program Description
 *
 * Created on: 	Feb 18, 2019
 *  			Last revised July 11, 2019
 *
 * Author: 		Michael Macaulay
 *
 * Problem:		Generate string section rosters for a professional orchestra's performances
 * 					- Section members will rotate according to rotation rules specified below
 * 				Track amount of work assigned to each orchestra member
 * 					- For each member, number of gigs is tracked for each subscription series
 * 						(Masterworks, Pops, Specials, Kids)
 *
 * 				Rotation rules:
 * 					- Principal and assistant principal musicians are user selected
 * 					- Remaining slots are filled in priority order
 * 					- Musicians who are scheduled for the fewest gigs on this particular series have priority
 * 					- In case of tie, musician scheduled for fewest total gigs on season has priority
 *
 * Major issues:
 *				cin buffer enters fail state when user enters wrong data type on a selection menu
 *					- missed keystroke breaks entire program
 *				added spaces to output file that don't totally make sense
 *				Assumes no more than 20 musicians per section - cannot dynamically add more
 *
 * Future goals:
 *
 *
 * Main Algorithm Description:
 * 				Read orchestra roster file data into variables
 * 				Prompt user to enter key data on program to be created
 * 				Populate each section
 * 					User selects principal and assistant principal
 * 					Remaining spots are filled with priority given to musicians who have performed the
 * 						fewest gigs on this particular subscription series this season
 * 					In case of a tie, musician who is scheduled for fewest total gigs this season across
 * 						all series will be given priority
 * 					If no orchestra member is available to fill an empty chair, it will be filled by a
 * 						sub or extra
 * 				Generate a text file for the program containing the string count and roster
 * 				Generate a new orchestra roster text file containing updated gig counts for each musician
 *
 */

/* List of program return codes
 * RETURN:	0	Code executed succesfully
 * 			4	Output file stream failure (unexpected)
 * 			5 	Input file stream failure (unexpected)
 * 			6	Input file formatting error
 * 			9	User chose to end program
 *
 */

#include "orchestra.h"
#include <iostream> // require user input tools for terminal interface
#include <fstream> // require file input/output to read and store data

using namespace std;

int main(){

	ifstream inputFile;
	ofstream outputFile;

	int userSelection; // holds user choice on menus
	int seriesIdentifier; // numeric ID corresponding to a specific subscription series
	bool validSelection; // used to error-check user-input menu selections

	string seriesName; // e.g. "Masterworks"
	string concertName; // user-input name for each individual concert


	// declare arrays to store data on musicians of each section
	string violin1Name[20]; bool violin1Available[20];
	int violin1GigsScheduled[4][20]; int violin1TotalScheduled[20];

	string violin2Name[20]; bool violin2Available[20];
	int violin2GigsScheduled[4][20]; int violin2TotalScheduled[20];

	string violaName[20]; bool violaAvailable[20];
	int violaGigsScheduled[4][20]; int violaTotalScheduled[20];

	string celloName[20]; bool celloAvailable[20];
	int celloGigsScheduled[4][20]; int celloTotalScheduled[20];

	string bassName[20]; bool bassAvailable[20];
	int bassGigsScheduled[4][20]; int bassTotalScheduled[20];

	cout << "STRING SECTION MANAGER" << endl << endl;

bool continueProgram = true; // program will continue running by default until user terminates it
while (continueProgram == true) { // loop of main algorithm

	cout << "Reading orchestra roster file . . . " << endl << endl;

	// since we do not know how many musicians are on the roster in advance,
	// initialize all musician statuses to unavailable
	MakeUnavailable(violin1Available, 20);
	MakeUnavailable(violin2Available, 20);
	MakeUnavailable(violaAvailable, 20);
	MakeUnavailable(celloAvailable, 20);
	MakeUnavailable(bassAvailable, 20);

	// declare variables to store number of musicians under contract with the orchestra
	// initialize to zero
	int vln1InOrchestra = 0;
	int vln2InOrchestra = 0;
	int vlaInOrchestra = 0;
	int vclInOrchestra = 0;
	int cbInOrchestra = 0;

	// declare variable to store number of musicians needed for the gig currently being populated
	// initialize to zero
	int vln1OnGig = 0;
	int vln2OnGig = 0;
	int vlaOnGig = 0;
	int vclOnGig = 0;
	int cbOnGig = 0;

	// connect to orchestra roster file and check input stream for errors
	inputFile.open("orchestraRoster.txt");
		if(!inputFile){
			cout << "ERROR: Cannot connect to input file \"orchestraRoster.txt\", ending program.";
			return 5;
		}


	string instrument; // used for temporary storage of instrument name while reading from the file
	string musicianName; // holds the musician's name

	int statsArray[HOW_MANY_SERIES]; // used to temporarily hold how many of each gig the musician has done
		// read all data from the orchestra roster file
		while(true){ // until entire file is read
			inputFile >> instrument; 	// store instrument
			for(int i = 0; i < HOW_MANY_SERIES; i++) inputFile >> statsArray[i]; // store the four integers representing gigs/series
			getline(inputFile, musicianName, '\n');



			if (instrument == "vln1"){
				int j = vln1InOrchestra; // int j is a counter that increments as musicians are added

				// connect key information on musician to numeric identifier
				violin1Name[j] = musicianName;
				violin1Available[j] = true;
				for(int k = 0; k < HOW_MANY_SERIES; k++){
					violin1GigsScheduled[k][j] = statsArray[k];
				}
				int temporaryVar = SumOfArray(violin1GigsScheduled[j], HOW_MANY_SERIES);
				violin1TotalScheduled[j] = temporaryVar;
				vln1InOrchestra++;
			}
			else if (instrument == "vln2"){
				int j = vln2InOrchestra;

				// connect key information on musician to numeric identifier
				violin2Name[j] = musicianName;
				violin2Available[j] = true;
				for(int k = 0; k < HOW_MANY_SERIES; k++){
					violin2GigsScheduled[k][j] = statsArray[k];
				}
				int temporaryVar = SumOfArray(violin2GigsScheduled[j], HOW_MANY_SERIES);
				violin2TotalScheduled[j] = temporaryVar;
				vln2InOrchestra++;
			}
			else if (instrument == "vla"){
				int j = vlaInOrchestra;

				// connect key information on musician to numeric identifier
				violaName[j] = musicianName;
				violaAvailable[j] = true;
				for(int k = 0; k < HOW_MANY_SERIES; k++){
					violaGigsScheduled[k][j] = statsArray[k];
				}
				int temporaryVar = SumOfArray(violaGigsScheduled[j], HOW_MANY_SERIES);
				violaTotalScheduled[j] = temporaryVar;
				vlaInOrchestra++;
			}
			else if (instrument == "vcl"){
				int j = vclInOrchestra;

				// connect key information on musician to numeric identifier
				celloName[j] = musicianName;
				celloAvailable[j] = true;
				for(int k = 0; k < HOW_MANY_SERIES; k++){
					celloGigsScheduled[k][j] = statsArray[k];
				}
				int temporaryVar = SumOfArray(celloGigsScheduled[j], HOW_MANY_SERIES);
				celloTotalScheduled[j] = temporaryVar;
				vclInOrchestra++;
			}
			else if (instrument == "cb"){
				int j = cbInOrchestra;

				// connect key information on musician to numeric identifier
				bassName[j] = musicianName;
				bassAvailable[j] = true;
				for(int k = 0; k < HOW_MANY_SERIES; k++){
					bassGigsScheduled[k][j] = statsArray[k];
				}
				int temporaryVar = SumOfArray(bassGigsScheduled[j], HOW_MANY_SERIES);
				bassTotalScheduled[j] = temporaryVar;
				cbInOrchestra++;
			}
			else{
				cout << "ERROR: Invalid input! Check that input file is correctly formatted." << endl;
				cout << "Ending program.";
				return 6;
			}

			if (inputFile.eof()) break;
		} // all data read from file
	inputFile.close();

		cout << "What type of program would you like to create?" << endl;
		cout << "1. Masterworks" << endl;
		cout << "2. Pops" << endl;
		cout << "3. Kids" << endl;
		cout << "4. Specials" << endl;
		cout << "Please enter your selection: ";
		cin >> userSelection;
		//!! error check the input

		switch(userSelection) { // store concert series information based on user selection
			case 1: seriesName = "Masterworks";
					seriesIdentifier = 0;
					break;
			case 2: seriesName = "Pops";
					seriesIdentifier = 1;
					break;
			case 3: seriesName = "Kids";
					seriesIdentifier = 2;
					break;
			case 4: seriesName = "Specials";
					seriesIdentifier = 3;
					break;
		}

		// prompt user for concert name
		cout << endl << "Please enter a name for the concert (can be a number, no spaces please): ";
			cin >> concertName;
			//!! error check concertName

		// create a filename for the concert roster output file
		string filename = seriesName + concertName + ".txt";
		outputFile.open(filename); // create output file for concert roster

		// declare variables to hold string counts
		int vln1Count, vln2Count, vlaCount, vclCount, cbCount;

		// prompt user for string count
		cout << endl << endl << "How many first violins are on this program? ";
			cin >> vln1Count;
		cout << endl << "How many second violins are on this program? ";
			cin >> vln2Count;
		cout << endl << "How many violas are on this program? ";
			cin >> vlaCount;
		cout << endl << "How many celli are on this program? ";
			cin >> vclCount;
		cout << endl << "How many basses are on this program? ";
			cin >> cbCount;

		// print program name to output file
		outputFile << "Program - " << seriesName + " " + concertName << endl;
		outputFile << "String count: " << vln1Count << " " << vln2Count << " " << vlaCount
				<< " " << vclCount << " " << cbCount << endl << endl;

		int x = 0; // user selection variable
		// select 1st violins
			outputFile << "Violin 1" << endl << endl;
		cout << "Violin 1" << endl;
		cout << "Please select a concertmaster:" << endl;
			PrintAvailableNames(violin1Name, violin1Available, 20);
		cin >> x;
			violin1Available[x] = false;
			outputFile << "Concertmaster " << violin1Name[x] << endl;
			vln1OnGig++;
			violin1GigsScheduled[seriesIdentifier][x]++;	// increment the gig counter

		if(vln1Count > vln1OnGig){
			cout << "Please select an assistant concertmaster:" << endl;
			PrintAvailableNames(violin1Name, violin1Available, 20);
		cin >> x;
			violin1Available[x] = false;
			outputFile << "Assistant Concertmaster " << violin1Name[x] << endl;
			vln1OnGig++;
			violin1GigsScheduled[seriesIdentifier][x]++;
		}

		if(vln1Count > vln1OnGig){
			bool exit = false;
			while(!exit){
				cout << "Are any of these musicians unavailable for the gig?" << endl;
				PrintAvailableNames(violin1Name, violin1Available, 20);
				cout << "25. Nope, everyone's available!" << endl;
				cin >> x;
				if(x >= 0 && x <= 19) violin1Available[x] = false;
				else if (x == 25) exit = true;
			}
			while(vln1Count > vln1OnGig){
				int index = FindLowest(violin1GigsScheduled[seriesIdentifier], violin1TotalScheduled, violin1Available, 20);
				if (index == -1){ // if FindLowest function failed to find any available musicians
					outputFile << "SUB/EXTRA MUSICIAN" << endl;
					vln1OnGig++;
				}
				else if (index != -1) { // if a valid value was returned
					violin1Available[index] = false;
					outputFile << violin1Name[index] << endl;
					violin1GigsScheduled[seriesIdentifier][index]++;
					vln1OnGig++;
				}
			} // exit loop when all slots in section are filled
		} // if violin 1 section filled, proceed

		// select 2nd violins
			outputFile << endl << "Violin 2" << endl << endl;
		cout << "Violin 2" << endl;
		cout << "Please select a principal:" << endl;
			PrintAvailableNames(violin2Name, violin2Available, 20);
		cin >> x;
			violin2Available[x] = false;
			outputFile << "Principal " << violin2Name[x] << endl;
			vln2OnGig++;
			violin2GigsScheduled[seriesIdentifier][x]++;	// increment the gig counter

		if(vln2Count > vln2OnGig){
			cout << "Please select an assistant principal:" << endl;
			PrintAvailableNames(violin2Name, violin2Available, 20);
		cin >> x;
			violin2Available[x] = false;
			outputFile << "Assistant Principal " << violin2Name[x] << endl;
			vln2OnGig++;
			violin2GigsScheduled[seriesIdentifier][x]++;
		}

		if(vln2Count > vln2OnGig){
			bool exit = false;
			while(!exit){
				cout << "Are any of these musicians unavailable for the gig?" << endl;
				PrintAvailableNames(violin2Name, violin2Available, 20);
				cout << "25. Nope, everyone's available!" << endl;
				cin >> x;
				if(x >= 0 && x <= 19) violin2Available[x] = false;
				else if (x == 25) exit = true;
			}
			while(vln2Count > vln2OnGig){
				int index = FindLowest(violin2GigsScheduled[seriesIdentifier], violin2TotalScheduled, violin2Available, 20);
				if (index == -1){ // if FindLowest function failed to find any available musicians
					outputFile << "SUB/EXTRA MUSICIAN" << endl;
					vln2OnGig++;
				}
				else if (index != -1) { // if a valid value was returned
					violin2Available[index] = false;
					outputFile << violin2Name[index] << endl;
					violin2GigsScheduled[seriesIdentifier][index]++;
					vln2OnGig++;
				}
			} // exit loop when all slots in section are filled
		} // if violin 2 section filled, proceed

		// select violas
			outputFile << endl << "Viola" << endl << endl;
		cout << "Viola" << endl;
		cout << "Please select a principal:" << endl;
			PrintAvailableNames(violaName, violaAvailable, 20);
		cin >> x;
			violaAvailable[x] = false;
			outputFile << "Principal " << violaName[x] << endl;
			vlaOnGig++;
			violaGigsScheduled[seriesIdentifier][x]++;	// increment the gig counter

		if(vlaCount > vlaOnGig){
			cout << "Please select an assistant principal:" << endl;
			PrintAvailableNames(violaName, violaAvailable, 20);
		cin >> x;
			violaAvailable[x] = false;
			outputFile << "Assistant Principal " << violaName[x] << endl;
			vlaOnGig++;
			violaGigsScheduled[seriesIdentifier][x]++;
		}

		if(vlaCount > vlaOnGig){
			bool exit = false;
			while(!exit){
				cout << "Are any of these musicians unavailable for the gig?" << endl;
				PrintAvailableNames(violaName, violaAvailable, 20);
				cout << "25. Nope, everyone's available!" << endl;
				cin >> x;
				if(x >= 0 && x <= 19) violaAvailable[x] = false;
				else if (x == 25) exit = true;
			}
			while(vlaCount > vlaOnGig){
				int index = FindLowest(violaGigsScheduled[seriesIdentifier], violaTotalScheduled, violaAvailable, 20);
				if (index == -1){ // if FindLowest function failed to find any available musicians
					outputFile << "SUB/EXTRA MUSICIAN" << endl;
					vlaOnGig++;
				}
				else if (index != -1) { // if a valid value was returned
					violaAvailable[index] = false;
					outputFile << violaName[index] << endl;
					violaGigsScheduled[seriesIdentifier][index]++;
					vlaOnGig++;
				}
			} // exit loop when all slots in section are filled
		} // if viola section filled, proceed


		// select cellos
			outputFile << endl << "Cello" << endl << endl;
		cout << "Cello" << endl;
		cout << "Please select a principal:" << endl;
			PrintAvailableNames(celloName, celloAvailable, 20);
		cin >> x;
			celloAvailable[x] = false;
			outputFile << "Principal " << celloName[x] << endl;
			vclOnGig++;
			celloGigsScheduled[seriesIdentifier][x]++;	// increment the gig counter

		if(vclCount > vclOnGig){
			cout << "Please select an assistant principal:" << endl;
			PrintAvailableNames(celloName, celloAvailable, 20);
		cin >> x;
			celloAvailable[x] = false;
			outputFile << "Assistant Principal " << celloName[x] << endl;
			vclOnGig++;
			celloGigsScheduled[seriesIdentifier][x]++;
		}

		if(vclCount > vclOnGig){
			bool exit = false;
			while(!exit){
				cout << "Are any of these musicians unavailable for the gig?" << endl;
				PrintAvailableNames(celloName, celloAvailable, 20);
				cout << "25. Nope, everyone's available!" << endl;
				cin >> x;
				if(x >= 0 && x <= 19) celloAvailable[x] = false;
				else if (x == 25) exit = true;
			}
			while(vclCount > vclOnGig){
				int index = FindLowest(celloGigsScheduled[seriesIdentifier], celloTotalScheduled, celloAvailable, 20);
				if (index == -1){ // if FindLowest function failed to find any available musicians
					outputFile << "SUB/EXTRA MUSICIAN" << endl;
					vclOnGig++;
				}
				else if (index != -1) { // if a valid value was returned
					celloAvailable[index] = false;
					outputFile << celloName[index] << endl;
					celloGigsScheduled[seriesIdentifier][index]++;
					vclOnGig++;
				}
			} // exit loop when all slots in section are filled
		} // if cello section filled, proceed


		// select basses
			outputFile << endl << "Bass" << endl << endl;
		cout << "Bass" << endl;
		cout << "Please select a principal:" << endl;
			PrintAvailableNames(bassName, bassAvailable, 20);
		cin >> x;
			bassAvailable[x] = false;
			outputFile << "Principal " << bassName[x] << endl;
			cbOnGig++;
			bassGigsScheduled[seriesIdentifier][x]++;	// increment the gig counter

		if(cbCount > cbOnGig){
			cout << "Please select an assistant principal:" << endl;
			PrintAvailableNames(bassName, bassAvailable, 20);
		cin >> x;
			bassAvailable[x] = false;
			outputFile << "Assistant Principal " << bassName[x] << endl;
			cbOnGig++;
			bassGigsScheduled[seriesIdentifier][x]++;
		}

		if(cbCount > cbOnGig){
			bool exit = false;
			while(!exit){
				cout << "Are any of these musicians unavailable for the gig?" << endl;
				PrintAvailableNames(bassName, bassAvailable, 20);
				cout << "25. Nope, everyone's available!" << endl;
				cin >> x;
				if(x >= 0 && x <= 19) bassAvailable[x] = false;
				else if (x == 25) exit = true;
			}
			while(cbCount > cbOnGig){
				int index = FindLowest(bassGigsScheduled[seriesIdentifier], bassTotalScheduled, bassAvailable, 20);
				if (index == -1){ // if FindLowest function failed to find any available musicians
					outputFile << "SUB/EXTRA MUSICIAN" << endl;
					cbOnGig++;
				}
				else if (index != -1) { // if a valid value was returned
					bassAvailable[index] = false;
					outputFile << bassName[index] << endl;
					bassGigsScheduled[seriesIdentifier][index]++;
					cbOnGig++;
				}
			} // exit loop when all slots in section are filled
		} // if bass section filled, proceed

		outputFile.close(); // once selection process is complete for all sections, close the concert roster file

		outputFile.open("orchestraRoster.txt"); //connect output file buffer to orchestraRoster.txt
			// print out updated roster w/ stats to file
			// violin 1
			for(int i = 0; i < vln1InOrchestra; i++){
				outputFile << "vln1 ";
				for(int j = 0; j < HOW_MANY_SERIES; j++) outputFile << violin1GigsScheduled[j][i] << " ";
				outputFile << violin1Name[i] << endl;
			}
			// violin 2
			for(int i = 0; i < vln2InOrchestra; i++){
				outputFile << "vln2 ";
				for(int j = 0; j < HOW_MANY_SERIES; j++) outputFile << violin2GigsScheduled[j][i] << " ";
				outputFile << violin2Name[i] << endl;
			}
			// viola
			for(int i = 0; i < vlaInOrchestra; i++){
				outputFile << "vla ";
				for(int j = 0; j < HOW_MANY_SERIES; j++) outputFile << violaGigsScheduled[j][i] << " ";
				outputFile << violaName[i] << endl;
			}
			// cello
			for(int i = 0; i < vclInOrchestra; i++){
				outputFile << "vcl ";
				for(int j = 0; j < HOW_MANY_SERIES; j++) outputFile << celloGigsScheduled[j][i] << " ";
				outputFile << celloName[i] << endl;
			}
			// bass
			for(int i = 0; i < cbInOrchestra; i++){
				outputFile << "cb ";
				for(int j = 0; j < HOW_MANY_SERIES; j++) outputFile << bassGigsScheduled[j][i] << " ";
				outputFile << bassName[i] << endl;
			}
		outputFile.close();

		cout << "We're all done! Roster created for " << seriesName << " " << concertName << "." << endl;
		cout << "To create a new roster, enter 1. To end the program, enter 0. ";

		validSelection = true; // set selection flag to true by default
		do {
			cin >> userSelection;
				if (userSelection == 1) cout << endl << "Creating new roster . . . " << endl;
				else if (userSelection == 0) continueProgram = false;
				else {
					validSelection = false;
					cout << "Invalid selection, please enter 1 or 0: ";
				}
		} while (validSelection == false);
	} // if user has selected "create new roster" the program repeats
	cout << "Ending program.";
	return 0;
}
