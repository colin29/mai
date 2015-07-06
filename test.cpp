#include <iostream>
#include <stack>

#include "exception.h"
#include "test.h"
#include "StorageReadInterface.h"
#include "util.cpp"



using std::cout;
using std::endl;

using std::string;
using std::vector;

extern StorageReadInterface& storageRead;

void test::run(){
//put your stuff to run here.

}


/*
getAncestors eeturns the titles of all ancestors in the inheritance DAG (all CNouns), filtering out duplicates.
*/
vector<string> test::getAncestors(const CNoun& ic){
	//DFS floodfill
	vector<string> results;
	std::stack<CNoun> Q; //Performance: Unneccsary copying but I can't imagine n being that high. Alternative is a stack of vector<string>'s
	CNoun cur{""};
	CNoun add{""};
	bool firstTime = true;
	if(ic.title()==""){
		throw EmptyEntryException("Invalid input: Empty CNoun given.");
	}
	add = storageRead.getCNoun(ic.title());
	if(add.title()==""){
		throw NonExistantEntryException("Specified CNoun '" + ic.title() + "' not found.");
	}


	Q.push(add);	
	while(!Q.empty()){

		cur = Q.top();
		Q.pop();
		if(!firstTime){
			results.push_back(cur.title()); //if it's not the first time (original CNoun), add to results.
		}else{
			firstTime=false;
		}

		//push all of cur's CNoun's parents onto Q
		for(vector<Relation>::const_iterator iterRel = cur.getRelations().begin(); iterRel!=cur.getRelations().end(); iterRel++){
			if (iterRel->relType() == RelType::INHERITANCE1){
				add = storageRead.getCNoun(iterRel->getTarget(Inher1::PARENT));
				 Q.push(add);
			}
		}

		//util::uniquify(results.begin(), results.end()); //remove duplicates
	}
	
	return results;
}


/*
prints all strings comma and space seperated.
*/
//kinda a naive function, no templates or anything.
void test::print(const vector<string>& vec){
	bool first = true;
	for(const string& s: vec){
		if(!first){
			cout <<", ";
		}else{
			first=false;
		}
		cout << s;
	}
	cout << endl;
}



