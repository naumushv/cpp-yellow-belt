/*
 * phone.cpp
 *
 *  Created on: Oct 14, 2020
 *      Author: yosh
 */

#include "phone_number.h"
#include <sstream>


  PhoneNumber::PhoneNumber(const string &n1){
	  stringstream n1_s(n1);
	  	char fir;
	  	bool incorrect = 0;
	  	n1_s >> fir;
	  	getline(n1_s, country_code_, '-');
	  	getline(n1_s, city_code_, '-');
	  	if (fir != '+' || n1_s.eof() || !country_code_.size() || !city_code_.size()) incorrect = 1;
	  	n1_s >> local_number_;
	  	if (!n1_s.eof() || !local_number_.size()){
	  		incorrect = 1;
	  	}

	  	if (incorrect) throw invalid_argument("incorrect format");

  }

  string PhoneNumber::GetCountryCode() const{
	  return country_code_;
  }
  string PhoneNumber::GetCityCode() const{
	  return city_code_;
  }
  string PhoneNumber::GetLocalNumber() const{
	  return local_number_;
  }
  string PhoneNumber::GetInternationalNumber() const{
	  string res = "+"+country_code_+"-"+city_code_+"-"+local_number_;
	  return res;
  }

