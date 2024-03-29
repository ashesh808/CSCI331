/**
 * @file Zipcode.h
 * @brief Header file for Zipcode class
 * @version 0.1
 * @date 2023-04-10
 * \author Steven Kraus
 * \author Emily Yang
 * \author Tyler Knudtson
 * \author Ashesh Nepal
 */

#ifndef ZIPCODE_H
#define ZIPCODE_H
#include <iostream>
#include "deltext.h"

/**
\class
\brief declaration file for Zipcode class
Contains function declarations for Zipcode class
*/

class Zipcode
{
public:
	char Code[10];
	char Placename[30];
	char State[5];
	char County[25];
	char Lat[10];
	char Long[10];

	/**
	\fn Zipcode
	Constructor
	\post Initializes an empty Zipcode object*/
	Zipcode();

	/* MODIFICATION MEMBER FUNCTIONS*/

	/**
	\fn Clear;
	Sets all fields to empty strings
	\post All fields set to empty strings*/
	void Clear();

	/**
	\fn InitBuffer;
	Initializes a DelimTextBuffer object
	\param the DelimTextBuffer to be initialized
	\pre a Zipcode object must exist
	\post the DelimTextBuffer object is initialized*/
	static int InitBuffer(DelimTextBuffer &);

	/**
	\fn Unpack;
	Unpacks DelimTextBuffer into Zipcode object
	\param the DelimTextBuffer to be unpacked
	\post the DelimTextBuffer is unpacked into a Zipcode object*/
	int Unpack(DelimTextBuffer &);

	/**
	\fn Pack;
	\brief the Zipcode object into a DelimTextBuffer object
	\param The DelimTextBuffer to pack
	\pre DelimTextBuffer must exist and be initialized
	\post the Zipcode object is packed into a DelimTextBuffer*/
	int Pack(DelimTextBuffer &) const;

	/* NONMODIFICATION MEMBER FUNCTIONS*/

	/**
	\fn Print;
	Prints Zipcode object into an ostream object
	\param ostream object to print to
	\post Fields from Zipcode are written into ostream object*/
	void Print(std::ostream &);

	/** Size;
	 * @pre a zipcode object must exist
	 * @post returns the length of all fields in a zipcode including the commas
	 * @return int
	 */
	int Size();

	bool operator!=(const Zipcode &other) const
	{
		return (strcmp(Code, other.Code) != 0 ||
				strcmp(Placename, other.Placename) != 0 ||
				strcmp(State, other.State) != 0 ||
				strcmp(County, other.County) != 0 ||
				strcmp(Lat, other.Lat) != 0 ||
				strcmp(Long, other.Long) != 0);
	}
	
	bool operator ==(const Zipcode &other) const
	{
		return !(operator!=(other));
	}

	bool operator <(const Zipcode&rhs) const{
		return(std::stoi(this->Code)<std::stoi(rhs.Code));
	}

	bool operator >(const Zipcode&rhs) const{
		return(std::stoi(this->Code)>std::stoi(rhs.Code));
	}

	Zipcode &operator=(const Zipcode &other)
	{
		if (this != &other)
		{
			// Copy the data members from the other object
			strcpy(Code, other.Code);
			strcpy(Placename, other.Placename);
			strcpy(State, other.State);
			strcpy(County, other.County);
			strcpy(Lat, other.Lat);
			strcpy(Long, other.Long);
		}
		return *this;
	}
	
	
};
#include "zipcode.cpp"
#endif