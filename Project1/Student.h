/**
 * Description: Header file for class defination of Student
 * Name: Ashesh Nepal
 * starID: ta9983ry
 * Date: 27th January, 2023
 * Profressor: Jie Meichsner
 */

#ifndef STUDENT
#define STUDENT

/** Provides ostream and istream*/
#include <iostream>
#include "Date.h"

Date defaultDate(0, 0, 0);
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
    Student(int identifier = 0, string fname = "x", string lname = "x", string address = "x", Date dateofenrollment = defaultDate, int creditHoursCompleted = 0);

    /** MODIFICATION MEMBER FUNCTIONS */
    /**
     * Set the unique identifier of this student
     * @param identifier the identifier to set
     */
    void setIdentifier(int identifier)
    {
        this->identifier = identifier;
    }

    /**
     * Set the first name of this student
     * @param fname the fname to set
     */
    void setFname(string fname)
    {
        this->fname = fname;
    }

    /**
     * Set the last name of this student
     * @param lname the lname to set
     */
    void setLname(string lname)
    {
        this->lname = lname;
    }

    /**
     * Set the address of this student
     * @param address the address to set
     */
    void setAddress(string address)
    {
        this->address = address;
    }

    /**
     * Set the date of enrollment of this student
     * @param dateofenrollment the dateofenrollment to set
     */
    void setDateofenrollment(Date dateofenrollment)
    {
        this->dateofenrollment = dateofenrollment;
    }

    /**
     * Set the credit hours completed by this student
     * @param creditHoursCompleted the creditHoursCompleted to set
     */
    void setCreditHoursCompleted(int creditHoursCompleted)
    {
        this->creditHoursCompleted = creditHoursCompleted;
    }

    /** CONSTANT MEMBER FUNCTIONS */
    /**
     * Get the unique identifier of this student
     * @return the identifier
     */
    int getIdentifier() const
    {
        return identifier;
    }
    /**
     * Get the first name of this student
     * @return the fname
     */
    string getFname() const
    {
        return fname;
    }
    /**
     * Get the last name of this student
     * @return the lname
     */
    string getLname() const
    {
        return lname;
    }

    /**
     * Get the address of this student
     * @return the address
     */
    string getAddress() const
    {
        return address;
    }

    /**
     * Get the date of enrollment of this student
     * @return the dateofenrollment
     */
    Date getDateofenrollment() const
    {
        return dateofenrollment;
    }
    /**
     * Get the credit hours completed by this student
     * @return the creditHoursCompleted
     */
    int getCreditHoursCompleted() const
    {
        return creditHoursCompleted;
    }

    /**
     * Overloads the ">>" operator for Student objects.
     * Reads values for the student's identifier, first name, last name, address, date of enrollment and credit hours completed from an input stream, and stores them in the target Student object.
     *
     * @param ins the input stream to read from
     * @param target the Student object to store the read values in
     * @return the input stream that was read from
     */
    friend istream &operator>>(istream &ins, Student &target);

    /**
    @brief two events based on thier eventTime.
    @pre  None.
    @post  If event has a greater event time than EventTime true is returned else false.
    @param event  The event with which comparision is made.
    @return  True if event has a bigger eventTime than eventTime else false. */
    Student &operator=(const Student &other)
    {
        identifier = other.identifier;
        /** first name of this student*/
        string fname = other.fname;
        /** last name of this student*/
        string lname = other.lname;
        /** address of this student*/
        string address = other.address;
        /** date of enrollment of this student*/
        Date dateofenrollment = other.dateofenrollment;
        /** credit hours completed by this student*/
        int creditHoursCompleted = other.creditHoursCompleted;
        return *this;
    }

private:
    /** unique identifier of this student*/
    int identifier;
    /** first name of this student*/
    string fname;
    /** last name of this student*/
    string lname;
    /** address of this student*/
    string address;
    /** date of enrollment of this student*/
    Date dateofenrollment;
    /** credit hours completed by this student*/
    int creditHoursCompleted;
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

#endif
