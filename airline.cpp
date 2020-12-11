//
// Created by Rohan Rodrigues on 12/10/20.
//

#include <vector>
#include "readFromFile.hpp"
#include "airport.h"
#include "route.h"
#include "airline.h"
#include <string>


Airline::Airline() {

}

Airline::Airline(string id, string name) {
    this->id = id;
    this->name = name;
}