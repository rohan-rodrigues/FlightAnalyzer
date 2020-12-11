//
// Created by Rohan Rodrigues on 12/10/20.
//

#include <vector>
#include "readFromFile.hpp"
#include "airport.h"
#include "route.h"
#include "airline.h"
#include <string>

Route::Route(string airlineId, string airlineCode, string sourceAirport, string destinationAirport, string numStops) {
    this->airlineId = airlineId;
    this->airlineCode = airlineCode;
//    this->airline = Airline("r", "r");
    this->sourceAirport = sourceAirport;
    this->destinationAirport = destinationAirport;
    this->numStops = numStops;
}

string Route::getAirlineId() {
    return airlineId;
}

string Route::getAirlineCode() {
    return airlineCode;
}

string Route::getSourceAirport() {
    return sourceAirport;
}

string Route::getDestinationAirport() {
    return destinationAirport;
}

string Route::getNumStops() {
    return numStops;
}
