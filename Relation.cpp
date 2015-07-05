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

const int Relation::targetTable[2][2] = 
{
	{0, 2}, //for Inher. 1
	{0, 2} //for Inher. 2
};
	

Relation::Relation(CNoun c1, Is_a, CNoun c2)
: mRelType{RelType::INHERITANCE1}
{
mContent.push_back(CNOUN + c1.title());
mContent.push_back("IS_A");
mContent.push_back(CNOUN + c2.title());
}

Relation::Relation(Instance i, Is_a, CNoun c)
: mRelType{RelType::INHERITANCE2}
{
mContent.push_back(INSTANCE + i.title());
mContent.push_back("IS_A");
mContent.push_back(CNOUN + c.title());
}


// const vector<string>& Relation::getContent() const {
// 	return mContent;
// }


string Relation::getTarget(Inher1 enumSelection) const{
return getTarget(RelType::INHERITANCE1, static_cast<int>(enumSelection));
}

string Relation::getTarget(Inher2 enumSelection) const{
return getTarget(RelType::INHERITANCE2, static_cast<int>(enumSelection));
}


string Relation::getTarget(RelType rtype, int enumSelection) const {
	if(rtype!=mRelType){
		throw InvalidTypeException("relType given does not match this Relation");
	}
	return mContent[targetTable[static_cast<int>(rtype)][enumSelection]];
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