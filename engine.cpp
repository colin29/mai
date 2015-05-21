

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

#include "engine.h" //empty for now
#include "EntrySet.h"
#include "Entry.h" //depends if the engine file will need to manipluate entries directly

using std::string;
using std::vector;
using std::cout;
using std::endl;

// void saveToRelationalTable();
// void loadFromRelationTable();

EntrySet entryBank;
int main(){
init();


//===================================start of testing area===================================
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
//===================================end of testing area===================================
}


//------------------------------------------------------------------------------------------------------------------
//Non-main Function Definitions ---------------------------------------------------------------------------------------------
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


