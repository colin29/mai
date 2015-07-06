
#include <stdexcept>
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

#include "CNoun.h"
#include "Instance.h"
#include "Relation.h"

#include "Storage.h"
#include "exception.h"

#include "test.h" //not meant to be re-used as a whole, but certain functions be useful

using std::string;
using std::vector;
using std::cout;
using std::endl;

using test::print;

// void saveToRelationalTable();
// void loadFromRelationTable();


static Storage storage{}; //not extern-able
StorageReadInterface& storageRead = storage;

int main(){

// init();

test::run();

//===================================start of testing area===================================

{

CNoun foo1{"foo1"};
CNoun foo2{"foo2"};
CNoun foo3{"foo3"};

CNoun doo1{"doo1"};
CNoun doo2{"doo12"};
CNoun doo3{"doo3"};

CNoun goo1{"goo12"};
CNoun goo2{"goo13"};
CNoun goo3{"goo3"};

doo1.addRelation(Relation(doo1, IS_A, foo1));
doo2.addRelation(Relation(doo2, IS_A, foo1));
doo2.addRelation(Relation(doo2, IS_A, foo2));
doo3.addRelation(Relation(doo3, IS_A, foo3));

goo1.addRelation(Relation(goo1, IS_A, goo1));
goo1.addRelation(Relation(goo1, IS_A, goo2));
goo2.addRelation(Relation(goo2, IS_A, goo1));
goo2.addRelation(Relation(goo2, IS_A, goo3));
goo3.addRelation(Relation(goo3, IS_A, goo3));

storage.add(foo1)
	   .add(foo2)
	   .add(foo3)
	   .add(doo1)
	   .add(doo2)
	   .add(doo3)
	   .add(goo1)
	   .add(goo2)
	   .add(goo3);

cout<<storage.getCNoun("foo1").title()<<endl;
cout << test::getAncestors(doo2).size() << endl;
print(test::getAncestors(doo2));

}









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


