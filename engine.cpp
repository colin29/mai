

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

using namespace std;

//------------------------------------------------------------------------------------------------------------------
// Class Definitions------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------

class Person{
  
  public:
  	string name;
  	int worth; //not used that often.
  	int closeness;
  	Person(){

  	};
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
static type stringToType(string s){
	if(s=="friend") return TOMO;
	else if(s=="close friend") return SHINYUU;
	else if(s=="family") return KAZOKU;
	else {
		cout << "Error: '" << s << "' is not a recoginzed Relation::type. Using 'friend' as default'." << endl;
		return TOMO;
	}
}
type t; string p1, p2;
Relation(){};
Relation(string p1, string p2, type t) //depicts a two-way relationship between people with names p1 and p2
	: p1(p1)
	, p2(p2)
	, t(t)
	{};
};



class Entry{ //these store Mai's information, like wikipedia articles. They are related, and the way they are related constitutes Mai's understanding.
public:
enum type{THING, ABSTRACT_NOUN}; //"thing" includes both entities and objects. I'm hoping not including them at this level will make the entries more flextible.

private:
string title; //textual definition. Mai usually doesn't have a understanding of these definitions because they are too high level.
type t;
 public:
string definition;
Entry(string s, type t)
	: title(s)
	, t(t)
	{};
string getTitle() const {
	return title;
}
type getType() const{
	return t;
}
};

struct entry_compare{
	bool operator()(const Entry& e1, const Entry& e2){
		return e1.getTitle() < e2.getTitle();
	}
};

class DataEntry{ // Completely different from Entries. The types listed in the class DataEntry  ///lol my english fails me can't describe
	public:
	enum type {PERSON, RELATION, INVALID};
	static type stringToType(string s){
	if(s=="Person") return PERSON;
	else if(s=="Relation") return RELATION;
	else {
		cout << "Error: '" << s << "' is not a recoginzed DataEntry::type. Setting type to INVALID." << endl;
		return INVALID;
	}
}
};


namespace enumTypes{
const string entry[2] = {"THING", "ABSTRACT_NOUN"};
}




//------------------------------------------------------------------------------------------------------------------
//Function Declarations and main------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------


void saveToRelationalTable();
void loadFromRelationTable();
void init();
vector<Person> people;
vector<Relation> relationTable; //relationTable is the program's collection. The relationALtable is a full store on disk.
set<Entry, entry_compare> entryBank;

void printEntryBank();
int main(){
init();


//start of testing area
loadFromRelationTable();

// cout << "Select an Option:"

// Person a("Leo", 10, 1);
// people.push_back(a);
// Relation r("Leo", "Ami", Relation::TOMO);
// relationTable.push_back(r);
Entry e1("Intelligence", Entry::ABSTRACT_NOUN);
e1.definition = "Ability to react meaningfully with a purpose to the input/environment.";
entryBank.insert(e1);
printEntryBank();


// saveToRelationalTable();
//end of testing area
}


//------------------------------------------------------------------------------------------------------------------
//Function Definitions ---------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------

void saveToRelationalTable(){ //overrides the old file, be careful!
cout << "***Saving data to Relational Table on disk (replaces old version)." << endl;
ofstream myfile ("relationalTable.txt");
myfile << ";\n"; //; is the delimiting character used to parse.
if (myfile.is_open())
	{
	for(vector<Person>::iterator it = people.begin(); it != people.end(); it++){
		myfile << "Person: " << it->name << ", " << it-> worth << ", " << it->closeness <<",;\n";  //stores all persons and relations. Do not include the character ';' in any field value. It it used to parse entries."
	}
	for(vector<Relation>::iterator it = relationTable.begin(); it != relationTable.end(); it++){
		myfile << "Relation: " << it->p1 << ", " << it->p2 << ", " << Relation::typeToString(it->t) << ",;\n";
	}
	myfile.close();
}
else cout << "Unable to open file" << endl;
};

void skipWS(istream &is){
	while(is.peek()==' '){is.get();}
}


void loadFromRelationTable(){ //parses line by line
//checks the start string against the  matching a valid entry type (e.g. Person, Relation), then gets the entry by seeking until the next ';' character.
cout << "***Starting to read dataEntries from the RelationalTable" << endl;
ifstream myfile;
myfile.open("relationalTable.txt"); //open a istream
string entryType;
while(myfile){
	myfile.ignore(numeric_limits<streamsize>::max(), ';'); //the text before the first ';' is considered comments and will be ignored.
	myfile.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
	myfile.peek();
	getline(myfile, entryType, ':');  //fyi, getline leaves the string unchanged if it can't read anything.
	if(!myfile){ cout << "Reached EOF. Ending." << endl; break;}
	cout << "entryType parsed: " << entryType << endl;
	DataEntry::type type = DataEntry::stringToType(entryType);
	
	switch(type){
		case DataEntry::PERSON: 
			{
			Person p; string temp;
			skipWS(myfile); //skip any whitespace
			getline(myfile, p.name, ',');
			skipWS(myfile);
			getline(myfile, temp, ','); p.worth = atoi(temp.c_str());
			skipWS(myfile);
			getline(myfile, temp, ','); p.closeness = atoi(temp.c_str());
			//cout << "adding a person to local chart." << endl;
			cout <<"peek: {" << (char) (myfile.peek()) << "}" << endl; //debug
			people.push_back(p);
			break;
			}
		case DataEntry::RELATION:
			{
			Relation r; string temp;
			skipWS(myfile);
			getline(myfile, r.p1, ',');
			skipWS(myfile);
			getline(myfile, r.p2, ',');
			skipWS(myfile);
			getline(myfile, temp, ','); r.t = (Relation::stringToType(temp));
			relationTable.push_back(r); //In the future I might introduce error handling to not load an entry if it fails, but w/e.
			break;
			}	
		default:
		cout << "Error: entryType: '" << entryType <<"' not recognized. Skipping entry (Caution: The next valid entry may be skipped as a result.)." << endl;
	}
}
cout << "Finished loading data from RelationalTable" << endl;
}

void printEntryBank(){
	cout << "Printing out Entry Bank: (# of Entries: " << entryBank.size() << ")." << endl;
	cout << "===Start of EntryBank===" << endl;
	for(set<Entry>::iterator it = entryBank.begin(); it != entryBank.end(); it++){
		cout << "Title: " << it->getTitle() << "; Definition: " << it->definition << endl;
	}
	cout << "===End of EntryBank===" << endl;
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


