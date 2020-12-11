//
// Created by Rohan Rodrigues on 12/10/20.
//

#ifndef FINAL_PROJECT_FLIGHT_ANALYTICS_H
#define FINAL_PROJECT_FLIGHT_ANALYTICS_H

#include <vector>
#include "readFromFile.hpp"
#include "airport.h"
#include "route.h"
#include "airline.h"
#include <string>
#include <iostream>

using namespace std;


class Analytics {
public:
    Analytics(vector<string> routes_vector);
    vector<Airport> get_airports(); // BFS algorithm - doesn't use airports file since it would be too easy (uses routes file instead)

//    Airline determine_airline(string airportA, string airportB); // Djisktras or A* search algorithm - finds airline with the
//    // least number of stops between the two airport

  //  int getNumConnectedAirports(string airline); // DFS algorithm - finds the number of disjointed groups connected by a specific airline

//    vector<string> getQuickestFlightPath(string airportA, string airportB); // Djisktras or A* search algorithm - finds airline with the
////    // least number of stops between the two airports
//
//    vector<string> getQuickestFlightPathThroughCountry(string airportA, string airportB, string countryA); // Landmark Path algorithm - finds airline with the
////    // least distance traveled between two airports
//
//    vector<Airport> getLongestPath();

    ~Analytics();

private:
    //vector<Route *> routes;
    vector<Airport *> airports;

    void sortRoutes(vector<Route *> & routes);
    vector<string> split(string s, char delim);
    void compileAirports(vector<Route *> & routes);

};


#endif //FINAL_PROJECT_FLIGHT_ANALYTICS_H
