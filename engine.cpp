

#include <string>
#include <vector>
#include <utility>  
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <stdexcept> //??

using namespace std;

//------------------------------------------------------------------------------------------------------------------
// Class Definitions------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------

class Person{
  
  public:
  	string name;
  	int worth; //not used that often.
  	int closeness;
  	Person(string iName,int iWorth, int iCloseness)
  	: name(iName)
  	, worth(iWorth)
  	, closeness(iCloseness) //Mai's estimation on how close they are.
  	{};
    //closeness
 //   static const int SIZE = 10;      // initial size of the array
  	string toString(){
	std::ostringstream oss;
	oss << "name: " << name <<", worth: " << worth << ", closeness: " << closeness;
	return oss.str();	
	}
};


class Relation{
public:
enum type {TOMO, SHINYUU, KAZOKU};  //tomo stands for friend, which I can't use because its a keyword}

static string typeToString(type t){
	switch(t){
		case TOMO: return "friend"; break;
		case SHINYUU: return "close friend"; break;
		case KAZOKU: return "family"; break;
	}
}
string StringToType(){ //what do to do on error? Ignore the relation (don't load it) and print out an error

}
type t; string p1, p2;
Relation(string p1, string p2, type t) //depicts a two-way relationship between people with names p1 and p2
	: p1(p1)
	, p2(p2)
	, t(t)
	{};
};

//------------------------------------------------------------------------------------------------------------------
//Function Declarations and main------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------


void saveToRelationalTable();
void loadFromRelationTable();
void init();
vector<Person> people;
vector<Relation> relationTable; //relationTable is the program's collection. The relationALtable is a full store on disk.

int main(){
init();

//start of testing area
Person a("Leo", 10, 1);
people.push_back(a);
cout << a.toString() << endl;
Relation r("Leo", "Ami", Relation::TOMO);
relationTable.push_back(r);
saveToRelationalTable();
//end of testing area
}


//------------------------------------------------------------------------------------------------------------------
//Function Definitions ---------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------

void saveToRelationalTable(){ //overrides the old file, be careful!
cout << "Saving data to Relational Table on disk (replaces old version)." << endl;
ofstream myfile ("relationalTable.txt");
if (myfile.is_open())
	{
	for(vector<Person>::iterator it = people.begin(); it<people.end(); it++){
		myfile << "Person: " << it->name << ", " << it-> worth << ", " << it->closeness <<";\n";  //stores all persons and relations. Do not include the character ';' in any field value. It it used to parse entries."
	}
	for(vector<Relation>::iterator it = relationTable.begin(); it<relationTable.end(); it++){
		myfile << "Relation: " << it->p1 << ", " << it->p2 << ", " << Relation::typeToString(it->t) << ";\n";
	}
	
	myfile << "This is another line.\n";
	myfile.close();
}
else cout << "Unable to open file" << endl;
};
void loadFromRelationTable(){ //parses line by line
//checks the start string against the  matching a valid entry type (e.g. Person, Relation), then gets the entry by seeking until the next ';' character.

	//TODO, implement 
}

//------------------------------------------------------------------------------------------------------------------
//Make-shift hardcoded Storage--------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------

void init(){ //initilizes all the messages for us to use
string m1 = "Mai's meaning of existence is to learn, understand, and make guesses about the world.";
string m2 = "Mai dreams of being able to simulate my own very simplified world.";

string m3 = "Mai is not generating these statments. Mai is not designed to parse text. Mai is also not able to make these deductions on Mai's own. In the future, Mai may be programmed to be able to use limited speech sythensis in order to express Mai's thoughts.";
string m4 = "Mai's goal is not to simulate and act according to human emotions, though Mai will be aware of human emotions and about what affect they may have. Mai uses models from humans (mostly Mai's creator). These models are made to be reasonable and similiar to the ones a human might plausibly use. (Mai's creator often uses his own models as a reference.)";

}




