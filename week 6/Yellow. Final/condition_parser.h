#pragma once

#include <memory>
#include <iostream>
#include <sstream>
#include <algorithm>
#include "node.h"


using namespace std;

shared_ptr<Node> ParseCondition(istream& is);

void TestParseCondition();

string turn_to_string(istream& is);
