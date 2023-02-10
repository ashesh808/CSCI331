/**
 * Description: Implementation file of the Student class consiting of method definations
 * Name: Ashesh Nepal
 * starID: ta9983ry
 * Date: 27th January, 2023
 * Profressor: Jie Meichsner
 */

/** FILE: Student.cpp */
/** CLASS IMPLEMENTED: Date (See Date.h for documentation.) */

#include "Student.h"

Student::Student(int identifier, string fname, string lname, string address, Date dateofenrollment, int creditHoursCompleted)
{
    this->identifier = identifier;
    this->fname = fname;
    this->lname = lname;
    this->address = address;
    this->dateofenrollment = dateofenrollment;
    this->creditHoursCompleted = creditHoursCompleted;
}

istream &operator>>(istream &ins, Student &target)
{
    ins >> target.identifier >> target.fname >> target.lname >> target.address >> target.dateofenrollment >> target.creditHoursCompleted;
    return ins;
}

ostream &operator<<(ostream &outs, const Student &source)
{
    outs << source.getIdentifier() << "\n" << source.getFname() << " " << source.getLname() << "\n" << source.getAddress() << "\n" << source.getDateofenrollment() << source.getCreditHoursCompleted() << "\n";
    return outs;
}