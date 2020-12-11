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


//Analytics::Analytics(vector<string> routes_vector) {
//    vector<Route *> routes;
//    cout << "Reached " << __LINE__ << endl;
//
//    for (unsigned int i = 0; i < routes_vector.size(); i++) {
//        vector<string> route_content = split(routes_vector[i], ',');
//
//      //  Airline * airline = new Airline(route_content[0], route_content[1]);
//      string airlineCode = route_content[0];
//      string airlineId = route_content[1];
//
////        Airport sourceAirport = Airport(route_content[2], route_content[3]);
////        Airport destinationAirport = Airport(route_content[4], route_content[5]);
//        string sourceAirport = route_content[3];
//        if (sourceAirport == "\\N") {
//            continue;
//        }
//        string destinationAirport = route_content[5];
//
//        string stops = route_content[7];
////        stringstream stopStream(route_content[7]);
////        int stops = 0;
////        stopStream >> stops;
//
//        Route * route = new Route(airlineId, airlineCode, sourceAirport, destinationAirport, stops);
//        routes.push_back(route);
//    }
//
//    cout << "Reached " << __LINE__ << endl;
//
//    // sort the list of routes based on airport
//    //vector<Route *> sortedRoutes = routes;
//    sortRoutes(routes);
//    compileAirports(routes);
//    cout << "Reached " << __LINE__ << endl;
//
////    cout << "Reached " << __LINE__ << endl;
////
////    cout << "Unsorted Routes: " << endl;
////    for (unsigned int i = 0; i < routes.size(); i++) {
////        cout << routes[i]->getSourceAirport() << endl;
////    }
//
//}




Analytics::Analytics(vector<string> routes_vector) {

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
        Airport * airport = new Airport(route_content[2], sourceAirport);
//        if airports.contain()
        airports.push_back(airport);
    }

    cout << "Reached " << __LINE__ << endl;

    // sort the list of routes based on airport
    //vector<Route *> sortedRoutes = routes;
    sortRoutes(routes);
    compileAirports(routes);
    cout << "Reached " << __LINE__ << endl;

//    cout << "Reached " << __LINE__ << endl;
//
//    cout << "Unsorted Routes: " << endl;
//    for (unsigned int i = 0; i < routes.size(); i++) {
//        cout << routes[i]->getSourceAirport() << endl;
//    }

}











void Analytics::compileAirports(vector<Route *> & routes) {
    cout << "Reached " << __LINE__ << endl;
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

    cout << "Reached " << __LINE__ << endl;

        cout << "Airport List: " << endl;
        for (unsigned int i = 0; i < airports.size(); i++) {
            cout << airports[i]->getId() << endl;
        }
}




vector<Airport> Analytics::get_airports() {
//    if (routes.size() == 0) return vector<Airport>();
//
//    vector<Route> bfs;
//    vector<bool> visited;
//    vector<Airport> airports;
//
//    for (int i = 0; i < routes.size(); i++) {
//        visited.push_back(false);
//    }
//
//    bfs.push_back(0);
//    visited[0] = true;

//    while (!bfs.empty()) {
//        currentIndex = bfs.front();
//        bfs.pop();
//        visited[currentIndex] = true;
//
//        for (int i = 0; i < )
//
////        for all neighbours w of v in Graph G
////        if w is not visited
////        Q.enqueue( w )
//    }
    return vector<Airport>();
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
//   for (unsigned int i = 0; i < routes.size(); i++) {
//       delete routes[i];
//   }
    for (unsigned int i = 0; i < airports.size(); i++) {
        delete airports[i];
    }
}