

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

Entry e1{"Physical Object"};
Entry e2{"Representation of Info"};
Entry e3{"Piece of Information"};
Entry e4{"Book (Content)"};
Entry e5{"Book (Physical)"};
Entry e6{"AI (Entity)"};
Entry e7{"Human"};



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


