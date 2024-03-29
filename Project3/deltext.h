// deltext.h
// Modified example from text book

#ifndef DELTEXT_H
#define DELTEXT_H

/*provides ostream and istream*/
#include <iostream>
/*provides use of c++ strings*/
#include <string>

#ifndef FALSE
#define FALSE (0)
#define TRUE (1)
#endif

class DelimTextBuffer 
// a buffer which holds delimited text fields.
// Record variables can be packed into and extracted from a buffer.
{  public:
	/**Constructor;
	 * @param Delim the delimiter character to be used
	 * @param maxBytes maximum number of characters in the buffer
	 * @pre none
	 * @post a buffer of size maxBytes is created with Delim as the delimiter*/
	DelimTextBuffer (char Delim = ',', int maxBytes = 10000);

	/**MODIFICATION MEMBER FUNCTIONS*/

	/**Clear;
	 * Clear fields from buffer
	 * @pre a DelimTextBuffer must exist
	 * @post the fields in the buffer are empty*/
	void Clear (); // clear fields from buffer

	/**Read;
	 * Reads into the buffer from an istream object
	 * @param istream object
	 * @pre a DelimTextBuffer must exsist
	 * @post a single line from an istream object is read into the buffer
	*/
	int Read (std::istream &);

	/**Pack;
	 * Packs the next value into a c style string
	 * @param a c style string
	 * @param size of the c style string
	 * @pre a DelimTextBuffer must exist
	 * @post a c style string is packed from the buffer
	*/
	int Pack (const char *, int size = -1);

	/**Unpack;
	 * Unpacks a c style string into the buffer
	 * @param a c style string
	 * @pre a DelimTextBuffer must exist
	 * @post a c style string is unpacked into the buffer
	*/
	int Unpack (char *);

	/**Init
	 * Initalize the buffer
	 * @param delim a character delimiter for the buffer
	 * @param maxBytes the maximum number of characters in the buffer(default 10000)
	 * @pre a DelimTextBuffer must exist
	 * @post the buffer is inialized to have delim as the delimiter and a maxBytes of maximum characters
	*/
 	int Init (char delim, int maxBytes = 10000);

	/**NONMODIFICATION MEMBER FUNCTIONS*/

	/**Print;
	 * Prints the maximum size and characters for the buffer
	 * @param ostream object
	 * @pre a DelimTextBuffer must exist
	 * @post the maximum size and characters for the buffer are written to an ostream object
	*/
	void Print (std::ostream &) const;

	/**Write;
	 * Writes the entire buffer to an ostream object
	 * @param ostream object
	 * @pre a DelimTextBuffer must exist
	 * @post the entire buffer is written into an ostream object with delimiters
	*/
	int Write (std::ostream &) const;

 private:
 	/**delimiter character*/
	char Delim;
	/**zero terminated string for Delim*/
	char DelimStr[3];
	/**character array to hold field values*/
	char * Buffer;
	/**string buffer*/
	std::string Rbuffer;
	/**size of packed fields*/
	int BufferSize;
	/**maximum number of characters in the buffer*/
	int MaxBytes;
	/**packing/unpacking position in buffer*/
	int NextByte;
	/**count if it is the end*/
	int count;
};

#include "deltext.cpp"
#endif
