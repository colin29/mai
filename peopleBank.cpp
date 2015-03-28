#include <string>
#include <vector>
#include <fstream>
#include <limits> 
#include <stdlib.h> 
#include <sstream>
#include <iostream>

using std::string;
using std::vector;
using std::cout;
using std::endl;
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

//------------------------------------------------------------------------------------------------------------------
//Function Definitions ---------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------
vector<Person> people;
vector<Relation> relationTable; //relationTable is the program's collection. The relationALtable is a full store on disk.

void saveRelTableToFile(){ //overrides the old file, be careful!
cout << "***Saving data to Relational Table on disk (replaces old version)." << endl;
std::ofstream myfile ("relationalTable.txt");
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
}

void skipWS(std::istream &is){
  while(is.peek()==' '){is.get();}
}


void loadFromRelationTable(){ //parses line by line
//checks the start string against the  matching a valid entry type (e.g. Person, Relation), then gets the entry by seeking until the next ';' character.
cout << "***Starting to read dataEntries from the RelationalTable" << endl;
std::ifstream myfile;
myfile.open("relationalTable.txt"); //open a istream
string entryType;
while(myfile){
  myfile.ignore(std::numeric_limits<std::streamsize>::max(), ';'); //the text before the first ';' is considered comments and will be ignored.
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

int main(){

return 0;
}