//
//  Population.cpp
//  tsp
//
//  Created by Ragnar Adolf on 07/05/15.
//  Copyright (c) 2015 Ragnar Adolf. All rights reserved.
//

#include "Population.h"

Population::Population(int populationSize, bool initialize) : tours(populationSize), size(populationSize) {
    // If we need to initialise a population of tours do so
    if(initialize) {
        // Loop and create individuals
        for(int i = 0; i < populationSize; i++) {
            Tour newTour;
            newTour.generateIndividual();
            saveTour(i, newTour);
        }
    }
}

void Population::saveTour(int index, Tour& tour) {
    tours.at(index) = tour;
}

Tour& Population::getTour(int index) {
    return tours.at(index);
}

Tour Population::getFittest() {
    Tour fittest = tours.at(0);
    // Loop through individuals to find fittest
    for(int i = 1; i < populationSize(); i++) {
        if(fittest.getFitness() <= getTour(i).getFitness()) {
            fittest = getTour(i);
        }
    }
    return fittest;
}

int Population::populationSize() const {
    return this->size;
}
