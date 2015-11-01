//
//  GA.h
//  tsp
//
//  Created by Ragnar Adolf on 07/05/15.
//  Copyright (c) 2015 Ragnar Adolf. All rights reserved.
//

#ifndef __tsp__GA__
#define __tsp__GA__

#include <iostream>
#include "Population.h"

class GA {
public:
    Population evolvePopulation(Population pop);
    Tour crossover(const Tour& parent1,const Tour& parent2);
private:
    /* GA parameters */
    const double mutationRate = 0.015;
    const int tournamentSize = 5;
    const bool elitism = true;
    
    void mutate(Tour tour);
    Tour tournamentSelection(Population pop);
};

#endif /* defined(__tsp__GA__) */
