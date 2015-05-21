
#ifndef MAI_ENTRY_H
#define MAI_ENTRY_H

#include <string>
#include "EntrySet.h"

class EntrySet;
class Entry{ //these store Mai's information, like wikipedia articles. They are related, and the way they are related constitutes Mai's understanding.
//fields//

public:
	enum type{THING, ABSTRACT_NOUN}; //"thing" includes both entities and objects. I'm hoping not including them at this level will make the entries more flextible.
	std::string definition;
	type t;

	Entry(std::string s, type t);

 	std::string getTitle() const;

	friend bool EntrySet::entryComp(const Entry&, const Entry&);

private:
	std::string title; //textual definition. Mai usually doesn't have a understading of these definitions because they are too abstract/complex
	
};
#endif