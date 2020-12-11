//
// Created by Rohan Rodrigues on 12/10/20.
//

#ifndef FINAL_PROJECT_AIRLINE_H
#define FINAL_PROJECT_AIRLINE_H

#include <vector>
#include "readFromFile.hpp"
#include "airport.h"
#include "route.h"
#include "airline.h"
#include <string>

using namespace std;


class Airline {
public:
    Airline();
    Airline(string id, string name);
    string findAirlines(string id); //returns the name of the airline


private:
    string id;
    string name;
};


#endif //FINAL_PROJECT_AIRLINE_H
