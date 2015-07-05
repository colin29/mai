#ifndef MAI_INSTANCE_H
#define MAI_INSTANCE_H	

#include <string>
#include <vector>

#include "NounEntry.h"
#include "Relation.h"
#include "CNoun.h"

class Instance : public NounEntry {

public:

/*
-title must be unique among instances;
-cNoun is the title of the CNoun the Instance is an Instance of. empty string "" means that instance is not based off a common noun, does not inherit Relations, and starts as a completely generic Instance. Meaning-wise, a generic Instance is a single "thing", to which we later add information to.
*/
Instance(std::string title, std::string cNoun = ""); //constructor should initialize title




/*
addRelation is used during the startup construction of the knowledge graph. May also be used futher down the road when Mai takes in information and constructs entries in the knowledge graph.

Note: A relation can only be added to an entry if it refer to that entry.
*/
void addRelation(const Relation&) override;

//Getter functions
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