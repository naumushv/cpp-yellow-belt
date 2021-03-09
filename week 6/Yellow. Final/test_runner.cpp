#include "test_runner.h"

ostream& operator<< (ostream& ss, const vector<string>& s){
	for (const auto& it : s){
		ss << it;
	}

	return ss;
}
