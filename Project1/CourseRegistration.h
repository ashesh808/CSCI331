/**
 * Description: Header file for class defination of Date
 * Name: Ashesh Nepal
 * starID: ta9983ry
 * Date: 27th January, 2023
 * Profressor: Jie Meichsner
 */

#ifndef COURSEREGISTRATION
#define COURSEREGISTRATION

/** Provides ostream and istream*/
#include <iostream>
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
	CourseRegistration(int courseId = 0, int studentId = 0, int creditHours = 0, string grade = "")
		: courseId_(courseId), studentId_(studentId), creditHours_(creditHours), grade_(grade) {}

	// Get/Set methods
	/**
	 * Returns the course identifier for this CourseRegistration.
	 *
	 * @return the course identifier
	 */
	int getCourseId() const { return courseId_; }
	/**
	 * Sets the course identifier for this CourseRegistration.
	 *
	 * @param courseId the new course identifier
	 */
	void setCourseId(int courseId) { courseId_ = courseId; }
	/**
	 * Returns the student identifier for this CourseRegistration.
	 *
	 * @return the student identifier
	 */
	int getStudentId() const { return studentId_; }

	/**
	 * Sets the student identifier for this CourseRegistration.
	 *
	 * @param studentId the new student identifier
	 */
	void setStudentId(int studentId) { studentId_ = studentId; }
	/**
	 * Returns the number of credit hours for this CourseRegistration.
	 *
	 * @return the number of credit hours
	 */
	int getCreditHours() const { return creditHours_; }
	/**
	 * Sets the number of credit hours for this CourseRegistration.
	 *
	 * @param creditHours the new number of credit hours
	 */
	void setCreditHours(int creditHours) { creditHours_ = creditHours; }
	/**
	 * Returns the course grade for this CourseRegistration.
	 *
	 * @return the course grade
	 */
	string getGrade() const { return grade_; }

	/**
	 * Sets the course grade for this CourseRegistration.
	 *
	 * @param grade the new course grade
	 */
	void setGrade(string grade) { grade_ = grade; }
	/**
	 * @brief Reads a CourseRegistration from an input stream
	 * @param ins the input stream to read from
	 * @param target the CourseRegistration object to store the read data
	 * @pre None
	 * @post The data for the CourseRegistration object has been read from the input stream. The input stream is returned.
	 */
	friend istream &operator>>(istream &ins, CourseRegistration &target);

private:
	int courseId_;
	int studentId_;
	int creditHours_;
	string grade_;
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

#endif
