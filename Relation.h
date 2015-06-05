#ifndef MAI_RELATION_H
#define MAI_RELATION_H

class CNoun; //using forward declaration here avoids circular dependency in headers

class IS_A{ //flag class definitions
};
class HAS_A{
};
class HAS_SOME{ 
};

extern IS_A is_a;
extern HAS_A has_a;
extern HAS_SOME has_some;

class Relation{
public:
Relation(IS_A); //temporary

};



#endif