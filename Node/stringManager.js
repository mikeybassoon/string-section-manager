var fs = Require('fs');

function Musician(){
	// gigs this musician scheduled for, by series
	this.popsGigs;
	this.mwGigs;
	this.specialsGigs;
	this.familyGigs;
}

function Section() {
	this.musicians = new Array();
	this.Sort = function(series) {
		if(series === 'pops')
			musicians.sort(function(a,b){return a.popsGigs - b.popsGigs});
		else if(series === 'mw')
			musicians.sort(function(a,b){retun a.mwGigs - b.mwGigs});
		else if(series === 'specials')
			musicians.sort(function(a,b){return a.mwGigs - b. mwGigs});
		else if(series === 'family')
			musicians.sort(function(a,b){return a.familyGigs - b.familyGigs});
		else
			console.log('Invalid series passed to sort function: ' + series);
	}
}

var vln1section = new Section();

let vln2section = vln1section;

let vlaSection = vln1section;

let vclSection = vln1section;

let cbSection = vln1section;

