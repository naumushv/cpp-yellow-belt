#pragma once
/*
 * responses.h
 *
 *  Created on: Oct 15, 2020
 *      Author: yosh
 */
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <map>

using namespace std;

struct BusesForStopResponse {
	std::vector<std::string> buses;
};

struct StopsForBusResponse {
	std::string bus;
	std::vector<std::pair<std::string, std::vector<std::string>>> stops_for_buses;
};

struct AllBusesResponse {
	map<string, vector<string>> buses_to_stops;
};

std::ostream& operator << (std::ostream& os, const BusesForStopResponse& r);

std::ostream& operator << (std::ostream& os, const StopsForBusResponse& r) ;

std::ostream& operator << (std::ostream& os, const AllBusesResponse& r);
