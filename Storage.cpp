#include <stdexcept>

#include "Storage.h"
#include "Exception.h"

using std::string;
using std::vector;
using std::set;



const CNoun Storage::EMPTY_CNOUN = CNoun("");
const Instance Storage::EMPTY_INSTANCE = Instance("");


Storage::Storage(){};


//add functions (inserting new items into the model)
Storage& Storage::add(const CNoun& c){
	mCNouns.insert(c);
	return *this;
}
Storage& Storage::add(const Instance& i){
	mInstances.insert(i);
	return *this;
}


//Read-only access functions

const CNoun& Storage::getCNoun(string s) const{
	CNoun temp(s); //construct a CNoun with title equal the one we are searching for.
	auto iter = mCNouns.find(temp);
	if (iter==mCNouns.end()){
		return EMPTY_CNOUN;
	}else{
		return *iter;
	}
}

const Instance& Storage::getInstance(string s) const{
	Instance temp(s); //construct an Instnace with title equal the one we are searching for.
	auto iter = mInstances.find(temp);
	if(iter == mInstances.end()){
		return EMPTY_INSTANCE;
	}else{
		return *iter;
	}
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