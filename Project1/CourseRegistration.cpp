/**
 * Description: Implementation file of the CourseRegistration class consiting of method definations
 * Name: Ashesh Nepal
 * starID: ta9983ry
 * Date: 27th January, 2023
 * Profressor: Jie Meichsner
 */

/** FILE: CourseRegistration.cpp */
/** CLASS IMPLEMENTED: Date (See CourseRegistration.h for documentation.) */

#include "CourseRegistration.h"

/* NONMEMBER FUNCTIONS for the CourseRegisration class */
// Friend function
istream &operator>>(istream &ins, CourseRegistration &target)
// Library facilities used: iostream
// Friend of: CourseRegistration class
// Inputs date in month-day-year format
{
    ins >> target.courseId_ >> target.studentId_ >> target.creditHours_ >> target.grade_;
    return ins;
}

ostream &operator<<(ostream &outs, const CourseRegistration &source)
// Library facilities used: iostream
{
    outs << source.getCourseId() << " " << source.getStudentId() << " " << source.getCreditHours() << " " << source.getGrade() << "\n";
    return outs;
}
