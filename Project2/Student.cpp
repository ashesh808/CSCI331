/**
 * Description: Implementation file of the Student class consiting of method definations
 * Name: Ashesh Nepal
 * starID: ta9983ry
 * Date: 2nd March, 2023
 * Profressor: Jie Meichsner
 */

/** FILE: Student.cpp */
/** CLASS IMPLEMENTED: Date (See Date.h for documentation.) */

#include "Student.h"


Student::Student (){Clear ();}

void Student::Clear ()
{
    // set each field to an empty string
    identifier[0] = 0;
    fname[0] = 0;
    lname[0] = 0;
    address[0] = 0;
    dateofenrollment[0] = 0;
    creditHoursCompleted[0] = 0;
}

int Student::Pack (IOBuffer & Buffer) const
{// pack the fields into a FixedFieldBuffer, 
 // return TRUE if all succeed, FALSE o/w
	int numBytes;
	Buffer . Clear ();
	numBytes = Buffer . Pack (identifier);
	if (numBytes == -1) return FALSE;
	numBytes = Buffer . Pack (fname);
	if (numBytes == -1) return FALSE;
	numBytes = Buffer . Pack (lname);
	if (numBytes == -1) return FALSE;
	numBytes = Buffer . Pack (address);
	if (numBytes == -1) return FALSE;
	numBytes = Buffer . Pack (dateofenrollment);
	if (numBytes == -1) return FALSE;
	numBytes = Buffer . Pack (creditHoursCompleted);
	if (numBytes == -1) return FALSE;
	return TRUE;
}

int Student::Unpack (IOBuffer & Buffer)
{
	Clear ();
	int numBytes;
	numBytes = Buffer . Unpack (identifier);
	if (numBytes == -1) return FALSE;
	identifier[numBytes] = 0;
	numBytes = Buffer . Unpack (fname);
	if (numBytes == -1) return FALSE;
	fname[numBytes] = 0;
	numBytes = Buffer . Unpack (lname);
	if (numBytes == -1) return FALSE;
	lname[numBytes] = 0;
	numBytes = Buffer . Unpack (address);
	if (numBytes == -1) return FALSE;
	address[numBytes] = 0;
	numBytes = Buffer . Unpack (dateofenrollment);
	if (numBytes == -1) return FALSE;
	dateofenrollment[numBytes] = 0;
	numBytes = Buffer . Unpack (creditHoursCompleted);
	if (numBytes == -1) return FALSE;
	creditHoursCompleted[numBytes] = 0;
	return TRUE;
}

int Student::InitBuffer (FixedFieldBuffer & Buffer)
// initialize a FixedFieldBuffer to be used for Student
{
	int result;
	result = Buffer . AddField (10); // identifier [11];
	result = result && Buffer . AddField (10); // fname [11];
	result = result && Buffer . AddField (10); // lname [11];
	result = result && Buffer . AddField (15); // address [16];
	result = result && Buffer . AddField (10);  // dateofenrollment [11];
	result = result && Buffer . AddField (9); // creditHoursCompleted [10];
	return result;
}

int Student::InitBuffer (DelimFieldBuffer & Buffer)
// initialize a DelimFieldBuffer to be used for Student
{	return TRUE;}

int Student::InitBuffer (LengthFieldBuffer & Buffer)
// initialize a LengthFieldBuffer to be used for Student
{	return TRUE;}

void Student::Print (ostream & stream, char * label) const
{
	if (label == 0) stream << "Student:";
	else stream << label;
	stream << "\n\t Identifier '"<< identifier<<"'\n"
		<< "\t First Name '"<< fname<<"'\n"
		<< "\t Last Name '"<< lname<<"'\n"
		<< "\t Address '"<< address<<"'\n"
		<< "\t Date of Enrollment '"<< dateofenrollment<<"'\n"
		<< "\t Credit Hours Completed '"<<creditHoursCompleted<<"'\n" <<flush;
}