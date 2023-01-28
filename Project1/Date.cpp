/**
 * Description: Implementation file of the Date class consiting of method definations
 * Name: Ashesh Nepal
 * starID: ta9983ry
 * Date: 27th January, 2023
 * Profressor: Jie Meichsner
 */

/** FILE: Date.cpp */
/** CLASS IMPLEMENTED: Date (See Date.h for documentation.) */

#include "Date.h"

Date::Date(int initial_day, int initial_month, int initial_year)
{
    day = initial_day; // Constructor sets the fraction to a given values.
    month = initial_month;
    year = initial_year;
}

void Date::set_day(int day_value)
{
    day = day_value;
}

void Date::set_month(int month_value)
{
    month = month_value;
}

void Date::set_year(int year_value)
{
    year = year_value;
}

bool Date::operator> (const Date &date) const
{
    if (year > date.get_year()) {
        return true;
    } else if (year == date.get_year()) {
        if (month > date.get_month()) {
            return true;
        } else if (month == date.get_month()) {
            return day > date.get_day();
        }
    }
    return false;
}

bool Date::operator==(const Date &date) const
{
    if (year != date.year) {
        return false;
    } else if (year == date.year) {
        if (month != date.month) {
            return false;
        } else if (month == date.month) {
            return day == date.day;
        }
    }
    return true;
}

bool Date::operator!=(const Date &date) const
{
    return !(operator==(date));
}

bool Date::operator<(const Date &date) const
{
    //Not "less than and equal to" then its greater than
    return !(operator>(date)) && operator!=(date);
}


/* NONMEMBER FUNCTIONS for the fraction class */
// Friend function
istream &operator>>(istream &ins, Date &target)
// Library facilities used: iostream
// Friend of: Date class
// Inputs date in month-day-year format
{
    ins >> target.month >> target.day >> target.year;
    return ins;
}

// Prints the date in month - day - year format
ostream &operator<<(ostream &outs, const Date &source)
// Library facilities used: iostream
{
    outs << source.get_month() << " / " << source.get_day() << " / " << source.get_year() << "\n";
    return outs;
}
