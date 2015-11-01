//
//  TourManager.cpp
//  tsp
//
//  Created by Ragnar Adolf on 07/05/15.
//  Copyright (c) 2015 Ragnar Adolf. All rights reserved.
//

#include "TourManager.h"

vector<City*> TourManager::destinationCities;

void TourManager::addCity(City* city) {
    destinationCities.push_back(city);
}

City* TourManager::getCity(int index) {
    return destinationCities.at(index);
}

int TourManager::numberOfCities() {
    return static_cast<int>(destinationCities.size());
}

void TourManager::init(bool random) {
    int noOfCities = 20;
    if(random) {
        for(int i = 0; i < noOfCities; i++) {
            TourManager::addCity(new City());
        }
    } else {
        /* Býr til tilvikin 20 af City sem fram koma í java klasanum TSP_GA(city1 - city20). */
        // Create and add our cities
        City* city = new City(60, 200);
        TourManager::addCity(city);
        City* city2 = new City(180, 200);
        TourManager::addCity(city2);
        City* city3 = new City(80, 180);
        TourManager::addCity(city3);
        City* city4 = new City(140, 180);
        TourManager::addCity(city4);
        City* city5 = new City(20, 160);
        TourManager::addCity(city5);
        City* city6 = new City(100, 160);
        TourManager::addCity(city6);
        City* city7 = new City(200, 160);
        TourManager::addCity(city7);
        City* city8 = new City(140, 140);
        TourManager::addCity(city8);
        City* city9 = new City(40, 120);
        TourManager::addCity(city9);
        City* city10 = new City(100, 120);
        TourManager::addCity(city10);
        City* city11 = new City(180, 100);
        TourManager::addCity(city11);
        City* city12 = new City(60, 80);
        TourManager::addCity(city12);
        City* city13 = new City(120, 80);
        TourManager::addCity(city13);
        City* city14 = new City(180, 60);
        TourManager::addCity(city14);
        City* city15 = new City(20, 40);
        TourManager::addCity(city15);
        City* city16 = new City(100, 40);
        TourManager::addCity(city16);
        City* city17 = new City(200, 40);
        TourManager::addCity(city17);
        City* city18 = new City(20, 20);
        TourManager::addCity(city18);
        City* city19 = new City(60, 20);
        TourManager::addCity(city19);
        City* city20 = new City(160, 20);
        TourManager::addCity(city20);
    }
}

void TourManager::cleanUp() {
    for(int i = 0; i < TourManager::numberOfCities(); i++) {
        delete destinationCities[i];
    }
    destinationCities.clear();
}
