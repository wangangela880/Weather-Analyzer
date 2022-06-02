//
// Created by 曹雨辰 on 4/26/22.
//
#include "Menu.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wnull-arithmetic"
#pragma clang diagnostic ignored "-Wc++11-extensions"

double Menu::getAveTemp(vector <AirQuality> airList) {
    double result = 0;
    int cnt = 0;
    for (AirQuality element: airList) {
        result += element.getTemp();
        cnt++;
    }
    return result / cnt;
}

double Menu::getAveRelaHumid(vector <AirQuality> airList) {
    double result = 0;
    int cnt = 0;
    for (AirQuality element: airList) {
        result += element.getRelaHumid();
        cnt++;
    }
    return result / cnt;
}

double Menu::getAveAbsHumid(vector <AirQuality> airList) {
    double result = 0;
    int cnt = 0;
    for (AirQuality element: airList) {
        result += element.getAbsHumid();
        cnt++;
    }
    return result / cnt;
}


double Menu::getHighestTemp(vector <AirQuality> airList) {
    double Highest = 0;
    for (AirQuality element: airList) {
        Highest = max(Highest, element.getTemp());

    }
    return Highest;
}

double Menu::getHighestRelaHumid(vector <AirQuality> airList) {
    double Highest = 0;
    for (AirQuality element: airList) {
        Highest = max(Highest, element.getRelaHumid());

    }
    return Highest;
}

double Menu::getHighestAbsHumid(vector <AirQuality> airList) {
    double Highest = 0;
    for (AirQuality element: airList) {
        Highest = max(Highest, element.getAbsHumid());

    }
    return Highest;
}

void Menu::displayHigherTemp(vector <AirQuality> airList) {
    double aveTemp = Menu::getAveTemp(airList);
    cout << "The average temperature is: " << aveTemp << endl;

    for (AirQuality element: airList) {
        if (element.getTemp() > aveTemp) {
            element.printDateTime();
            cout << "The temperature is: " << element.getTemp() << "\n" << endl;
        }
    }
    cout << endl;
}

void Menu::displayHigherRelaHumid(vector <AirQuality> airList) {
    double aveRelaHumid = getAveRelaHumid(airList);
    cout << "The average relative humidity is: " << aveRelaHumid << endl;


    for (AirQuality element: airList) {
        if (element.getRelaHumid() > aveRelaHumid) {
            element.printDateTime();
            cout << "The relative humidity is: " << element.getRelaHumid() << "\n" << endl;
        }
    }
    cout << endl;
}

void Menu::displayHigherAbsHumid(vector <AirQuality> airList) {
    double aveAbsHumid = getAveAbsHumid(airList);
    cout << "The average absolute humidity is: " << aveAbsHumid << endl;

    for (AirQuality element: airList) {
        if (element.getAbsHumid() > aveAbsHumid) {
            element.printDateTime();
            cout << "Absolute humidity is: " << element.getAbsHumid() << "\n" << endl;
        }
    }
    cout << endl;
}

vector <AirQuality> Menu::searchMonth(int month, int year, vector <AirQuality> airList) {
    vector <AirQuality> monthResult;
    for (AirQuality element: airList) {
        if (element.getDate().getMonth() == month && element.getDate().getYear() == year) {
            monthResult.push_back(element);
        }
    }
    return monthResult;
}


vector <AirQuality> Menu::searchDateTime(DateType date, Time time, vector <AirQuality> airList) {
    vector <AirQuality> dateTime;
    for (AirQuality element: airList) {
        if (element.getDate() == date && element.getTime() == time) {
            dateTime.push_back(element);
        }
    }
    return dateTime;
}

