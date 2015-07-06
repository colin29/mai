#include "CNoun.h"
#include "Relation.h"

#include "exception.h"


using std::string;
using std::vector;

//Public functions
CNoun::CNoun(string iTitle)
: mTitle{iTitle}
{}



void CNoun::addRelation(const Relation& r){
	if(r.checkRefersToCNoun(mTitle)==false){
		throw AddRelationException(r.getTarget(Inher1::CHILD) + "!=" + mTitle + ": Relation does not refer to the same CNoun.");
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
