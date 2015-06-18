#include "Relation.h"
#include "CNoun.h"
#include "Instance.h"

using std::vector;
using std::string;

Is_a IS_A;  //global variable, by default external linkage.
Has_a HAS_A;
Has_some HAS_SOME;


Relation::Relation(CNoun c1, Is_a, CNoun c2){
mRelType = INHERITANCE1;

mContent.push_back(c1.title());
mContent.push_back("IS_A");
mContent.push_back(c2.title());

}
Relation::Relation(Instance i, Is_a, CNoun c){
mRelType = INHERITANCE2;

mContent.push_back(i.title());
mContent.push_back("IS_A");
mContent.push_back(c.title());
}

/*
check returns true if this Relation applies to the entry(CNoun or Instance) referred to by the given string
*/
bool Relation::check(string s) const {
	//TODO: stub
	return true;
}