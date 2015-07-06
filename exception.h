#include <string>
#include <stdexcept>

/*
MaiException is the parent class for all user-defined exceptions.
*/
class MaiException : public std::runtime_error{
public:
	MaiException(std::string message = "No Info Provided");
};

class AddRelationException: public MaiException{
public:
	AddRelationException(std::string message = "");
};

class NonExistantEntryException : public MaiException{
public:
	NonExistantEntryException(std::string message = "");
};

class InvalidObjectException : public MaiException{
public:
	InvalidObjectException(std::string message = "");
};

class InvalidTypeException : public MaiException{
public:
	InvalidTypeException(std::string message = "");
};

class EmptyEntryException : public MaiException{
public:
	EmptyEntryException(std::string message = "");
};