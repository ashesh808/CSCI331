/*
* Description: Header file for class defination of Date
* Name: Ashesh Nepal
* starID: ta9983ry
* Date: 2nd September, 2022
* Profressor: Jie Meichsner
*/

#ifndef DATE
#define DATE

/** Provides ostream and istream*/
#include <iostream>
using namespace std;

class Date
{
public:
	/** Constructor
	 * @param month the month of the Date
	 * @param day the day of the Date
     * @param year the year of the Date
	 * @post sets the date to (initial_day / initial_month / initial_year) */
	Date(int initial_day = 0, int initial_month = 0, int initial_year = 0);

	/** MODIFICATION MEMBER FUNCTIONS */
	/** 
     * @brief value of the numerator
	 * @param numerator_value the new value of the numerator
	 * @pre None
	 * @post The fraction has a new numerator value of numerator_value */
	void set_day(int day_value);

	/** 
     * @brief value of the denominator
	 * @param denominator_value the new value of the denominator
	 * @pre parameter denominator_value cannot be equal to 0
	 * @post The fraction has a new denominator value of denominator_value */
	void set_month(int month_value);

    /** 
     * @brief value of the denominator
	 * @param denominator_value the new value of the denominator
	 * @pre parameter denominator_value cannot be equal to 0
	 * @post The fraction has a new denominator value of denominator_value */
	void set_year(int year_value);

	/** CONSTANT MEMBER FUNCTIONS */
	/** 
     * @brief the numerator of the fraction.
	 * @pre None
	 * @post The value returned is the numerator of the fraction.*/
	int get_day() const { return day; }

	/** 
     * @brief the denominator of the fraction.
	 * @pre None
	 * @post The value returned is the denominator of the fraction.*/
	int get_month() const { return month; }

    /** returns the denominator of the fraction.
	 * @pre None
	 * @post The value returned is the denominator of the fraction.*/
	int get_year() const { return year; }


	/** 
     * @brief a fraction from the istream
	 * @param ins is the istream, target is a fraction
	 * @pre None
	 * @post The numerator and denominator of target have been
	 *  ead from ins. The return value is the istream ins.*/
	friend istream& operator>>(istream &ins, Date &target);

	/* Comparision  functions*/

    /**
    @brief two events based on thier eventTime.
    @pre  None.
    @post  If event has a greater event time than EventTime true is returned else false.
    @param event  The event with which comparision is made.
    @return  True if event has a bigger eventTime than eventTime else false. */
   bool operator>(const Date &event) const;

   /** 
    @brief two events based on thier eventTime.
    @pre  None.
    @post  If event has a smaller event time than EventTime true is returned else false.
    @param event  The event with which comparision is made.
    @return  True if event has a smaller eventTime than eventTime else false. */
   bool operator<(const Date &event) const;

   /** 
    @brief two events based on thier eventTime.
    @pre  None.
    @post  If event has a equal the event time as EventTime true is returned else false.
    @param event  The event with which comparision is made.
    @return  True if event has a equal the eventTime as eventTime else false. 
    */
   bool operator==(const Date &event) const;

 /** 
    @brief two events based on thier eventTime.
    @pre  None.
    @post  If event has a equal the event time as EventTime true is returned else false.
    @param event  The event with which comparision is made.
    @return  True if event has a equal the eventTime as eventTime else false. 
    */
   bool operator!=(const Date &date) const;

private:
	/** numerator of this fraction*/
	int day;
	/** denominator of this fraction*/
	int month;
    /** denominator of this fraction*/
    int year;
};

/* NONMEMBER FUNCTIONS for the fraction class */

/** 
* @brief the fration the ostream
* @param outs is the ostream, source is a fraction
* @pre denominators must not be equal to 0
* @post the numerator and denominator of source have been
	written to outs. The return value is the ostream outs.*/
std::ostream &operator<<(std::ostream &outs, const Date &source);

#endif
