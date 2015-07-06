#ifndef MAI_STORAGE_H
#define MAI_STORAGE_H	


#include <set>
#include <string>
#include <vector>

#include "Cnoun.h"
#include "Instance.h"
#include "StorageReadInterface.h"



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

class Storage : public StorageReadInterface{

public:
Storage(); //nothing to initialize atm.


//add functions:
Storage& add(const CNoun&);
Storage& add(const Instance&);


//Read-only Access functions
const Instance& getInstance(std::string s) const;
const CNoun& getCNoun(std::string s) const;



//Convenience functions
const CNoun& parent(const Instance&) const; 


private:


/*
mCNouns and mInstances are backend containers which hold all CNouns and Instances in a Storage.
*/
std::set<CNoun, CNounComp> mCNouns; 
std::set<Instance, InstanceComp> mInstances;

static const CNoun EMPTY_CNOUN;
static const Instance EMPTY_INSTANCE;

};


#endif