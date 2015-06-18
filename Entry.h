
#ifndef MAI_ENTRY_H
#define MAI_ENTRY_H

#include <string>
#include "EntrySet.h"
#include "Cnoun.h" 

class Entry{ //these store Mai's information, like wikipedia articles. They are related, and the way they are related constitutes Mai's understanding.
//fields//

public:
	enum conT{THING, ABSTRACT_TOPIC}; //"thing" includes both entities and objects. I'm hoping not including them at this level will make the entries more flextible.
	enum plurT{COMMON_NOUN, PROPER_NOUN};

	Entry(std::string title, plurT p = COMMON_NOUN);

	//CNoun& getCNoun();
	
	//Getters and Setters
	std::string title() const;
	conT conceptualType() const;
	plurT pluralityType() const;
private:
	 //conT, plurT, and title should never be re-assigned except for when replacing the entire object
	conT mConceptualType;
	plurT mPluralityType; 
	std::string mTitle; 

	CNoun cnoun;

	std::string mDefinition;
};
#endif