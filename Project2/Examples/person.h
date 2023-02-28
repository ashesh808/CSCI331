// person.h
// Copyright 1997, Gregory A. Riccardi

#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include "fixtext.h"
#include "lentext.h"
#include "deltext.h"

using namespace std;

class Person 
{
  public:
	// fields
	char LastName [11];
	char FirstName [11];
	char Address [16];
	char City [16];
	char State [3];
	char ZipCode [10];
	//operations
	Person ();
	void Clear ();
	static int InitBuffer (FixedTextBuffer &);
	//initialize a buffer object for this Person object
	int Unpack (FixedTextBuffer &);
	int Pack (FixedTextBuffer &) const;
	static int InitBuffer (LengthTextBuffer &);
	int Unpack (LengthTextBuffer &);
	int Pack (LengthTextBuffer &) const;
	static int InitBuffer (DelimTextBuffer &);
	int Unpack (DelimTextBuffer &);
	int Pack (DelimTextBuffer &) const;
	void Print (ostream &);
};

#include "person.cpp"
#endif
