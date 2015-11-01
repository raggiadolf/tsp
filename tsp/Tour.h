//
//  Tour.h
//  tsp
//
//  Created by Ragnar Adolf on 07/05/15.
//  Copyright (c) 2015 Ragnar Adolf. All rights reserved.
//

#ifndef __tsp__Tour__
#define __tsp__Tour__

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "City.h"
#include "Tourmanager.h"

using namespace std;

class Tour {
public:
    Tour();
    Tour(vector<City*> tour);
    
    void generateIndividual();
    City* getCity(int tourPosition) const;
    void setCity(int tourPosition, City* city);
    double getFitness();
    int getDistance();
    int tourSize() const;
    bool containsCity(City* city) const;
    
    friend ostream& operator<<(ostream& out, const Tour& tour);
private:
    vector<City*> tour;
    double fitness = 0;
    int distance = 0;
};

#endif /* defined(__tsp__Tour__) */
