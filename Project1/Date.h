/**
 * Description: Header file for class defination of Date
 * Name: Ashesh Nepal
 * starID: ta9983ry
 * Date: 27th January, 2023
 * Profressor: Jie Meichsner
 */

#ifndef _DATE_H_
#define _DATE_H_

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
     * @brief set the day value
     * @param day_value the new value for the day
     * @post The date object has a new day value of day_value
     * */
    void set_day(int day_value);

    /**
    @brief set the month value
    @param month_value the new value for the month
    @post The date object has a new month value of month_value
    */
    void set_month(int month_value);

    /**
    @brief set the year value
    @param year_value the new value for the year
    @post The date object has a new year value of year_value
    */
    void set_year(int year_value);

    /** CONSTANT MEMBER FUNCTIONS */
    /**
     * @brief Retrieves the current day value
     * @pre None
     * @post The value returned is the current day value.
     * @return The current day value.
     */
    int get_day() const { return day; }

    /**
     * @brief Retrieves the current month value
     * @pre None
     * @post The value returned is the current month value.
     * @return The current month value.
     */
    int get_month() const { return month; }

    /**
     * @brief Retrieves the current year value
     * @pre None
     * @post The value returned is the current year value.
     * @return The current year value.
     */
    int get_year() const { return year; }

    /**
     * @brief reads in a date from an input stream
     * @param ins the input stream to read from
     * @param target the date object to store the read in date
     * @pre None
     * @post The day, month and year of the target date object have been read in from the input stream. The input stream is returned.
     */
    friend istream &operator>>(istream &ins, Date &target);

    /* Comparision  functions*/

    /**
     * @brief compares the current date with the input date
     * @param date is the date to be compared with
     * @return true if the current date is later than the input date, false otherwise
     * @pre none
     * @post the current date and input date are not modified
     */
    bool operator>(const Date &date) const;

    /**
     * @brief compares two dates and checks if the current date object is smaller than the passed date object.
     * @param date is the date object that is to be compared with the current date object
     * @pre None
     * @post returns true if the current date object is smaller than the passed date object, false otherwise.
     */
    bool operator<(const Date &date) const;

    /**
    @brief Compares two Date objects for equality
    @param date The Date object to compare against
    @return true if the two dates are equal, false otherwise
    */
    bool operator==(const Date &date) const;

    /**
    @brief compares two dates and returns true if they are not equal
    @param date the Date object to compare against
    @pre None
    @post Returns true if the current date object is not equal to the date parameter, false otherwise.
    */
    bool operator!=(const Date &date) const;

    /**
     * @brief assigns other Date
     * @param other the date that will be assigned
     * @return refrence to the date object
     */
    Date &operator=(const Date &other)
    {
        day = other.get_day();
        /** first name of this student*/
        month = other.get_month();
        /** last name of this student*/
        year = other.get_year();
        return *this;
    }

private:
    /** day of this date*/
    int day;
    /** month of this date*/
    int month;
    /** year of this date*/
    int year;
};

/* NONMEMBER FUNCTIONS for the fraction class */
/**
 * @brief
 * @param outs the output stream to write to
 * @param source the Date object to be written
 * @pre None
 * @post The contents of source (day, month, and year) have been written to outs.
 */
std::ostream &operator<<(std::ostream &outs, const Date &source);

#endif
