//
//  City.h
//  tsp
//
//  Created by Ragnar Adolf on 07/05/15.
//  Copyright (c) 2015 Ragnar Adolf. All rights reserved.
//

#ifndef __tsp__City__
#define __tsp__City__

#include <iostream>
#include <cmath>

using namespace std;

class City {
public:
    City() = default;
    City(int x, int y);
    
    int getX() const;
    int getY() const;
    double distanceTo(City* city) const;
    
    friend ostream& operator<<(ostream& out, const City& city);
    bool operator==(const City& that) const;
private:
    int x = rand() % 200;
    int y = rand() % 200;
};

#endif /* defined(__tsp__City__) */
