//
//  TourManager.h
//  tsp
//
//  Created by Ragnar Adolf on 07/05/15.
//  Copyright (c) 2015 Ragnar Adolf. All rights reserved.
//

#ifndef __tsp__TourManager__
#define __tsp__TourManager__

#include <stdio.h>
#include <vector>
#include "City.h"

class TourManager {
public:
    static void addCity(City* city);
    static City* getCity(int index);
    static int numberOfCities();
    static void init(bool random);
    static void cleanUp();
private:
    static vector<City*> destinationCities;
};

#endif /* defined(__tsp__TourManager__) */
