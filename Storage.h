#ifndef MAI_STORAGE_H
#define MAI_STORAGE_H	


#include <set>
#include <string>
#include <vector>

#include "Cnoun.h"
#include "Instance.h"



struct CNounComp{ 
	bool operator()(const CNoun& c1, const CNoun& c2){
		return c1.title() < c2.title();
	}
};
struct InstanceComp{
	bool operator()(const Instance& i1, const Instance& i2){
		return i1.title() < i2.title();
	}
};

class Storage{

public:
Storage(); //nothing to initialize atm.

/*
Purpose: Get's an Instance's CNoun.
Notes: An instance can validly have no CNoun, in which case,  returns a CNoun with an empty ("") title.
*/
CNoun getCNoun(const Instance&); 


private:
std::set<CNoun, CNounComp> mCNouns;
std::set<Instance, InstanceComp> mInstances;

};


#endif