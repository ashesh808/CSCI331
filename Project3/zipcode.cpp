// FILE: zipcode.cpp
// CLASS IMPLEMENTED: Zipcode(see zipcode.h for documentation)

#include "zipcode.h"

Zipcode::Zipcode ()
{
	Clear ();
}

void Zipcode::Clear ()
{
	// set each field to an empty string
	Code [0] = 0;
	Placename [0] = 0;
	State [0] = 0;
	County [0] = 0;
	Lat [0] = 0;
	Long [0] = 0;
}

int Zipcode::Pack (DelimTextBuffer & Buffer) const
{// pack the fields into a DelimTextBuffer, return TRUE if all succeed, FALSE o/w
	int result;
	Buffer . Clear ();
	result = Buffer . Pack (Code);
	result = result && Buffer . Pack (Placename);
	result = result && Buffer . Pack (State);
	result = result && Buffer . Pack (County);
	result = result && Buffer . Pack (Lat);
	result = result && Buffer . Pack (Long);
	return result;
}

int Zipcode::Unpack (DelimTextBuffer & Buffer)
{
	int result;
	result = Buffer . Unpack (Code);
	result = result && Buffer . Unpack (Placename);
	result = result && Buffer . Unpack (State);
	result = result && Buffer . Unpack (County);
	result = result && Buffer . Unpack (Lat);
	result = result && Buffer . Unpack (Long);

	return result;
}

int Zipcode::InitBuffer (DelimTextBuffer & Buffer)
// initialize a DelimTextBuffer to be used for Persons
{
	return TRUE;
}

void Zipcode::Print (std::ostream & stream)
{
	stream << "info:"
		<< "\t   ZipCode '"<<Code<<"'\n"
		<< "\t Placename '"<<Placename<<"'\n"
		<< "\t     State '"<<State<<"'\n"
		<< "\t    County '"<<County<<"'\n"
		<< "\t       Lat '"<<Lat<<"'\n"
		<< "\t      Long '"<<Long<<"'\n" <<std::flush;
}
