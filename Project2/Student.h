/**
 * Description: Header file for class defination of Student
 * Name: Ashesh Nepal
 * starID: ta9983ry
 * Date: 2nd March, 2023
 * Profressor: Jie Meichsner
 */

#ifndef _STUDENT_H
#define _STUDENT_H

/** Provides ostream and istream*/
#include <iostream>
#include "Date.h"
#include "fixfld.h"
// #include "length.h"
#include "delim.h"

class Student
{
public:
    /**
     * Constructs a new Student object with the given parameters.
     * @param identifier The unique identifier for the student. Default is 0.
     * @param fname The first name of the student. Default is "x".
     * @param lname The last name of the student. Default is "x".
     * @param address The address of the student. Default is "x".
     * @param dateofenrollment The date of enrollment of the student. Default is defaultDate.
     * @param creditHoursCompleted The number of credit hours completed by the student. Default is 0.
     */
    Student();
    /**
     * Overloads the ">>" operator for Student objects.
     * Reads values for the student's identifier, first name, last name, address, date of enrollment and credit hours completed from an input stream, and stores them in the target Student object.
     *
     * @param ins the input stream to read from
     * @param target the Student object to store the read values in
     * @return the input stream that was read from
     */
    friend istream &operator>>(istream &ins, Student &target);

    // Buffer Methods
    static int InitBuffer(DelimFieldBuffer &);
    static int InitBuffer(LengthFieldBuffer &);
    static int InitBuffer(FixedFieldBuffer &);
    void Clear();
    int Unpack(IOBuffer &);
    int Pack(IOBuffer &) const;
    void Print(ostream &, char *label = 0) const;
    /** unique identifier of this student*/
    char identifier[11];
    /** first name of this student*/
    char fname[11];
    /** last name of this student*/
    char lname[16];
    /** address of this student*/
    char address[16];
    /** date of enrollment of this student*/
    char dateofenrollment[11];
    /** credit hours completed by this student*/
    char creditHoursCompleted[10];
};

/* NONMEMBER FUNCTIONS for the fraction class */

/**
 * Overloads the "<<" operator for Student objects.
 * Outputs the values of the student's identifier, first name, last name, address, date of enrollment and credit hours completed in the format "identifier fname lname address dateofenrollment creditHoursCompleted" to an output stream.
 *
 * @param outs the output stream to write to
 * @param source the Student object to output the values from
 * @return the output stream that was written to
 */
std::ostream &operator<<(std::ostream &outs, const Student &source);

#include "student.cpp"
#endif
