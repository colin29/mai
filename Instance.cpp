#include "Instance.h"

#include "Exception.h"
#include "Relation.h"

using std::string;
using std::vector;


Instance::Instance(string title, string instanceOf)
: mTitle{title},
  mCNoun{instanceOf}
{}




void Instance::addRelation(const Relation& r){

	if(r.checkRefersToInstance(this->mTitle)==false){
		throw AddRelationException("Relation does not refer to the same Instance.");
	}
	
	mRelations.push_back(r);
	return;
}


//Getter functions
const vector<Relation>& Instance::getRelations() const {
	return mRelations;
};

string Instance::title() const {
	return mTitle;
};
string Instance::cNoun() const {
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