//
// Created by Rohan Rodrigues on 12/10/20.
//

#include "flight_analytics.h"
#include <vector>
#include "readFromFile.hpp"
#include "airport.h"
#include "route.h"
#include "airline.h"
#include <string>
#include <iostream>
#include <sstream>


Analytics::Analytics(vector<string> routes_vector) {
    vector<Route *> routes;

    for (unsigned int i = 0; i < routes_vector.size(); i++) {
        vector<string> route_content = split(routes_vector[i], ',');
        string airlineCode = route_content[0];
        string airlineId = route_content[1];
        string sourceAirport = route_content[3];
        if (sourceAirport == "\\N") {
            continue;
        }
        string destinationAirport = route_content[5];

        string stops = route_content[7];
        Route * route = new Route(airlineId, airlineCode, sourceAirport, destinationAirport, stops);
        routes.push_back(route);
    }
    sortRoutes(routes);
    compileAirports(routes);
}


void Analytics::compileAirports(vector<Route *> & routes) {
    Airport * currentAirport;
    for (unsigned int i = 0; i < routes.size(); i++) {
        string airportId = routes[i]->getSourceAirport();

        if (currentAirport == NULL) {
            currentAirport = new Airport(airportId);
            currentAirport->addOutgoingRoute(routes[i]);
        }
        else if (currentAirport->getId() == airportId) {
            currentAirport->addOutgoingRoute(routes[i]);
        }
        else {
            airports.push_back(currentAirport);
            currentAirport = new Airport(airportId);
            currentAirport->addOutgoingRoute(routes[i]);
        }
    }
        Airport * t = airports[0];
        for (unsigned int i = 0; i < t->getOutgoingRoutes().size(); i++) {
            cout << t->getOutgoingRoutes()[i]->getAirlineId() << endl;
        }
}



// BFS algorithm that traverses the graph of Airport Nodes and Route edges to find all airlines
vector<string> Analytics::get_airlines() {
    if (airports.size() == 0) return vector<string>();

    vector<int> bfs;
    vector<bool> visited;
    vector<string> airlines;

    for (unsigned int i = 0; i < airports.size(); i++) {
        visited.push_back(false);
    }

    bfs.push_back(0);
    visited[0] = true;
    int currentIndex = 0;

    while (!bfs.empty()) {
        currentIndex = bfs.front();
        bfs.pop_back();
        visited[currentIndex] = true;

        vector<Route *> & routes = airports[currentIndex]->getOutgoingRoutes();
        for (unsigned int i = 0; i < routes.size(); i++) {
            string airlineCode = routes[i]->getAirlineCode();
            if (!std::count(airlines.begin(), airlines.end(), airlineCode)) {
                airlines.push_back(airlineCode);
            }

            Airport * a = getAirportById(routes[i]->getDestinationAirport());
            int aIndex = getIndexOfAirport(a);
            if (!visited[aIndex]) {
                bfs.push_back(aIndex);
                visited[aIndex] = true;
            }

        }

    }


    return airlines;
}



// Djikstra's Algorithm - finds the quickest path from one airport to another that minimizes the total amount of distance traveled
vector<string> Analytics::getQuickestFlightPath(string airportA, string airportB) {
    if (airports.size() == 0) return vector<string>();

    //vector<int> traversal;
    PriorityQueue<Integer> distancePriorityQueue = new PriorityQueue<>();
    vector<bool> visited;
    vector<int> previousSteps;
    vector<int> distances;

    for (int i = 0; i < airports.size(); i++) {
        visited.push_back(false);
        distances.push_back(INT_MAX);
        previousSteps.push_back(-1);
    }

    int indexOfSource = findAirportIndex(airportA);
    int indexOfDestination = findAirportIndex(airportB);

    distances[indexOfSource] = 0;
    distancePriorityQueue.push(indexOfSource);
    visited[indexOfSource] = true;
    int currentIndex = indexOfSource;

    while (bfs.front() != indexOfDestination) {
        currentIndex = bfs.front();
        bfs.pop();
        vector<Route *> routes = airports[currentIndex].getRoutes();
        visited[currentIndex] = true;


        for (int i = 0; i < routes.size(); i++) {
            Airport a = getAirport(routes[i]->getDestinationAirport());

            int distance = 5;
            // write code to use airport data to get distance

            int aIndex = airports.indexOf(a);
            if (!visited[aIndex]) {
                bfs.push_back(aIndex);
                visited[aIndex] = true;
                distances[aIndex] = distances[currentIndex] + distance;
                previousSteps[aIndex] = currentIndex;
            }
            else {
                if (distances[currentIndex] + distance < distances[aIndex]) {
                    distances[aIndex] = distances[currentIndex] + distance;
                    previousSteps[aIndex] = currentIndex;
                }
            }

        }

    }


    vector<string> finalPath;
    int current_index = indexOfDestination;
    while (current_index != indexOfSource) {
        finalPath.push_back(getAirportName(current_index));
        current_index = previousSteps[current_index];
    }

    finalPath.push_back(getAirportName(current_index));
    std::reverse(finalPath.begin(),finalPath.end());
    return finalPath;
}




// sort the routes based on source airport ID
void Analytics::sortRoutes(vector<Route *> & routeArr) {
    for (unsigned int i = 0; i < routeArr.size()-1; i++) {
        for (unsigned int j = 0; j < routeArr.size()-i-1; j++) {
           // if (routeArr[j]->getSourceAirport().compare(routeArr[j+1]->getSourceAirport()) > 0) {
            if (routeArr[j]->getSourceAirport() > routeArr[j+1]->getSourceAirport()) {
                Route temp = *routeArr[j];
                *routeArr[j] = *routeArr[j+1];
                *routeArr[j+1] = temp;
            }
        }
    }
}


// Helper method created with inspiration from http://www.cplusplus.com/articles/1UqpX9L8/
vector<string> Analytics::split(string s, char delim) {
    vector<string> flds;
    string work = s;
    string buf = "";
    unsigned int i = 0;
    while (i < work.length()) {
        if (work[i] != delim) {
            buf += work[i];
        }
        else {
            flds.push_back(buf);
            buf = "";
        }
        i++;
    }
    if (!buf.empty()) {
        flds.push_back(buf);
    }

    return flds;
}



Analytics::~Analytics() {
    for (unsigned int i = 0; i < airports.size(); i++) {
        delete airports[i];
    }
}


Airport * Analytics::getAirportById(string id) {
    for (unsigned int i = 0; i < airports.size(); i++) {
        if (airports[i]->getId() == id) {
            return airports[i];
        }
    }
    return nullptr;
}


int Analytics::getIndexOfAirport(Airport * a) {
    return binarySearch(airports, 0, airports.size() - 1, a);
}

// Inspiration for code from https://www.geeksforgeeks.org/binary-search/
int Analytics::binarySearch(vector<Airport *> airports, int l, int r, Airport * target) {
    if (r >= l) {
        int mid = l + (r - l) / 2;

        if (airports[mid] == target)
            return mid;

        if (airports[mid] > target)
            return binarySearch(airports, l, mid - 1, target);

        return binarySearch(airports, mid + 1, r, target);
    }

    return -1;
}