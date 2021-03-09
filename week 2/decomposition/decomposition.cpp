#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>
#include <utility>
#include <tuple>

using namespace std;

enum class QueryType {
  NewBus,
  BusesForStop,
  StopsForBus,
  AllBuses
};

struct Query {
  QueryType type;
  string bus;
  string stop;
  vector<string> stops;
};

istream& operator >> (istream& is, Query& q) {
	vector<string> empty;
	q.bus = "";
	q.stop = "";
	q.stops = empty;
	string qr_type;
	is >> qr_type;
	if (qr_type == "NEW_BUS"){
		q.type = QueryType::NewBus;
		int stop_count;
		is >> q.bus >> stop_count;
		for (int i = 0; i < stop_count; i++){
			is >> q.stop;
			q.stops.push_back(q.stop);
		}
	}
	else if (qr_type == "BUSES_FOR_STOP"){
		q.type = QueryType::BusesForStop;
		is >> q.stop;
	}
	else if (qr_type == "STOPS_FOR_BUS"){
		q.type = QueryType::StopsForBus;
		is >> q.bus;
	}
	else if (qr_type == "ALL_BUSES"){
		q.type = QueryType::AllBuses;
	}

return is;
}

struct BusesForStopResponse {
	string no_stop = "No stop";
	vector<string> answer;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
	if (r.answer.size() == 0) os << r.no_stop ;
	else {
	for (const string& bus : r.answer) {
			  os << bus << " ";
			}
//		os << endl;
	}
  return os;
}

struct StopsForBusResponse {
	string no_bus = "No bus";
	vector<pair<string, vector<string>>> answer;
	//	map<string, vector<string>> answer;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
	if (r.answer.empty() ) os << r.no_bus;
		else {
			int i=0, size = r.answer.size();
	        for (const auto& stop : r.answer) {
	          os << "Stop " << stop.first << ": ";
	            for (const string& other_bus : stop.second) {
	                os << other_bus << " ";
	              }
	            ++i;
	            if (i < size)
	          os << endl;
	          }
	        }
  return os;
}

struct AllBusesResponse {
	string no_buses = "No buses";
	map<string, vector<string>> answer;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
    if (r.answer.empty()) {
      os << "No buses";
    } else {
      for (const auto& bus_item : r.answer) {
        os << "Bus " << bus_item.first << ": ";
        for (const string& stop : bus_item.second) {
          os << stop << " ";
        }
        os << endl;
      }
    }

  return os;
}

class BusManager {
public:
  void AddBus(const string& bus, const vector<string>& stops) {

	  for (const string& stop : stops) {
				buses_to_stops[bus].push_back(stop);
				stops_to_buses[stop].push_back(bus);
	        }
  }

  BusesForStopResponse GetBusesForStop(const string& stop) const {
	  	  BusesForStopResponse bb;
	        if (stops_to_buses.count(stop) == 0) {}
	        else {
	          for (const string& bus : stops_to_buses.at(stop)) {
	        	  bb.answer.push_back(bus);
	          }
	        }
	        return bb;
  }

  StopsForBusResponse GetStopsForBus(const string& bus) const {

	  StopsForBusResponse ss;
      if (buses_to_stops.count(bus) == 0) {}
      else {
        for (const string& stop : buses_to_stops.at(bus)) {
			  vector<string> vec;
          if (stops_to_buses.at(stop).size() == 1) {
        	  vec.push_back("no interchange");
          } else {
            for (const string& other_bus : stops_to_buses.at(stop)) {
              if (bus != other_bus) {
            	  vec.push_back(other_bus);
              }
            }
          }
          ss.answer.push_back(make_pair(stop, vec));
        }
      }
      return ss;
  }

  AllBusesResponse GetAllBuses() const {

	  AllBusesResponse bb;
      if (buses_to_stops.empty()) {}
      else {

    	  bb.answer = buses_to_stops;
      }
  return bb;

    }
private:
  map<string, vector<string>> buses_to_stops, stops_to_buses;
};

int main() {
  int query_count;
  Query q;

  cin >> query_count;

  BusManager bm;
  for (int i = 0; i < query_count; ++i) {
    cin >> q;
    switch (q.type) {
    case QueryType::NewBus:
      bm.AddBus(q.bus, q.stops);
      break;
    case QueryType::BusesForStop:
      cout << bm.GetBusesForStop(q.stop) << endl;
      break;
    case QueryType::StopsForBus:
      cout << bm.GetStopsForBus(q.bus) << endl;
      break;
    case QueryType::AllBuses:
      cout << bm.GetAllBuses() << endl;
      break;
    }
  }

  return 0;
}
