

#include <string>
#include <vector>
#include <utility>  
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <stdexcept> //??
#include <limits>
#include <stdlib.h>  
#include <set>
#include <algorithm>

using namespace std;

//------------------------------------------------------------------------------------------------------------------
// Class Definitions------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------

class Entry{ //these store Mai's information, like wikipedia articles. They are related, and the way they are related constitutes Mai's understanding.
//fields//
public:
enum type{THING, ABSTRACT_NOUN}; //"thing" includes both entities and objects. I'm hoping not including them at this level will make the entries more flextible.
type t;

private:
string title; //textual definition. Mai usually doesn't have a understanding of these definitions because they are too high level.


//member functions//
 public:
 	friend bool entryComp(const Entry&, const Entry&);
	string definition;
	Entry(string s, type t)
		: title(s)
		, t(t)
		{};
	string getTitle() const {
		return title;
	}
};

namespace enumTypes{
const string entry[2] = {"THING", "ABSTRACT_NOUN"};
}

bool entryComp(const Entry& e1, const Entry& e2){
		return e1.title < e2.title;
}

class EntrySet{
//Class Invariants:  setOfEntries holds a ordered set of Entries. Entries are sorted by title A-Z, and each entry has a unique title.

	private:
	vector<Entry> setOfEntries;

	public:
	EntrySet(){};
	int getSize(){
		return setOfEntries.size();
	}

	void insert(const Entry& e){
		setOfEntries.push_back(e);

	}

	void printEntryBank(){
	cout << "Printing out Entry Bank: (# of Entries: " << this->getSize() << ")." << endl;
	cout << "===Start of EntryBank===" << endl;
	for(vector<Entry>::iterator it = setOfEntries.begin(); it != setOfEntries.end(); it++){
		cout << "Title: " << it->getTitle() << "; Definition: " << it->definition << endl;
	}
	cout << "===End of EntryBank===" << endl;
}
	

	private:
	
	void sort(){
		std::sort(setOfEntries.begin(), setOfEntries.end(), entryComp);
	}

	

};


//------------------------------------------------------------------------------------------------------------------
//Function Declarations and main------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------


// void saveToRelationalTable();
// void loadFromRelationTable();
void init();


EntrySet entryBank;
int main(){
init();


//start of testing area
//loadFromRelationTable();

// cout << "Select an Option:"

// Person a("Leo", 10, 1);
// people.push_back(a);
// Relation r("Leo", "Ami", Relation::TOMO);
// relationTable.push_back(r);
Entry e1("Intelligence", Entry::ABSTRACT_NOUN);
e1.definition = "Ability to react meaningfully with a purpose to the input/environment.";
entryBank.insert(e1);
entryBank.printEntryBank();

// saveToRelationalTable();
//end of testing area
}


//------------------------------------------------------------------------------------------------------------------
//Function Definitions ---------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------




//------------------------------------------------------------------------------------------------------------------
//Make-shift hardcoded Storage--------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------

void init(){ //initilizes all the messages for us to use
string m1 = "Mai's meaning of existence is to learn, understand, and make guesses about the world.";
string m2 = "Mai dreams of being able to simulate my own very simplified world.";

string m3 = "Mai is not generating these statments. Mai is not designed to parse text. Mai is also not able to make these deductions on Mai's own. In the future, Mai may be programmed to be able to use limited speech sythensis in order to express Mai's thoughts.";
string m4 = "Mai's goal is not to simulate and act according to human emotions, though Mai will be aware of human emotions and about what affect they may have. Mai uses models from humans (mostly Mai's creator). These models are made to be reasonable and similiar to the ones a human might plausibly use. (Mai's creator often uses his own models as a reference.)";
	
}


