#ifndef PERSONALINFO_H
#define PERSONALINFO_H

#include <iostream>
#include "Time.h"
#include "DateType.h"

using namespace std;


class AirQuality {
public:
    void setAirQuality(int month, int day, int year, int hour, int minute, int second, double temperature,
                       double relativeHumidity, double absoluteHumidity);

    void printAirQuality() const;

    void printTemRel() const;

    void printDateTime() const;

    DateType getDate();

    Time getTime();

    double getTemp();

    double getRelaHumid();

    double getAbsHumid();


    AirQuality(int month = 1, int day = 1, int year = 1900, int hour = 1, int minute = 1, int second = 1,
               double temperature = 10.0, double relativeHumidity = 10.0, double absoluteHumidity = 10.0000);

private:
    DateType bDay;
    Time bTime;
    double bTemperature;
    double bRelativeHumidity;
    double bAbsoluteHumidity;

};

#endif