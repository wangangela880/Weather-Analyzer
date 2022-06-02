#ifndef H_DateType
#define H_DateType

#include <iostream>

using namespace std;

class DateType {
public:
    friend ostream &operator<<(ostream &, const DateType &); // method overloading
    friend istream &operator>>(istream &, DateType &);

    void setDate(int month, int day, int year);

    int getDay() const;

    int getMonth() const;

    int getYear() const;

    void printDate() const;

    DateType(int month = 1, int day = 1, int year = 1900);

    // Overloading operators
    bool operator<(const DateType &otherDateType) const;

    bool operator>(const DateType &otherDateType) const;

    bool operator==(const DateType &otherDateType) const;

    bool operator<=(const DateType &otherDateType) const;

    bool operator>=(const DateType &otherDateType) const;

    bool operator!=(const DateType &otherDateType) const;

    // Overloading math operations
    DateType operator++();

    DateType operator++(int);

    DateType operator--();

    DateType operator--(int);

private:
    int dMonth; //variable to store the month
    int dDay; //variable to store the day
    int dYear; //variable to store the year
};

#endif