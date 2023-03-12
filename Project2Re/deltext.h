// deltext.h
// Copyright 1997, Gregory A. Riccardi

#ifndef DELTEXT_H
#define DELTEXT_H

#include <iostream>
using namespace std;

#ifndef FALSE
#define FALSE (0)
#define TRUE (1)
#endif


class DelimTextBuffer 
// a buffer which holds delimited text fields.
// Record variables can be packed into and extracted from a buffer.
{  public:
	DelimTextBuffer (char delim = '|', int maxBytes = 1000); 
	      // construct with fields with delimeters
	void Clear (); // clear fields from buffer
	int Read (istream &); //Read data from a file with a length indicator at the beginning of the file
						  //to the buffer
	int Write (ostream &) const; //Write the Buffer contents to a file with a length indicator at the beginning 
                                 //of the file
	int Pack (const char *, int size = -1); // set the value of the next field of the buffer;
	int Unpack (char *); // extract the value of the next field of the buffer
	void Print (ostream &) const; //display maxBytes and BufferSize 
 	int Init (char delim, int maxBytes = 1000);
 private:
	char Delim;
	char DelimStr[2]; // zero terminated string for Delim
	char * Buffer; // character array to hold field values
	int BufferSize; // size of packed fields
	int MaxBytes; // maximum number of characters in the buffer
	int NextByte; // packing/unpacking position in buffer
};

#endif
