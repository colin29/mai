
#ifndef MAI_ENTRY_H
#define MAI_ENTRY_H

#include <string>
#include "EntrySet.h"

class EntrySet;
class Entry{ //these store Mai's information, like wikipedia articles. They are related, and the way they are related constitutes Mai's understanding.
//fields//

public:
	enum conT{THING, ABSTRACT_TOPIC}; //"thing" includes both entities and objects. I'm hoping not including them at this level will make the entries more flextible.
	enum plurT{COMMON_NOUN, PROPER_NOUN};

	Entry(std::string title, conT c = THING, plurT p = COMMON_NOUN);

	friend bool EntrySet::entryComp(const Entry&, const Entry&);
	
	//Getters and Setters
	std::string title() const;
	conT conceptualType() const;
	plurT pluralityType() const;

	std::string def() const;
	void setDef(std::string);
private:
	 //conT, plurT, and title should never be re-assigned except for when replacing the entire object
	conT mConceptualType;
	plurT mPluralityType; 
	std::string mTitle; 

	//std::vector<Element> elements;

	std::string mDefinition;
};
#endif