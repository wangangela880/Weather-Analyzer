#include <iostream>
#include "DateType.h"
#include "Time.h"
#include "AirQuality.h"
#include <iomanip>

using namespace std;

AirQuality::AirQuality(int month, int day, int year, int hour, int minute, int second, double temperature,
                       double relativeHumidity, double absoluteHumidity) : bDay(month, day, year),
                                                                           bTime(hour, minute, second) {
    bTemperature = temperature;
    bRelativeHumidity = relativeHumidity;
    bAbsoluteHumidity = absoluteHumidity;
}

void AirQuality::setAirQuality(int month, int day, int year, int hour, int minute, int second, double temperature,
                               double relativeHumidity, double absoluteHumidity) {
    bDay.setDate(month, day, year);
    bTime.setTime(hour, minute, second);
    bTemperature = temperature;
    bRelativeHumidity = relativeHumidity;
    bAbsoluteHumidity = absoluteHumidity;
}

DateType AirQuality::getDate() {
    return bDay;
}

Time AirQuality::getTime() {
    return bTime;
}

double AirQuality::getTemp() {
    return bTemperature;
}

double AirQuality::getRelaHumid() {
    return bRelativeHumidity;
}


double AirQuality::getAbsHumid() {
    return bAbsoluteHumidity;
}

void AirQuality::printTemRel() const {
    cout << "Temperature is " << showpoint << setprecision(3) << bTemperature << endl;
    cout << "RelativeHumidity is " << showpoint << setprecision(3) << bRelativeHumidity << endl;
}


void AirQuality::printAirQuality() const {
    cout << "Date is ";
    bDay.printDate();
    cout << "Time is ";
    bTime.printTime();
    cout << "Temperature is " << showpoint << setprecision(3) << bTemperature << endl;
    cout << "RelativeHumidity is " << showpoint << setprecision(3) << bRelativeHumidity << endl;
    cout << "AbsoluteHumidity is " << showpoint << setprecision(4) << bAbsoluteHumidity << endl;
    cout << endl;
}

void AirQuality::printDateTime() const {
    bDay.printDate();
    bTime.printTime();

}