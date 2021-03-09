#pragma once
#include <sstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

class Date {
 public:
  Date();
  explicit Date(const std::string& input_date);
  Date(int year, int month, int day);

  int GetYear() const;
  int GetMonth() const;
  int GetDay() const;

  Date& operator=(const Date& rhs);

  std::string GetDate(char separator = '-') const;

 private:
  int year_;
  int month_;
  int day_;

  void CheckFormat(const std::string &input, char separator = '-');
  bool CheckNumber(std::stringstream& ss, int& number);

  void CheckData();
};

bool operator<(const Date& lhs, const Date& rhs);

bool operator<=(const Date& lhs, const Date& rhs);

bool operator>(const Date& lhs, const Date& rhs);

bool operator>=(const Date& lhs, const Date& rhs);

bool operator==(const Date& lhs, const Date& rhs);

bool operator!=(const Date& lhs, const Date& rhs);

std::ostream& operator<<(std::ostream& ostream, const Date& date);

Date ParseDate(std::istream& input);

bool date_check(int year, int month, int day);
