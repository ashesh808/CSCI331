//zipcode.h

#ifndef ZIPCODE_H
#define ZIPCODE_H

#include <iostream>
#include "deltext.h"

class Zipcode 
{
  public:
	/**zipcode*/
	char Code [10];
	/**city*/
	char Placename [30];
	/**state*/
	char State [5];
	/**county*/
	char County [25];
	/**Latitude*/
	char Lat [10];
	/**Longitude*/
	char Long [10];
	
	/**Constructor;
	 * @pre none;
	 * @post an empty zipcode object is created*/
	Zipcode ();

	/**MODIFICATION MEMBER FUNCTIONS*/

	/**Clear;
	 * Sets each field to an empty string
	 * @pre a Zipcode object must exist
	 * @post the zipcode object has its fields set to an empty string*/
	void Clear ();

	/**InitBuffer;
	 * Initalizes a given DelimTextBuffer object
	 * @param DelimTextBuffer object
	 * @pre a Zipcode object and DelimTextBuffer object must exist
	 * @post the given DelimTextBuffer Object is initalized(see deltext.h for more documentation)*/
	static int InitBuffer (DelimTextBuffer &);

	/**Unpack;
	 * Unpacks the zipcode object into a given DelimTextBuffer object
	 * @param DelimTextBuffer object
	 * @pre a Zipcode object and DelimTextBuffer object must exist
	 * @post the Zipcode object is unpacked into a given DelimTextBuffer object*/
	int Unpack (DelimTextBuffer &);

	/**Pack;
	 * Packs the zipcode object from a given DelimTextBuffer object
	 * @param DelimTextBufferObject
	 * @pre a Zipcode object and DelimTextBuffer object must exist
	 * @post the Zipcode object is packed from a given DelimTextBuffer object*/
	int Pack (DelimTextBuffer &) const;

	/**NONMODIFICATION MEMBER FUNCTIONS*/

	/**Print;
	 * Prints the zipcodes fields to a given ostream object
	 * @param ostream object
	 * @pre a Zipcode object must exist
	 * @post the zipcodes fields are written to the given ostream object*/
	void Print (std::ostream &);
};

#include "zipcode.cpp"
#endif
