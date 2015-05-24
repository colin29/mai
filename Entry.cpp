#include "Entry.h"

using std::string;

//public functions:

Entry::Entry(string it, conT ic = THING,  plurT ip = COMMON_NOUN)
		: mTitle{it}
		, mConceptualType{ic}
		, mPluralityType{ip}
		{};

string Entry::title() const {return mTitle;}
Entry::conT Entry::conceptualType() const {return mConceptualType;}
Entry::plurT Entry::pluralityType() const {return mPluralityType;}

string Entry::def() const{
	return mDefinition;
}
void Entry::setDef(std::string id){
	mDefinition = id;
}

//private functions: