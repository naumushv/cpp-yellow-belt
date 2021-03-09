
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

/*enum class Gender {
  FEMALE,
  MALE
};

struct Person {
  int age;  // возраст
  Gender gender;  // пол
  bool is_employed;  // имеет ли работу
};*/

/*template <typename InputIt>
int ComputeMedianAge(InputIt range_begin, InputIt range_end){
	int accum = 0, cnt=0;
	while (range_begin != range_end){
		*range_begin++ += accum;
		++cnt;
	}
	return accum/cnt;
}*/

// Это пример функции, его не нужно отправлять вместе с функцией PrintStats
/*template <typename InputIt>
int ComputeMedianAge(InputIt range_begin, InputIt range_end) {
  if (range_begin == range_end) {
    return 0;
  }
  vector<typename InputIt::value_type> range_copy(range_begin, range_end);
  auto middle = begin(range_copy) + range_copy.size() / 2;
  nth_element(
      begin(range_copy), middle, end(range_copy),
      [](const Person& lhs, const Person& rhs) {
        return lhs.age < rhs.age;
      }
  );
  return middle->age;
}*/

void PrintStats(vector<Person> persons){
	vector<int> meds(7);
	meds.at(0) = ComputeMedianAge(begin(persons), end(persons));
	/*for_each(partition(begin(persons), end(persons), [](Person for_struct){return for_struct.gender == Gender::MALE;}),
			end(persons),
				[](Person brr){ cout << brr.age  << ' '; });*/
	meds.at(1) = ComputeMedianAge(
			partition(begin(persons), end(persons), [](Person for_struct){return for_struct.gender == Gender::MALE;}),
			end(persons));
	meds.at(2) = ComputeMedianAge(
			partition(begin(persons), end(persons), [](Person for_struct){return for_struct.gender == Gender::FEMALE;}),
			end(persons));
	meds.at(3) = ComputeMedianAge(
			partition(begin(persons), end(persons), [](Person for_struct){return (for_struct.gender == Gender::MALE || for_struct.is_employed == false);}),
			end(persons));
	meds.at(4) = ComputeMedianAge(
			partition(begin(persons), end(persons), [](Person for_struct){return (for_struct.gender == Gender::MALE || for_struct.is_employed == true);}),
			end(persons));
	meds.at(5) = ComputeMedianAge(
			partition(begin(persons), end(persons), [](Person for_struct){return (for_struct.gender == Gender::FEMALE || for_struct.is_employed == false);}),
			end(persons));
	meds.at(6) = ComputeMedianAge(
			partition(begin(persons), end(persons), [](Person for_struct){return (for_struct.gender == Gender::FEMALE || for_struct.is_employed == true);}),
			end(persons));
	/*for_each(begin(meds), end(meds),
			[](int i){ cout << i << ' '; });*/
//	for_each(meds.begin(), meds.end(), [](int i){ std::cout << i << ' '; });
	vector<string> ss = {"Median age = ", "Median age for females = ", "Median age for males = ",
			"Median age for employed females = ", "Median age for unemployed females = ", "Median age for employed males = ",
			"Median age for unemployed males = "
	};
	for (int i= 0; i < meds.size(); i++){
		cout << ss.at(i) << meds.at(i) << endl;
	}
/*	Median age = 40
	Median age for females = 40
	Median age for males = 55
	Median age for employed females = 40
	Median age for unemployed females = 80
	Median age for employed males = 55
//	Median age for unemployed males = 78
*/

}

int main() {
  vector<Person> persons = {
	  {31, Gender::MALE, false},
	  {40, Gender::FEMALE, true},
	  {24, Gender::MALE, true},
	  {20, Gender::FEMALE, true},
	  {80, Gender::FEMALE, false},
	  {78, Gender::MALE, false},
	  {10, Gender::FEMALE, false},
	  {55, Gender::MALE, true},
  };
  PrintStats(persons);

  return 0;
}
