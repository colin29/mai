#include "Relation.h"
#include "CNoun.h"
#include "Instance.h"
#include "exception.h"

using std::vector;
using std::string;

Is_a IS_A;  //global variable, by default external linkage.
Has_a HAS_A;
Has_some HAS_SOME;

const string CNOUN = "Cnoun::"; //internal linkage by default;
const string INSTANCE = "Instance::";

Relation::Relation(CNoun c1, Is_a, CNoun c2){
mRelType = INHERITANCE1;

mContent.push_back(CNOUN + c1.title());
mContent.push_back("IS_A");
mContent.push_back(CNOUN + c2.title());
}

Relation::Relation(Instance i, Is_a, CNoun c){
mRelType = INHERITANCE2;

mContent.push_back(INSTANCE + i.title());
mContent.push_back("IS_A");
mContent.push_back(CNOUN + c.title());
}


const vector<string>& Relation::getContent() const {
	return mContent;
}

/*
check returns true if this Relation applies to the entry(CNoun or Instance) referred to by the given string
*/
bool Relation::checkRefersToInstance(string title) const {
	assertRelation(*this);
	if(!(mContent[0].find(INSTANCE)==0)){ //mContent[0]should begin with INSTANCE.
		return false;
	}
	if(mContent[0].substr(INSTANCE.size()) != title ){
		return false;
	}
	return true;
}
bool Relation::checkRefersToCNoun(string title) const{
	assertRelation(*this);
	if(!(mContent[0].find(CNOUN)==0)) {
		return false;
	}
	if(mContent[0].substr(CNOUN.size()) != title) {
		return false;
	}	
	return true;
}

//Getter functions:

const RelType Relation::relType() const{
	return mRelType;
}

//Private functions:


void Relation::assertRelation(const Relation& r){
	if(r.mContent.size()==0){
		throw InvalidObjectException("Relation::mContent is empty.");
	}
}