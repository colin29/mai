#include <stdexcept>

#include "Storage.h"
#include "Exception.h"

using std::string;
using std::vector;
using std::set;



const CNoun Storage::EMPTY_CNOUN = CNoun("");
const Instance Storage::EMPTY_INSTANCE = Instance("");


Storage::Storage(){};


const CNoun& Storage::getCNoun(string s) const{
	return EMPTY_CNOUN; //TODO: stub
}
const Instance& Storage::getInstance(string s) const{
	return EMPTY_INSTANCE; //TODO: stub
}

const CNoun& Storage::parent(const Instance& i) const{
	if(i.cNoun()==""){
		return EMPTY_CNOUN; //represents Instance having no CNoun
	}
	CNoun temp(i.cNoun()); //create temp CNoun with same title
	set<CNoun>::const_iterator it = mCNouns.find(temp); 
	if(it==mCNouns.end()){
		throw NonExistantEntryException();
	}else{
		return *it;
	}
}