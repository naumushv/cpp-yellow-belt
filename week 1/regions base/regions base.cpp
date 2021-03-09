#include <iostream>
#include <limits>
#include <vector>
#include <map>
#include <tuple>
using namespace std;

/*enum class Lang {
  DE, FR, IT
};

struct Region {
  string std_name;
  string parent_std_name;
  map<Lang, string> names;
  int64_t population;
};*/

bool operator==(const Region& one, const Region& two){
	auto one_tup = make_tuple(one.std_name, one.parent_std_name, one.names, one.population);
	auto two_tup = make_tuple(two.std_name, two.parent_std_name, two.names, two.population);
	return one_tup == two_tup;
}

bool operator<(const Region& one, const Region& two){
	auto one_tup = make_tuple(one.std_name, one.parent_std_name, one.names, one.population);
	auto two_tup = make_tuple(two.std_name, two.parent_std_name, two.names, two.population);
	return one_tup < two_tup;
}

int FindMaxRepetitionCount(const vector<Region>& regions){
	if (regions.size() == 0) return 0;
	else
	if (regions.size() == 1) return 1;
	int biggest = 1, repetition = 1;
	map<Region, int> srch;
	for (int k = 0; k < static_cast<int>(regions.size()); k++){
		srch[regions.at(k)]++;
	}
	for (auto& item:srch){
		if (item.second > biggest) biggest = item.second;
	}

	return biggest;


}

int main() {

/*	Region one = {   "Moscow",
	        "Russia",
	        {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
	        89
	    };
Region two = {
        "Moscow",
        "NotRussia",
        {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
        89
    };

	bool comparison = one == two;
	cout << comparison << endl;
	*/

	cout << FindMaxRepetitionCount({
	      {
	          "Moscow",
	          "Russia",
	          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
	          89
	      }, {
	          "Russia",
	          "Eurasia",
	          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
	          89
	      }, {
	          "Moscow",
	          "Russia",
	          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
	          89
	      }, {
	          "Moscow",
	          "Russia",
	          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
	          89
	      }, {
	          "Russia",
	          "Eurasia",
	          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
	          89
	      },
	  }) << endl;

	cout << FindMaxRepetitionCount({
	      {
	          "Moscow",
	          "Russia",
	          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
	          89
	      }, {
	          "Russia",
	          "Eurasia",
	          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
	          89
	      }, {
	          "Moscow",
	          "Russia",
	          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
	          89
	      }, {
	          "Moscow",
	          "Toulouse",
	          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
	          89
	      }, {
	          "Moscow",
	          "Russia",
	          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
	          31
	      },
	  }) << endl;


  return 0;
}
