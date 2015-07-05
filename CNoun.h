#ifndef MAI_CNOUN_H
#define MAI_CNOUN_H

#include <string>
#include <vector>

#include "Relation.h"
#include "NounEntry.h"


class CNoun : public NounEntry{


public:

CNoun(std::string title); //constructor should initialize title


void addRelation(const Relation&) override;

//Getter functions
const std::vector<Relation>& getRelations ()const;
std::string title() const;

private:

//title: should not be modified except when whole object is replaced.
std::string mTitle;


std::vector<Relation> mRelations;




};

#endif

