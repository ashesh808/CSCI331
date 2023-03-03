/**
 * Description: Implementation file of the CourseRegistration class consiting of method definations
 * Name: Ashesh Nepal
 * starID: ta9983ry
 * Date: 2nd March, 2023
 * Profressor: Jie Meichsner
 */
/** FILE: CourseRegistration.cpp */
/** CLASS IMPLEMENTED: Date (See Date.h for documentation.) */

#include "CourseRegistration.h"

CourseRegistration::CourseRegistration (){Clear ();}

void CourseRegistration::Clear ()
{
   // set each field to an empty string
    courseId_[0] = 0;
    studentId_[0] = 0;
    creditHours_[0] = 0;
    grade_[0] = 0;
}

int CourseRegistration::Pack (IOBuffer & Buffer) const
{// pack the fields into a FixedFieldBuffer, 
 // return TRUE if all succeed, FALSE o/w
	int numBytes;
	Buffer . Clear ();
	numBytes = Buffer . Pack (courseId_);
	if (numBytes == -1) return FALSE;
	numBytes = Buffer . Pack (studentId_);
	if (numBytes == -1) return FALSE;
	numBytes = Buffer . Pack (creditHours_);
	if (numBytes == -1) return FALSE;
	numBytes = Buffer . Pack (grade_);
	if (numBytes == -1) return FALSE;
	return TRUE;
}

int CourseRegistration::Unpack (IOBuffer & Buffer)
{
	Clear ();
	int numBytes;
	numBytes = Buffer . Unpack (courseId_);
	if (numBytes == -1) return FALSE;
	courseId_[numBytes] = 0;
	numBytes = Buffer . Unpack (studentId_);
	if (numBytes == -1) return FALSE;
	studentId_[numBytes] = 0;
	numBytes = Buffer . Unpack (creditHours_);
	if (numBytes == -1) return FALSE;
	creditHours_[numBytes] = 0;
	numBytes = Buffer . Unpack (grade_);
	if (numBytes == -1) return FALSE;
	grade_[numBytes] = 0;
	return TRUE;
}

int CourseRegistration::InitBuffer (FixedFieldBuffer & Buffer)
// initialize a FixedFieldBuffer to be used for Student
{
	int result;
	result = Buffer . AddField (10); 
	result = result && Buffer . AddField (10); 
	result = result && Buffer . AddField (15); 
	result = result && Buffer . AddField (10);  
	return result;
}

int CourseRegistration::InitBuffer (DelimFieldBuffer & Buffer)
// initialize a DelimFieldBuffer to be used for Student
{	return TRUE;}

int CourseRegistration::InitBuffer (LengthFieldBuffer & Buffer)
// initialize a LengthFieldBuffer to be used for Student
{	return TRUE;}


void CourseRegistration::Print (ostream & stream, char * label) const
{
	if (label == 0) stream << "Course:";
	else stream << label;
	stream << "\n\t Identifier '"<< courseId_<<"'\n"
		<< "\t Student ID '"<< studentId_<<"'\n"
		<< "\t Credit Hours '"<< creditHours_<<"'\n"
		<< "\t Grade '"<< grade_<<"'\n" <<flush;
}