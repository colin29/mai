#include "Entry.h"

using std::string;

Entry::Entry(string s, Entry::type t)
		: title(s)
		, t(t)
		{};
string Entry::getTitle() const {
		return title;
	}

