#include "date.h"

Date ParseDate(std::istream& input) {
	  std::string bufer;
	  input >> bufer;
	  input.get();
	  return Date(bufer);
}

Date::Date() : year_(0), month_(0), day_(0) {}

Date::Date(const std::string &input_date) {
  CheckFormat(input_date);
  CheckData();
}

Date::Date(int year, int month, int day) : year_(year), month_(month), day_(day) {
  CheckData();
}

int Date::GetYear() const { return year_; }

int Date::GetMonth() const { return month_; }

int Date::GetDay() const { return day_; }

Date& Date::operator=(const Date& rhs) {
  year_ = rhs.year_;
  month_ = rhs.month_;
  day_ = rhs.day_;
  return *this;
}

std::string Date::GetDate(char separator) const {
  std::stringstream so;
  so << std::setfill('0');
  if (year_ < 0) {
    so << '-';
  }
  so << std::setw(4) << abs(year_);
  so << separator;
  so << std::setw(2) << month_;
  so << separator;
  so << std::setw(2) << day_;
  return so.str();
}


void Date::CheckFormat(const std::string &input, char separator) {
  std::stringstream ss(input);
  int count_data = 3;
  int date_data[3] = {-1, -1, -1};

  if (!CheckNumber(ss, date_data[0])) {
    std::stringstream so;
    so << "Wrong date format: " << input;
    throw std::runtime_error(so.str());
  }

  char input_date_separator = '-';
  for (int i = 1; i < count_data; ++i) {
    if (ss.peek() != separator) {
      std::stringstream so;
      so << "Wrong date format: " << input;
      throw std::runtime_error(so.str());
    }
    else {
      ss.ignore(1);
      if (!CheckNumber(ss, date_data[i])) {
        std::stringstream so;
        so << "Wrong date format: " << input;
        throw std::runtime_error(so.str());
      }
    }
  }

  if (ss.rdbuf()->in_avail() != 0) {
    std::stringstream so;
    so << "Wrong date format: " << input;
    throw std::runtime_error(so.str());
  }
  year_ = date_data[0];
  month_ = date_data[1];
  day_ = date_data[2];
}

bool Date::CheckNumber(std::stringstream& ss, int& number) {
  if (ss.peek() == '+' || ss.peek() == '-') {
    return false;
  }
  else if (ss.peek() >= '0' && ss.peek() <= '9') {
    ss >> number;
  }
  else {
    return false;
  }
  return true;
}

void Date::CheckData() {

  if (year_ < 0) {
    std::stringstream ss;
    ss << "Year value is invalid: " << month_;
    throw std::runtime_error(ss.str());
  }

  if (month_ < 1 || month_ > 12) {
    std::stringstream ss;
    ss << "Month value is invalid: " << month_;
    throw std::runtime_error(ss.str());
  }

  if (day_ < 1 || day_ > 31) {
    std::stringstream ss;
    ss << "Day value is invalid: " << day_;
    throw std::runtime_error(ss.str());
  }
}

bool operator<(const Date& lhs, const Date& rhs) {
  int l_year = lhs.GetYear(), l_month = lhs.GetMonth(), l_day = lhs.GetDay();
  int r_year = rhs.GetYear(), r_month = rhs.GetMonth(), r_day = rhs.GetDay();
  return (std::tie(l_year, l_month, l_day) < std::tie(r_year, r_month, r_day));
}

bool operator<=(const Date& lhs, const Date& rhs) {
  int l_year = lhs.GetYear(), l_month = lhs.GetMonth(), l_day = lhs.GetDay();
  int r_year = rhs.GetYear(), r_month = rhs.GetMonth(), r_day = rhs.GetDay();
  return (std::tie(l_year, l_month, l_day) <= std::tie(r_year, r_month, r_day));
}

bool operator>(const Date& lhs, const Date& rhs) {
  int l_year = lhs.GetYear(), l_month = lhs.GetMonth(), l_day = lhs.GetDay();
  int r_year = rhs.GetYear(), r_month = rhs.GetMonth(), r_day = rhs.GetDay();
  return (std::tie(l_year, l_month, l_day) > std::tie(r_year, r_month, r_day));
}

bool operator>=(const Date& lhs, const Date& rhs) {
  int l_year = lhs.GetYear(), l_month = lhs.GetMonth(), l_day = lhs.GetDay();
  int r_year = rhs.GetYear(), r_month = rhs.GetMonth(), r_day = rhs.GetDay();
  return (std::tie(l_year, l_month, l_day) >= std::tie(r_year, r_month, r_day));
}

bool operator==(const Date& lhs, const Date& rhs) {
  int l_year = lhs.GetYear(), l_month = lhs.GetMonth(), l_day = lhs.GetDay();
  int r_year = rhs.GetYear(), r_month = rhs.GetMonth(), r_day = rhs.GetDay();
  return (std::tie(l_year, l_month, l_day) == std::tie(r_year, r_month, r_day));
}

bool operator!=(const Date& lhs, const Date& rhs) {
  int l_year = lhs.GetYear(), l_month = lhs.GetMonth(), l_day = lhs.GetDay();
  int r_year = rhs.GetYear(), r_month = rhs.GetMonth(), r_day = rhs.GetDay();
  return (std::tie(l_year, l_month, l_day) != std::tie(r_year, r_month, r_day));
}

std::ostream& operator<<(std::ostream& ostream, const Date& date) {
  ostream << date.GetDate();
  return ostream;
}