void Menu::display(vector <AirQuality> airList){
    cout << "Here are the options menu: \n" << "Enter 1 to get the average temperature for a month.\n"
         << "Enter 2 to get the average relative humidity for a month\n"
         << "Enter 3 to get the average absolute humidity temperature for a month\n"
         << "Enter 4 to get the temperature, and relative humidity on that date and time.\n"
         << "Enter 5 to get the highest temperature for a month.\n"
         << "Enter 6 to get the highest relative humidity value for a month\n"
         << "Enter 7 to get the highest absolute humidity for a month\n"
         << "Enter 8 to get the dates and times for a month when the temperature is higher than the average temperature.\n"
         << "Enter 9 to get the dates and times for a month when the relative humidity is higher than the average relative humidity for that month.\n"
         << "Enter 10 to get the dates and times for a month when absolute humidity is higher than the average absolute humidity for that month.\n"
         << "Enter 0 to quit." << endl;

    int choice = 0;
    while (true) {
        cout << "Please enter your options:" << endl;
        cin >> choice;

        // check if input is null or exit value
        if (choice == NULL) {
            break;
        }

        // check if input is invalid
        if (choice < 1 || choice > 10) {
            cout << "Invalid Input, please try again. " << endl;
            continue;
        }

        if (choice == 4) {
            int day, month, year, hour, minute, second;
            minute = 0;
            second = 0;
            cout
                    << "Please enter the Year, Month and Date, and the exact hour of that day, each with a blank in between:"
                    << endl;
            cin >> year >> month >> day >> hour;
            if (month == NULL || day == NULL || year == NULL || hour == NULL) {
                cout << "invalid input format, please refer to instruction document." << endl;
                break;
            }

            DateType resultDay = DateType(month, day, year);
            Time resultTime = Time(hour, minute, second);
            vector <AirQuality> result = Menu::searchDateTime(resultDay, resultTime, airList);
            if (result.size() != 0) {
                result[0].printTemRel();
            } else {
                cout << "Can't find data of that date and time." << endl;
            }
        }

        if (choice != 4) {
            int month;
            int year;
            cout << "Please enter a month then a year, with a blank between: " << endl;
            cin >> month >> year;
            if (month == NULL or year == NULL) {
                cout << "invalid input format, please refer to instruction document." << endl;
                break;
            }
            vector <AirQuality> result = Menu::searchMonth(month, year, airList);

            if (result.size() == 0) {
                cout << "Can't find data of that month." << endl;
                continue;
            }

            if (choice == 1) {
                double averageTemp = Menu::getAveTemp(result);
                cout << "The average temperature of this month is " << averageTemp << endl;

            } else if (choice == 2) {
                double averageRelaHumid = Menu::getAveRelaHumid(result);
                cout << "The average relative humidity of this month is " << averageRelaHumid << endl;

            } else if (choice == 3) {
                double averageAbsHumid = Menu::getAveAbsHumid(result);
                cout << "The average absolute humidity of this month is " << averageAbsHumid << endl;

            } else if (choice == 5) {
                double HighestTemp = Menu::getHighestTemp(result);
                cout << "the highest temperature for that month is " << HighestTemp << endl;

            } else if (choice == 6) {
                double HighestRelaHumid = Menu::getHighestRelaHumid(result);
                cout << "the highest relative humidity for that month is " << HighestRelaHumid << endl;

            } else if (choice == 7) {
                double HighestAbsHumid = Menu::getHighestAbsHumid(result);
                cout << "the highest absolute humidity for that month is " << HighestAbsHumid << endl;

            } else if (choice == 8) {
                cout
                        << "here are the dates and times for a month when the temperature is higher than the average temperature."
                        << endl;
                Menu::displayHigherTemp(result);

            } else if (choice == 9) {
                cout
                        << "here are the dates and times for a month when the relative humidity is higher than the average relative humidity for that month."
                        << endl;
                Menu::displayHigherRelaHumid(result);
            } else if (choice == 10) {
                cout
                        << "here are the dates and times for a month when absolute humidity is higher than the average absolute humidity for that month."
                        << endl;
                Menu::displayHigherAbsHumid(result);
            }
        }
    }
}