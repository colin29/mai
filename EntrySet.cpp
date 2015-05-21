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

EntrySet::EntrySet(){};

int EntrySet::getSize(){
	return setOfEntries.size();
}

void EntrySet::insert(const Entry& e){
	setOfEntries.push_back(e);

}

void EntrySet::printEntryBank(){
	cout << "Printing out Entry Bank: (# of Entries: " << this->getSize() << ")." << endl;
	cout << "===Start of EntryBank===" << endl;
	for(vector<Entry>::iterator it = setOfEntries.begin(); it != setOfEntries.end(); it++){
		cout << "Title: " << it->getTitle() << "; Definition: " << it->definition << endl;
	}
	cout << "===End of EntryBank===" << endl;
}


//Private Members Functions//
bool EntrySet::entryComp(const Entry& e1, const Entry& e2){
		return e1.title < e2.title;
}


void EntrySet::sort(){
	std::sort(setOfEntries.begin(), setOfEntries.end(), entryComp);
}






