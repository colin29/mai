#include <vector>
#include <string>

#include "CNoun.h"
#include "Instance.h"

class Test{


/*
reccomended for engine to only call run and not call other functions.
*/
void run();

//if the function becomes useful, I can stick it into CNoun without too much work.
/* 
getAncestors returns all CNoun's inherited from  (ie. IS_A)
*/
std::vector<std::string> getAncestors(const CNoun&);



//I might make a template version for fun, though also should check whether std has a fun. that accomplishes the same things ()
void print(const std::vector<std::string>&);


};