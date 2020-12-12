//
// Created by Rohan Rodrigues on 12/10/20.
//

#include <vector>
#include "readFromFile.hpp"
#include "airport.h"
#include "route.h"
#include "airline.h"
#include <string>

using namespace std;

Airport::Airport(string name) {
    this->name = name;
    this->fromAirportData = false;
}


Airport::Airport(string name, string id) {
    this->name = name;
    this->id = id;
    this->fromAirportData = false;
}


Airport::Airport(string id, string name, string city, string country, std::pair<int, int> location) {
    this->id = id;
    this->name = name;
    this->city = city;
    this->country = country;
    this->location = location;
    this->fromAirportData = true;
}

Airport::~Airport() {
    if (!fromAirportData) {
        for (unsigned int i = 0; i < outgoingRoutes.size(); i++) {
            delete outgoingRoutes[i];
        }
    }
}

void Airport::addOutgoingRoute(Route * route) {
    outgoingRoutes.push_back(route);
}


string Airport::getId() {
    return id;
}

vector<Route *> & Airport::getOutgoingRoutes() {
    return outgoingRoutes;
}