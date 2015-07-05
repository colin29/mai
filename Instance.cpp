#include "Instance.h"

#include "Exception.h"
#include "Relation.h"

using std::string;
using std::vector;


Instance::Instance(string cNoun, string title)
: mTitle{title},
  mCNoun{cNoun}
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