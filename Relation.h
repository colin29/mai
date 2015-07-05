#ifndef MAI_RELATION_H
#define MAI_RELATION_H

#include <string>
#include <vector>

class CNoun; //using forward declaration here avoids circular dependency in headers
class Instance;

//flag class definitions
/*
I chose to have the class lower case because I wanted to use the more widely used global variables to look like flags, and also stand out.
*/
class Is_a{
};
class Has_a{
};
class Has_some{ 
};

extern Is_a IS_A;
extern Has_a HAS_A;
extern Has_some HAS_SOME;

enum class RelType{INHERITANCE1 = 0, INHERITANCE2 =1};


enum class Inher1 {CHILD, PARENT};
enum class Inher2 {CHILD, PARENT};



class Relation{

public:

/*Constructors are declared in same order as RelType*/
Relation(CNoun, Is_a, CNoun); //INHERITANCE1
Relation(Instance, Is_a, CNoun); //INHERITANCE2, etc.



/*
As a rule, check functions that return a bool leave the throwing up to the caller, unless something stops themself from terminating properly.
*/
/*
For reltypes such as IS A, for a relation like "Bob IS_A Human", the relations refers to Bob, and only Bob.

For other reltypes, this is TBD.
*/
bool checkRefersToCNoun(std::string) const;
bool checkRefersToInstance(std::string) const;


//Getter functions

const RelType relType() const;

/*
getContent provides the Relation with each part converted to string. This is the usual way for other modules to parse Relations.
The format of the strings is the same as in the vector<string> mContent.
Caution: Other components should decipher a Relation's type through the relType, not by matching Relator strings. Relator strings are for output, with their point of control being Relation.cpp only.
*/
const std::vector<std::string>& getContent() const;





/*
getTarget returns the name (with type e.g. CNoun::Human) of the Entry it's getting.
use the i1, i2 enums for the second parameter.
*/
std::string getTarget(Inher1) const;  
std::string getTarget(Inher2) const;



/*
toString returns the string representation of the Relation, which is close to natural langauge. Useful for human eyes.
*/
std::string toString() const;


private:

/*
assertRelation makes makes several asserts checking that the Relation looks valid. Call it at the end of constructors which seem sketchy.
assertRelation will throw InvalidDataException the Relation fails the check.
*/
static void assertRelation(const Relation&);
std::string getTarget(RelType reltype, int enumSelection) const;

//Data Members:
//mContent, mRelType, memberList: should not be modified after initialization, except when replacing the whole object
/*
INVARIANT: mContent contains a list-of-strings representation of the Relation.
-Entries are prefixed by their type: e.g. "Instance::Bob"
-Relators (eg. IS_A, HAS_A) are converted to all upper-case strings (e.g. "IS_A", "HAS_A").
INVARIANT: contains at least 1 element, an entry in the first value.
*/
std::vector<std::string> mContent;
RelType mRelType;

/*
targetTable: used to convert from relType num + member number to index of item in mContent.
*/
static const int targetTable[2][2]; 




//String conversion tables:



};


#endif