//
// Created by Rohan Rodrigues on 12/10/20.
//

#ifndef FINAL_PROJECT_AIRPORT_H
#define FINAL_PROJECT_AIRPORT_H

#include <vector>
#include "readFromFile.hpp"
#include "airport.h"
#include "route.h"
#include "airline.h"
#include <string>

using namespace std;

class Airport {
public:
    Airport(string name);
    Airport(string name, string id);
    Airport(string id, string name, string city, string country, std::pair<int, int> location);
    ~Airport();

    void addOutgoingRoute(Route * route);
    string getId();

private:
    string id;
    string name;
    string city;
    string country;
    pair<int, int> location; //latitude and longtitude
    vector<Route *> outgoingRoutes;

    bool fromAirportData; // to check if this class was created using data from the airport data file or from the
    // routes data file
};


#endif //FINAL_PROJECT_AIRPORT_H
