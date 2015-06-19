#include "Instance.h"
#include "Exception.h"

using std::string;
using std::vector;


Instance::Instance(string title, string instanceOf)
: mTitle{title},
  mCNoun{instanceOf}
{}




void Instance::addRelation(const Relation& r){
	/*check whether Relation involves the object it's being added to. Checking is done by the Relation class because the required knowledge is more tightly related to the Relation class.*/
	if(checkRefersToInstance(this->mTitle)==false){
		throw AddRelationException("Relation does not refer to the same Instance.");
		//throw std::runtime_error("My error");
	}
	
	mRelations.push_back(r);
	return;
}


//Getter functions
const std::vector<Relation>& Instance::getRelations() const {
	return mRelations;
};
std::string Instance::title() const {
	return mTitle;
};
std::string Instance::cNoun() const {
	return mCNoun;
}


/*
CNoun getCNoun(string cn){
	if(cn==""){
		return null;
	}
	//TODO:: look up "cn"
	return null
}*/