#include <iostream>
#include <stack>

#include "test.h"
#include "StorageReadInterface.h"

using std::cout;
using std::endl;

using std::string;
using std::vector;

extern StorageReadInterface& storageRead;

void test::run(){
//put your stuff to run here.
}


vector<string> test::getAncestors(const CNoun& ic){
	//DFS floodfill
	vector<string> results;
	std::stack<CNoun> Q; //Performance: Unneccsary copying but I can't imagine n being that high. Alternative is a stack of vector<string>'s
	CNoun cur = ic;
	CNoun next{""};
	bool firstTime = true;
	while(!Q.empty()){

		//push all of cur's CNoun's parents onto Q
		for(vector<Relation>::const_iterator iterRel = cur.getRelations().begin(); iterRel!=cur.getRelations().end(); iterRel++){

			if (iterRel->relType() == INHERITANCE1){
				 next = storageRead.getCNoun(iterRel->getContent()[2]);
				 Q.push(next);

			}
		}

		cur = Q.pop();
		if(!firstTime){
			results.push(cur.title());
		}
		
		//todo: search for the entry in the list of Cnoun.
	
	}
	
	return vector<string> stub;
}

//kinda a naive function, no templates or anything.
void print(const vector<string>& vec){
	bool first = true;
	for(const string& s: vec){
		if(!first){
			cout <<", " << endl;
		}else{
			first=false;
		}
		cout << s << endl;
	}
}
