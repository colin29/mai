 // warning: include order matters for entry/entryset!
#include "Entry.h"
#include "EntrySet.h"
#include <iostream>
#include <string>
#include <algorithm>

using std::vector;
using std::string;
using std::cout;
using std::endl;



//public functions:

EntrySet::EntrySet(){};

void EntrySet::insert(const Entry& e){
	setOfEntries.push_back(e);
	sort(); //very ineffecient but not a concern any time soon (<10,000 Entries)
}

int EntrySet::getSize() const{
	return setOfEntries.size();
}

void EntrySet::printEntryBank() const{
	cout << "===Start of EntryBank===" << endl;
	int counter = 0;
	for(vector<Entry>::const_iterator it = setOfEntries.begin(); it != setOfEntries.end(); it++){
		cout << "Entry " << counter++ << ":"
			 << "\nTitle: " << it->title() 
			 << "\nTypes: " << it->conceptualType() << " " << it->pluralityType()
			 << endl;
	}
	cout << "===End of EntryBank===" << endl;
}


//private functions:

bool EntrySet::entryComp(const Entry& e1, const Entry& e2){
		return e1.title() < e2.title();
}

void EntrySet::sort(){
	std::sort(setOfEntries.begin(), setOfEntries.end(), entryComp);
}






