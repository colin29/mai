#include "Entry.h"
#include <stdexcept>

using std::string;

//public functions:


Entry::Entry(string iTitle, plurT ip)
		: mTitle{iTitle}
		, mConceptualType{THING} 
		, mPluralityType{ip}
		, cnoun(iTitle)
		{
			if (mConceptualType != THING || mPluralityType != COMMON_NOUN){
				throw std::invalid_argument("only COMMON_NOUN THING entries are supported at the moment.");
			}
		};

string Entry::title() const {return mTitle;}
Entry::conT Entry::conceptualType() const {return mConceptualType;}
Entry::plurT Entry::pluralityType() const {return mPluralityType;}



//private functions: