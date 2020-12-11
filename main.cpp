#include <iostream>
#include <vector>
#include "readFromFile.hpp"
#include "flight_analytics.h"
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
	std::cout << "Filename: " << argv[1] << std::endl;
	
	// convert file to string representation
//	std::cout << "String Representation:" << std::endl;
//	std::cout << file_to_string(argv[1]) << std::endl;
	
	// convert file to vector representation
//	std::cout << "Vector Representation:" << std::endl;
//	std::vector<std::string> vectorRepr = file_to_vector(argv[1]);
//	for (auto word : vectorRepr) {
//		std::cout << word << std::endl;
//	}

    vector<string> vectorRepr = file_to_vector(argv[1]);
    Analytics * a = new Analytics(vectorRepr);
    delete a;
}
