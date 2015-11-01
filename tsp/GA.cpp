//
//  GA.cpp
//  tsp
//
//  Created by Ragnar Adolf on 07/05/15.
//  Copyright (c) 2015 Ragnar Adolf. All rights reserved.
//

#include "GA.h"

Population GA::evolvePopulation(Population pop) {
    Population newPopulation(pop.populationSize(), false);
    
    // Keep our best individual if elitism is enabled
    int elitismOffset = 0;
    if(elitism) {
        Tour fittest = pop.getFittest();
        newPopulation.saveTour(0, fittest);
        elitismOffset = 1;
    }
    
    // Crossover population
    // Loop over the new population's size and create individuals from
    // Current population
    for(int i = elitismOffset; i < newPopulation.populationSize(); i++) {
        // Select parents
        Tour parent1 = tournamentSelection(pop);
        Tour parent2 = tournamentSelection(pop);
        // Crossover parents
        Tour child = crossover(parent1, parent2);
        // Add child to new population
        newPopulation.saveTour(i, child);
    }
    
    // Mutate the new population a bit to add some new genetic material
    for(int i = elitismOffset; i < newPopulation.populationSize(); i++) {
        mutate(newPopulation.getTour(i));
    }
    
    return newPopulation;
}

Tour GA::crossover(const Tour& parent1,const Tour& parent2) {
    // Create new child tour
    Tour child;
    int startPos = rand() % parent1.tourSize();
    int endPos = rand() % parent1.tourSize();
    
    // Loop and add the sub tour from parent1 to our child
    for(int i = 0; i < child.tourSize(); i++) {
        // If our start position is less than the end position
        if(startPos < endPos && i > startPos && i < endPos) {
            child.setCity(i, parent1.getCity(i));
        } // If our start position is larger
        else if (startPos > endPos) {
            if(!(i < startPos && i > endPos)) {
                child.setCity(i, parent1.getCity(i));
            }
        }
    }
    
    // Loop through parent2's city tour
    for (int i = 0; i < parent2.tourSize(); i++) {
        // If child doesn't have the city add it
        if(!child.containsCity(parent2.getCity(i))) {
            // Loop to find a spare position in the child's tour
            for(int ii = 0; ii < child.tourSize(); ii++) {
                // Spare position found, add city
                if(child.getCity(ii) == nullptr) {
                    child.setCity(ii, parent2.getCity(i));
                    break;
                }
            }
        }
    }
    
    return child;
}

void GA::mutate(Tour tour) {
    // Loop through tour cities
    for(int tourPos1 = 0; tourPos1 < tour.tourSize(); tourPos1++) {
        // Apply mutation rate
        double r = static_cast<double>(rand() / RAND_MAX);
        if(r < mutationRate) {
            // Get a second random position in the tour
            int tourPos2 = rand() % tour.tourSize();
            
            // Get the cities at target position in tour
            City* city1 = tour.getCity(tourPos1);
            City* city2 = tour.getCity(tourPos2);
            
            // Swap them around
            tour.setCity(tourPos2, city1);
            tour.setCity(tourPos1, city2);
        }
    }
}

Tour GA::tournamentSelection(Population pop) {
    // Create a tournament population
    Population tournament(tournamentSize, false);
    // For each place in the tournament get a random canditate tour and
    // add it
    for(int i = 0; i < tournamentSize; i++) {
        int randomID = rand() % pop.populationSize();
        tournament.saveTour(i, pop.getTour(randomID));
    }
    // Get the fittest tour
    Tour fittest = tournament.getFittest();
    return fittest;
}
