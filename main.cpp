#include <iostream>
#include <fstream>
#include <vector>
#include "AirQuality.cpp"
#include "AirQuality.h"
#include "Time.h"
#include "Time.cpp"
#include "DateType.cpp"
#include "DateType.h"
#include "Menu.h"
#include "Menu.cpp"


using namespace std;

const int columnNumber = 16;
const int dayColumn = 0;
const int TimeColumn = 1;
const int TempColumn = 12;
const int RelativeHumidityColumn = 13;
const int AbsoluteHumidityColumn = 14;
const int maxNumber = 9357;

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wnull-arithmetic"
#pragma clang diagnostic ignored "-Wc++11-extensions"

// get air quality data function
vector <AirQuality> getAirQualityData(ifstream &infile);

int main() {
    vector <AirQuality> airList;

    // file preset
    ifstream infile;
    string headerLine;
    infile.open("AirQualityUCI.csv");
    // if no file, throw error.
    if (!infile) {
        cout << "The input file does not exist. " << "Program terminates." << endl;
        return 1;
    }
    // get rid of the file title
    for (int i = 0; i < 1; i++) {
        infile >> headerLine;
    }

    //read data and set airObject in airList
    airList = getAirQualityData(infile);

    Menu::display(airList);

    return 0;
}

vector <AirQuality> getAirQualityData(ifstream &infile) {
    AirQuality airObject;
    vector <AirQuality> airList;

    string dayString;
    string timeString;

    int dHour;
    int dMinute;
    int dSecond;

    int dMonth;
    int dDay;
    int dYear;

    double bTemperature;
    double bRelativeHumidity;
    double bAbsoluteHumidity;

    string dayConstructor;
    string timeConstructor;

    for (int count = 0; count < maxNumber; count++) {
        string data[16];
        string _partOfstr;

        for (int i = 0; i < columnNumber; i++) {
            getline(infile, _partOfstr, ',');
            data[i] = _partOfstr.c_str();
        }


        dayString = data[dayColumn];
        timeString = data[TimeColumn];
        bTemperature = atof(data[TempColumn].c_str());
        bRelativeHumidity = atof(data[RelativeHumidityColumn].c_str());
        bAbsoluteHumidity = atof(data[AbsoluteHumidityColumn].c_str());

        int num = 0;
        int num1 = 0;
        for (int i = 0; i < dayString.length(); i++) {
            if (dayString[i] == '/') {
                if (num == 0) {
                    dMonth = stoi(dayConstructor);
                    dayConstructor = "";
                } else if (num == 1) {
                    dDay = stoi(dayConstructor);
                    dayConstructor = "";
                }
                num += 1;
            } else {
                dayConstructor += dayString[i];
            }
        }
        dYear = stoi(dayConstructor);
        dayConstructor = "";

        for (int i = 0; i < timeString.length(); i++) {
            if (timeString[i] == ':') {
                if (num1 == 0) {
                    dHour = stoi(timeConstructor);
                    timeConstructor = "";
                } else if (num1 == 1) {
                    dMinute = stoi(timeConstructor);
                    timeConstructor = "";
                }
                num1 += 1;
            } else {
                timeConstructor += timeString[i];
            }
        }
        dSecond = stoi(timeConstructor);
        timeConstructor = "";

        int a = 0;
        if (bTemperature == -200 || bRelativeHumidity == -200 || bAbsoluteHumidity == -200){
            a = 1;
        }else{
            airObject.setAirQuality(dMonth, dDay, dYear, dHour, dMinute, dSecond, bTemperature, bRelativeHumidity,
                                bAbsoluteHumidity);
        }
        
        airList.push_back(airObject);
    }
    return airList;
}


#pragma clang diagnostic pop



