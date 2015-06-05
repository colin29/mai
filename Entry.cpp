#include "Entry.h"
#include <stdexcept>

using std::string;

//public functions:


Entry::Entry(string it, conT ic,  plurT ip)
		: mTitle{it}
		, mConceptualType{ic} 
		, mPluralityType{ip}
		{
			if (mConceptualType != THING || mPluralityType != COMMON_NOUN){
				throw std::invalid_argument("only COMMON_NOUN THING entries are supported at the moment.");
			}
		};

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