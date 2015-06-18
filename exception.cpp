
#include <string>
#include "exception.h"

using std::string;
/*
MaiException is the parent class for all user-defined exceptions.
*/

MaiException::MaiException(string message)
	: std::runtime_error(message)
{}

AddRelationException::AddRelationException(string message)
	: MaiException("Tried to add a Relation to an Entry it doesn't apply to. || " + message)
{}

NonExistantEntryException::NonExistantEntryException(string message)
	: MaiException("Something is referring by string to a entry that does not exist. || " + message)
{}