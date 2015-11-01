//
//  Tour.cpp
//  tsp
//
//  Created by Ragnar Adolf on 07/05/15.
//  Copyright (c) 2015 Ragnar Adolf. All rights reserved.
//

#include "Tour.h"

Tour::Tour() {
    for(int i = 0; i < TourManager::numberOfCities(); i++) {
        tour.push_back(nullptr);
    }
}

Tour::Tour(vector<City*> tour) : tour(tour) {
    
}

void Tour::generateIndividual() {
    // Loop through all our destination cities and add them to our tour
    for(int cityIndex = 0; cityIndex < TourManager::numberOfCities(); cityIndex++) {
        setCity(cityIndex, TourManager::getCity(cityIndex));
    }
    // Randomly reorder the tour
    unsigned seed = static_cast<unsigned int>(chrono::system_clock::now().time_since_epoch().count());
    shuffle(tour.begin(), tour.end(), default_random_engine(seed));
}

City* Tour::getCity(int tourPosition) const {
    return tour.at(tourPosition);
}

void Tour::setCity(int tourPosition, City* city) {
    tour[tourPosition] = city;
    // If the tours been altered we need to reset the fitness and distance
    fitness = 0;
    distance = 0;
}

double Tour::getFitness() {
    if(fitness == 0) {
        fitness = 1/static_cast<double>(getDistance());
    }
    return fitness;
}

int Tour::getDistance() {
    if(distance == 0) {
        int tourDistance = 0;
        // Loop through our tour's cities
        for (int cityIndex = 0; cityIndex < tourSize(); cityIndex++) {
            // Get city we're travelling from
            City* fromCity = getCity(cityIndex);
            // City we're travelling to
            City* destinationCity;
            // Check we're not on our tour's last city, if we are set our
            // tour's final destination city to our starting city
            if(cityIndex + 1 < tourSize()) {
                destinationCity = getCity(cityIndex + 1);
            } else {
                destinationCity = getCity(0);
            }
            // Get the distance between the two cities
            if(fromCity == NULL || destinationCity == NULL) {
                tourDistance += 0;
            } else {
                tourDistance += fromCity->distanceTo(destinationCity);
            }
        }
        distance = tourDistance;
    }
    return distance;
}

int Tour::tourSize() const {
    return static_cast<int>(tour.size());
}

bool Tour::containsCity(City* city) const {
    return find(tour.begin(), tour.end(), city) != tour.end();
}

ostream& operator<<(ostream& out, const Tour& tour) {
    out << "|";
    
    for(auto ele : tour.tour) {
        out << *ele << "|";
    }
    
    return out;
}
