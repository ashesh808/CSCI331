// FILE: deltext.cpp
// CLASS IMPLEMENTED: DelimTextBuffer(see deltext.h for documentation)
// Modified example from text book


#include "deltext.h"
#include <string.h>
#include <iostream>

DelimTextBuffer :: DelimTextBuffer (char delim, int maxBytes)
 // construct with a maximum of maxFields
{	Init (delim, maxBytes);}

void DelimTextBuffer :: Clear ()
// clear fields from buffer
{	count = 0; NextByte = 0; BufferSize = 0;}

int DelimTextBuffer :: Read (std::istream & stream)
{
	Clear ();
	if (stream.fail()){ std::cout <<"streamfail "<<std::endl; return FALSE;}
	if (BufferSize > MaxBytes){ std::cout <<"bs > m "<<std::endl; return FALSE;} // buffer overflow	
	std::getline(stream, Rbuffer); 	
	BufferSize = Rbuffer.length();	
	return stream . good ();
}


int DelimTextBuffer :: Write (std::ostream & stream) const
{
	stream . write (Buffer, BufferSize);
	stream . write ((char*)&DelimStr[2], sizeof(DelimStr[2]));
	return stream . good ();
}

int DelimTextBuffer :: Pack (const char * str, int size)
// set the value of the next field of the buffer;
// if size = -1 (default) use strlen(str) as Delim of field
{
	short len; // length of string to be packed
	if (size >= 0){ len = size;}
		else{ len = strlen (str);}
	if (len > strlen(str)){ // str is too short!
		std::cout <<"tooshort "<<std::endl;return FALSE;}
	int start = NextByte; // first character to be packed

	memcpy (&Buffer[start], str, len);
	if(count!=5){
		NextByte += len + 1;
		if (NextByte > MaxBytes){ std::cout<< NextByte <<"n>m "<< MaxBytes<<std::endl;return FALSE;}
		Buffer [start+len] = Delim; // add delimeter
		BufferSize = NextByte;
		count++;
	}else{
		NextByte += len;
		if (NextByte > MaxBytes){ std::cout <<"n>m 5"<<std::endl;return FALSE;}
		BufferSize = NextByte;
		count = 0;}
	return TRUE;
}

int DelimTextBuffer :: Unpack (char * str)
// extract the value of the next field of the buffer
{
	int len = -1; // length of packed string
	int start = NextByte; // first character to be unpacked
	if(count!=5){
		for(int i = start; i < BufferSize; i++)
		if (Rbuffer[i] == Delim) 
			{len = i - start;
			

			break;}

		if (len == -1){ 
			std::cout <<"len == -1 "<<std::endl; 
			return FALSE;} // delimeter not found

		NextByte += len + 1;

		if (NextByte > BufferSize){ 
			std::cout <<"next > bs "<<std::endl;
			return FALSE;}

		strncpy (str, &Rbuffer[start], len);
		str [len] = 0; // zero termination for string 
		count++;
	}else{
		len = BufferSize-start - 1;
		NextByte += len;
		if (NextByte > BufferSize){ std::cout <<"next > bs 5 "<<std::endl; return FALSE;}
		strncpy (str, &Rbuffer[start], len);
		str [len] = 0; // zero termination for string 		
		count = 0;
		}
	return TRUE;
}

void DelimTextBuffer :: Print (std::ostream & stream) const
{
	stream << "Buffer has max characters "<<MaxBytes<<" and Buffer Size "<<BufferSize<<std::endl;
}

// Protected members

int DelimTextBuffer :: Init (char delim, int maxBytes)
 // construct with a maximum of maxFields
{
	Delim = delim;
	DelimStr[0] = Delim;
	DelimStr[1] = 0;
	DelimStr[2] = '\n';
	if (maxBytes < 0) maxBytes = 0;
	MaxBytes = maxBytes;
	Buffer = new char[MaxBytes];
	Rbuffer = "";
	BufferSize = 0;
	count = 0;
	return 1;
}

