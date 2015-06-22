#ifndef MAI_STORAGE_H
#define MAI_STORAGE_H	


#include <set>
#include <string>
#include <vector>

#include "Cnoun.h"
#include "Instance.h"



struct CNounComp{ 
	bool operator()(const CNoun& c1, const CNoun& c2) const {
		return c1.title() < c2.title();
	}
};
struct InstanceComp{
	bool operator()(const Instance& i1, const Instance& i2) const {
		return i1.title() < i2.title();
	}
};

class Storage{

public:
Storage(); //nothing to initialize atm.


/*
both getInstance and getCNoun denote "not-found" by return an Entry with a blank title.
*/
const Instance& getInstance(std::string s) const;
const CNoun& getCNoun(std::string s) const;

/*
getParent returns an Instance's CNoun.
Notes: An instance can validly have no CNoun, in which case,  returns a CNoun with an empty ("") title.
*/
const CNoun& parent(const Instance&) const; 


private:
std::set<CNoun, CNounComp> mCNouns;
std::set<Instance, InstanceComp> mInstances;

static const CNoun EMPTY_CNOUN;
static const Instance EMPTY_INSTANCE;

};


#endif