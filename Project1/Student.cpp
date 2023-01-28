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

Student::Student(int identifier = 0, string fname = "x", string lname = "x", string address = "x", Date dateofenrollment = defaultDate, int creditHoursCompleted = 0)
{
    this->identifier = identifier;
    this->fname = fname;
    this->lname = lname;
    this->address = address;
    this->dateofenrollment = dateofenrollment;
    this->creditHoursCompleted = creditHoursCompleted;
}

friend istream &operator>>(istream &ins, Student &target)
{
    ins >> target.identifier >> target.fname >> target.lname >> target.address >> target.dateofenrollment >> target.creditHoursCompleted;
    return ins;
}

friend ostream &operator<<(ostream &outs, const Student &source)
{
    outs << source.identifier << " " << source.fname << " " << source.lname << " " << source.address << " " << source.dateofenrollment << " " << source.creditHoursCompleted;
    return outs;
}