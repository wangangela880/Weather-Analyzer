//
// Created by 曹雨辰 on 4/26/22.
//
#include <iostream>
#include <fstream>
#include <vector>
#include "AirQuality.h"

#ifndef FINAL_PROJECT_3_MENU_H
#define FINAL_PROJECT_3_MENU_H


class Menu {
public:
    static double getAveTemp(vector <AirQuality> airList);

    static double getAveRelaHumid(vector <AirQuality> airList);

    static double getAveAbsHumid(vector <AirQuality> airList);

    static double getHighestTemp(vector <AirQuality> airList);

    static double getHighestRelaHumid(vector <AirQuality> airList);

    static double getHighestAbsHumid(vector <AirQuality> airList);

    static void displayHigherTemp(vector <AirQuality> airList);

    static void displayHigherRelaHumid(vector <AirQuality> airList);

    static void displayHigherAbsHumid(vector <AirQuality> airList);

    static vector <AirQuality> searchMonth(int month, int year, vector <AirQuality> airList);

    static vector <AirQuality> searchDateTime(DateType date, Time time, vector <AirQuality> airList);

    static void display(vector <AirQuality> airList);
    
};


#endif //FINAL_PROJECT_3_MENU_H
