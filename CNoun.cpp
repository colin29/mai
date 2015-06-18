#include "CNoun.h"

using std::string;
using std::vector;

//Public functions
CNoun::CNoun(string iTitle)
: mTitle{iTitle}
{}



void CNoun::addRelation(const Relation& r){
	//TODO:: check whether Relation involves the object it's being added to
	mRelations.push_back(r);
	return;
}



//Getter functions:

const std::vector<Relation>& CNoun::getRelations() const {
	return mRelations;
};
std::string CNoun::title() const {
	return mTitle;
};







//Private functions
