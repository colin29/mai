#ifndef MAI_INSTANCE_H
#define MAI_INSTANCE_H	

#include <string>
#include <vector>

#include "Relation.h"
#include "CNoun.h"

class Instance{

public:

Instance(std::string title, std::string instanceOf = ""); //constructor should initialize title

void addRelation(const Relation&);

//getters
const std::vector<Relation>& getRelations() const;
std::string title() const;
std::string cNoun() const;

private:
//title, CNoun: should not be modified except when whole object is replaced.
std::string mTitle; 
std::string mCNoun; //The title of the CNoun the Instance is an instance of. empty string "" means that instance is not based off a common noun, does not inherit Relations, and starts as a completely generic Instance. Meaning-wise, a generic Instance is a single "thing", to which we later add information to.


std::vector<Relation> mRelations;

};

#endif