#include <iostream>
#include <cstdlib>
#include <ctime>
#include "tourManager.h"
#include "tour.h"
#include "city.h"
#include "population.h"
#include "ga.h"
using namespace std;

void tsp() {
    const int PopulationSize = 50;
    const int NumberOfEvolutions = 100;
    
    Population pop(PopulationSize, true);
    Tour fittest = pop.getFittest();
    cout << endl;
    cout << "First distance: " << fittest.getDistance() << endl;
    cout << "Fittest:" << endl;
    cout << fittest << endl;
    
    GA ga;
    for (int i = 1; i <= NumberOfEvolutions; i++) {
        pop = ga.evolvePopulation(pop);
        fittest = pop.getFittest();
        cout << "Evolution " << i << " - distance: " << fittest.getDistance() << endl;
        cout << fittest << endl;
    }
    
    // Print final results
    fittest = pop.getFittest();
    cout << endl;
    cout << "Final distance: " << fittest.getDistance() << endl;
    cout << "Solution:" << endl;
    cout << fittest << endl;
    
}

int main()
{
    srand(time(NULL));
    //srand(10);
    TourManager::init(false);
    cout << "Tour size: " << TourManager::numberOfCities() << endl;
    tsp();
    TourManager::cleanUp();
    
    TourManager::init(true);
    tsp();
    TourManager::cleanUp();
    
    return 0;
}
