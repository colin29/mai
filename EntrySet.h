#ifndef MAI_ENTRYSET_H
#define MAI_ENTRYSET_H

	
#include <vector>

class Entry;

//Info: EntrySet is a encylopedic container that holds known entries.
class EntrySet{
//Class Invariants:  setOfEntries holds a ordered set of Entries. Entries are sorted by title A-Z, and each entry has a unique title.
	public:
	EntrySet();

	void insert(const Entry& e);

	int getSize() const;
	void printEntryBank() const;

	static bool entryComp(const Entry& e1, const Entry& e2);
	private:
	void sort();

	std::vector<Entry> setOfEntries;

};


#endif