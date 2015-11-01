//
//  Population.h
//  tsp
//
//  Created by Ragnar Adolf on 07/05/15.
//  Copyright (c) 2015 Ragnar Adolf. All rights reserved.
//

#ifndef __tsp__Population__
#define __tsp__Population__

#include <iostream>
#include <vector>
#include "Tour.h"

class Population {
public:
    Population(int populationSize, bool initialize);
    void saveTour(int index, Tour& tour);
    Tour& getTour(int index);
    Tour getFittest();
    int populationSize() const;
private:
    vector<Tour> tours;
    int size;
};

#endif /* defined(__tsp__Population__) */
