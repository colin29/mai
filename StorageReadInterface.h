
/*
StorageReadInterface provides a read-only interface to the Storage object. All functions here do not add, remove, or change any of the items stored in the Knowledge Graph*/
class StorageReadInterface{


// Access functions
/*
both getInstance and getCNoun denote "not-found" by return an Entry with a blank title.
*/
virtual const Instance& getInstance(std::string s) const =0;
virtual const CNoun& getCNoun(std::string s) const = 0;



//Convenience functions
/*
getParent returns an Instance's CNoun.
Notes: An instance can validly have no CNoun, in which case,  returns a CNoun with an empty ("") title.
*/
virtual const CNoun& parent(const Instance&) const = 0; 


};