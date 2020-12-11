//
// Created by Rohan Rodrigues on 12/10/20.
//

#ifndef FINAL_PROJECT_ROUTE_H
#define FINAL_PROJECT_ROUTE_H

#include <vector>
#include "readFromFile.hpp"
#include "airport.h"
#include "route.h"
#include "airline.h"
#include <string>

using namespace std;

class Route {
public:
    Route(string airlineId, string airlineCode, string sourceAirport, string destinationAirport, string numStops);
    string getAirlineId();
    string getAirlineCode();
    string getSourceAirport();
    string getDestinationAirport();
    string getNumStops();

private:
    string airlineId;
    string airlineCode;
    string sourceAirport;
    string destinationAirport;
    string numStops;

};


#endif //FINAL_PROJECT_ROUTE_H
