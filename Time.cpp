#include <iostream>
#include "Time.h"

using namespace std;

//Constructor with parameters
Time::Time(int hour, int minute, int second) {
    dHour = hour;
    dMinute = minute;
    dSecond = second;
}

void Time::setTime(int hour, int minute, int second) {
    dHour = hour;
    dMinute = minute;
    dSecond = second;
}

int Time::getHour() const {
    return dHour;
}

int Time::getMinute() const {
    return dMinute;
}

int Time::getSecond() const {
    return dSecond;
}

void Time::printTime() const {
    cout << "Time is " << dHour << ":" << dMinute << ":" << dSecond << endl;
}

bool Time::operator==(const Time &otherTime) const {
    if (dHour == otherTime.dHour && dMinute == otherTime.dMinute && dSecond == otherTime.dSecond)
        return true;
    else
        return false;
}



