#ifndef H_Time
#define H_Time

#include <iostream>
#include <string.h>

using namespace std;

class Time {

public:
    //Time();
    void setTime(int hour, int minute, int second);

    int getHour() const;

    int getMinute() const;

    int getSecond() const;

    void printTime() const;

    bool operator==(const Time &otherTime) const;

    Time(int hour = 1, int minute = 1, int second = 1);


private:
    int dHour; //variable to store the month
    int dMinute; //variable to store the day
    int dSecond; //variable to store the year
};

#endif

