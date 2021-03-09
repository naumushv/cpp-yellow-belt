#pragma once
#include "date.h"
#include <string>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

class Database {
public:
	Database(){};
	void Add(const Date& date, const std::string& event);
	void Print(std::ostream& out) const;
	std::string Last(const Date& date) const;

	template <typename Predicate>
	  std::vector<std::string> FindIf(Predicate predicate) const {
	    std::vector<std::string> result;
	    for (const auto& date : db) {
	      for (const auto& event : date.second.data_vector) {
	        if (predicate(date.first, event)) {
	          std::string bufer = date.first.GetDate() + " " + event;
	          result.push_back(bufer);
	        }
	      }
	    }
	    return result;
	  }

	 template <typename Predicate>
	  int RemoveIf(Predicate predicate) {
	    int count = 0;
	    for(auto date = db.begin(); date != db.end(); ) {
	      if (predicate(date->first, "")) {
	        count += date->second.data_vector.size();
	        date = db.erase(date);
	      }
	      else {
	        auto new_predicate = [date, predicate](const std::string& event) { return !predicate(date->first, event);};
	        auto start = std::stable_partition(date->second.data_vector.begin(), date->second.data_vector.end(), new_predicate);
	        if (start == date->second.data_vector.begin()) {
	          count += date->second.data_vector.size();
	          date = db.erase(date);
	        }
	        else if (start != date->second.data_vector.end()) {
	          for (auto curr = --date->second.data_vector.end(); curr != prev(start); curr--) {
	            date->second.data_vector.pop_back();
	            date->second.data_set.erase(*curr);
	            count++;
	          }
	          if(date->second.data_vector.empty()) date = db.erase(date);
	          else ++date;
	        }
	        else {
	          ++date;
	        }
	      }
	    }
	    return count;
	  }

private:
	struct Events {
	    std::vector<std::string> data_vector;
	    std::set<std::string> data_set;
	  };
	std::map<Date, Events> db;
};
