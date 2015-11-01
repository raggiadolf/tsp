//
//  City.cpp
//  tsp
//
//  Created by Ragnar Adolf on 07/05/15.
//  Copyright (c) 2015 Ragnar Adolf. All rights reserved.
//

#include "City.h"

City::City(int x, int y) : x(x), y(y) {
    
}

int City::getX() const {
    return this->x;
}

int City::getY() const {
    return this->y;
}

double City::distanceTo(City* city) const {
    int xDistance = abs(getX() - city->getX());
    int yDistance = abs(getY() - city->getY());
    double distance = sqrt( (xDistance*xDistance) + (yDistance*yDistance));
    
    return distance;
}

ostream& operator<<(ostream& out, const City& city) {
    out << "(" << city.getX() << "," << city.getY() << ")";
    return out;
}

bool City::operator==(const City& that) const {
    return this->getX() == that.getX() && this->getY() == that.getY();
}
