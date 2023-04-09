/**
\file zipcode.cpp
\author Steven Kraus
\author Emily Yang
\author Tyler Knudtson
\author Ashesh Nepal
\brief Implementation file for Zipcode class
*/

#include "zipcode.h"
#include <string>

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
	//std::cout<<std::endl<<(sizeof(Placename)/sizeof(char))<<std::endl;
	
	int length=((strlen(Placename)+strlen(Code)+strlen(State)+strlen(County)+strlen(Lat)+strlen(Long))+8);
	char* charlen;
	charlen=(char*)std::to_string(length).c_str();//Hooray for three type conversions in one line of code!
	if(std::stoi(charlen)<10){
		charlen[1]=charlen[0];
		charlen[0]='0';//Makes the ASCII length indicator always a fixed length, this makes the buffer implementation easier at the expense of a few kilobytes of disk space.
	}
	Buffer.Pack(charlen);
	result = Buffer . Pack (Code);///Set Code to '' if writing the header.
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
	char len[2];
	len[0]=0;//Basically discards the length indicator at this stage because it's no longer useful.
	Buffer.Unpack(len);//A new length indicator will need to be made during the packing stage though.
	result = Buffer . Unpack (Code);
	if (Code==""){
		result=false;
	}
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