#ifndef MAI_ENTRYSET_H
#define MAI_ENTRYSET_H

	
#include <vector>

class Entry;
class EntrySet{
//Class Invariants:  setOfEntries holds a ordered set of Entries. Entries are sorted by title A-Z, and each entry has a unique title.
	public:
	EntrySet();

	int getSize();
	void insert(const Entry& e);
	void printEntryBank();
	static bool entryComp(const Entry& e1, const Entry& e2);
	
	private:
	void sort();

};


#endif