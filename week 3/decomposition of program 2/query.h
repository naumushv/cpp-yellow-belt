#pragma once
/*
 * query.h
 *
 *  Created on: Oct 15, 2020
 *      Author: yosh
 */

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

enum class QueryType {
  NewBus,
  BusesForStop,
  StopsForBus,
  AllBuses
};

struct Query {
  QueryType type;
  std::string bus;
  std::string stop;
  std::vector<std::string> stops;
};


std::istream& operator >> (std::istream& is, Query& q);
