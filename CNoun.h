#ifndef MAI_CNOUN_H
#define MAI_CNOUN_H

#include <string>
#include <vector>

#include "Relation.h"



class CNoun{


public:
CNoun(std::string iTitle);

const std::vector<Relation>& getRelation ()const;


private:
std::vector<Relation> relations;
std::string title;




};

#endif

