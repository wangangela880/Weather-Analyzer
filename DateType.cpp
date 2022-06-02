#include <iostream>
#include "DateType.h"

using namespace std;

//Constructor with parameters
DateType::DateType(int month, int day, int year) {
    dMonth = month;
    dDay = day;
    dYear = year;
}

void DateType::setDate(int month, int day, int year) {
    dMonth = month;
    dDay = day;
    dYear = year;
}

int DateType::getDay() const {
    return dDay;
}

int DateType::getMonth() const {
    return dMonth;
}

int DateType::getYear() const {
    return dYear;
}

void DateType::printDate() const {
    cout << "Date is " << dMonth << "/" << dDay << "/" << dYear << endl;
}

// ostream operator
ostream &
operator<<(ostream &osObject, const DateType &DateType1) //creating an instance of a DateType class, i.e. DateType1
{
    osObject << DateType1.dYear << "/" << DateType1.dMonth << "/" << DateType1.dDay;
    return osObject;
}

// istream operator
istream &operator>>(istream &isObject, DateType &DateType1) {
    isObject >> DateType1.dYear >> DateType1.dMonth >> DateType1.dDay;
    return isObject;
}

// Overloading "equal to" operator
bool DateType::operator==(const DateType &otherDateType) const {
    if (dYear == otherDateType.dYear && dMonth == otherDateType.dMonth && dDay == otherDateType.dDay)
        return true;
    else
        return false;
}

// Overloading "not equal to" operator
bool DateType::operator!=(const DateType &otherDateType) const {
    return !(*this == otherDateType);
}

// Overloading "less than or equal to" operator 
bool DateType::operator<=(const DateType &otherDateType) const {
    return (*this < otherDateType || *this == otherDateType);
}

// Overloading "less than" operator
bool DateType::operator<(const DateType &otherDateType) const {
    if ((dYear < otherDateType.dYear) || (dYear == otherDateType.dYear && dMonth < otherDateType.dMonth) ||
        (dYear == otherDateType.dYear && dMonth == otherDateType.dMonth && dDay < otherDateType.dDay))
        return true;
    else
        return false;
}

// Overloading "greater than or equal to" operator
bool DateType::operator>=(const DateType &otherDateType) const {
    return !(*this < otherDateType);
}

// Overloading "greater than" operator
bool DateType::operator>(const DateType &otherDateType) const {
    return !(*this <= otherDateType);
}
