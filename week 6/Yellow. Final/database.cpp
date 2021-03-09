#include "database.h"

void Database::Add(const Date& date, const std::string& event){
	auto added = db[date].data_set.insert(event);
	if (added.second)
		db[date].data_vector.push_back(event);
}

void Database::Print(std::ostream &out) const {
  for (const auto& date : db) {
    for (const auto& event : date.second.data_vector) {
      out << date.first.GetDate() << " " << event << std::endl;
    }
  }
}


std::string Database::Last(const Date &date) const {
  auto last = db.upper_bound(date);
  if (last == db.begin()) {
    return "No entries";
  }
  else {
    last = prev(last);
    return last->first.GetDate() + " " + last->second.data_vector.back();
  }
}
