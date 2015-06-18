#include <stdexcept>

#include "Storage.h"
#include "Exception.h"

using std::string;
using std::vector;
using std::set;






Storage::Storage(){};

CNoun Storage::getCNoun(const Instance& i){
	if(i.cNoun()==""){
		return CNoun(""); //represents Instance having no CNoun
	}
	CNoun temp(i.cNoun()); //create temp CNoun with same title
	set<CNoun>::iterator it = mCNouns.find(temp); 
	if(it==mCNouns.end()){
		throw NonExistantEntryException();
	}else{
		return *it;
	}
}