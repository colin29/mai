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

enum RelType{INHERITANCE1 = 0, INHERITANCE2 =1};

class Relation{

public:

/*Constructors are declared in same order as RelType*/
Relation(CNoun, Is_a, CNoun); //INHERITANCE1
Relation(Instance, Is_a, CNoun); //INHERITANCE2, etc.


/*
getContent provides the Relation with each part converted to string. This is the usual way for other modules to parse Relations.
Note: Entries are prefixed by their type: e.g. "Instance::Bob"
Note: Relators (eg. IS_A, HAS_A) are converted to all upper-case strings (e.g. "IS_A", "HAS_A").
Caution: Other components should decipher a Relation's type through the relType, not by matching Relator strings. Relator strings are for output, with their point of control being Relation.cpp only.
*/
std::vector<std::string> getContent() const;
/*
toString returns the string representation of the Relation, which is close to natural langauge. Useful for human eyes.
*/
std::string toString() const;

bool check(std::string) const; //argument type subject to change

private:


//mContent, mRelType: should not be modified after initialization, except when replacing the whole object
/*
mContent contains a list-of-strings representation of the Relation.
*/
std::vector<std::string> mContent;
RelType mRelType;

//String conversion tables:



};


#endif