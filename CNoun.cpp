#include "CNoun.h"

#include "exception.h"

using std::string;
using std::vector;

//Public functions
CNoun::CNoun(string iTitle)
: mTitle{iTitle}
{}



void CNoun::addRelation(const Relation& r){
	if(r.checkRefersToCNoun(this->mTitle)==false){
		throw AddRelationException("Relation does not refer to the same CNoun.");
	}
	
	mRelations.push_back(r);
	return;
}



//Getter functions:

const vector<Relation>& CNoun::getRelations() const {
	return mRelations;
};
string CNoun::title() const {
	return mTitle;
};







//Private functions
