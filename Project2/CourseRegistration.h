/**
 * Description: Header file for class defination of Date
 * Name: Ashesh Nepal
 * starID: ta9983ry
 * Date: 2nd March, 2023
 * Profressor: Jie Meichsner
 */

#ifndef _COURSEREGISTRATION_H
#define _COURSEREGISTRATION_H

/** Provides ostream and istream*/
#include <iostream>
#include "fixfld.h"
#include "length.h"
#include "delim.h"
using namespace std;

class CourseRegistration
{
public:
	// Constructors
	/**
	 * Constructs a new CourseRegistration object with the given course identifier, student identifier,
	 * credit hours, and course grade.
	 *
	 * @param courseId the course identifier (default 0)
	 * @param studentId the student identifier (default "")
	 * @param creditHours the number of credit hours (default 0)
	 * @param grade the course grade (default "")
	 */
	CourseRegistration();
	//Buffer Methods
    static int InitBuffer (DelimFieldBuffer &);
	static int InitBuffer (LengthFieldBuffer &);
	static int InitBuffer (FixedFieldBuffer &);
	void Clear ();
	int Unpack (IOBuffer &);
	int Pack (IOBuffer &) const;
	void Print (ostream &, char * label = 0) const;

	//Feilds	
    char courseId_[11];
    char studentId_[11];
    char creditHours_[16];
    char grade_[9];
    
};

/* NONMEMBER FUNCTIONS for the fraction class */

/**
 * @brief 
 * @param outs the output stream to write to
 * @param source the CourseRegistration object to output
 * @pre None
 * @post The contents of the source CourseRegistration object have been written to the outs output stream
 * @return the output stream
 */
std::ostream &operator<<(std::ostream &outs, const CourseRegistration &source);

#include "CourseRegistration.cpp"
#endif
