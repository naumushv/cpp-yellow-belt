#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
      os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};


/*
class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
	  fn[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
	  ln[year] = last_name;
  }
  string GetFullName(int year) {
	  string result,n="",f="";
	  bool empty = ln.empty() && fn.empty();
	  if ((year<=fn.begin()->first && year<=ln.begin()->first) || empty){
		  return "Incognito";
	  }
	  else {
		  for (auto i:fn)
			  if (i.first<=year) n=i.second;
		  for (auto k:ln)
			  if (k.first<=year) f=k.second;
		  if (n=="" && f=="")
			  return "Incognito";
		  else
			  if (n!="" && f=="")
				  return {n + " with unknown last name"};
			  else
				  if(n=="" && f!="")
					  return { f + " with unknown first name"};
				  else return { n + " " + f};
//	  }

  }
  }
private:
  map<int, string> fn;
  map<int, string> ln;
};
*/

Person human;

void nothingAtStart(){
	for (int t:{100, 200, 300, 400}){
		AssertEqual(human.GetFullName(t), "Incognito", "#nothingAtStart");
	}
}

void CheckFN(){
	for (int t:{100, 200, 300}){
			AssertEqual(human.GetFullName(t), "Ivan with unknown last name", "CheckFN");
		}
}

void CheckSN(){
	for (int t:{10, 20, 30, 49}){
			AssertEqual(human.GetFullName(t), "Ivanov with unknown first name", "#CheckSN");
		}
}

void Incognito(){
	for (int t:{1,2,3,4,5,6,7,8,9}){
		AssertEqual(human.GetFullName(t), "Incognito", "#Incognito");
	}
}

void CheckFirst(){
	for (int t:{50, 100, 200, 1000000}){
		AssertEqual(human.GetFullName(t), "Ivan Ivanov", "#CheckFirst");
	}
}
void CheckFirstChange(){
	for (int t:{200, 201, 300}){
		AssertEqual(human.GetFullName(t), "Pavel Ivanov", "#CheckFirstChange");
	}
	for (int t:{50, 101, 199}){
			AssertEqual(human.GetFullName(t), "Ivan Ivanov", "#CheckFirstChange");
		}
}

void CheckSecond(){
	for (int t:{301, 350, 900}){
		AssertEqual(human.GetFullName(t), "Pavel Pavlov", "#CheckSecond");
	}
}

void CheckSecondChange(){
	for (int t:{200, 291, 299}){
			AssertEqual(human.GetFullName(t), "Pavel Ivanov", "#CheckSecondChange");
		}
}


int main() {
  TestRunner runner;

  runner.RunTest(nothingAtStart, "nothingAtStart");
  human.ChangeFirstName(50, "Ivan");
  runner.RunTest(CheckFN, "CheckFN");
  human.ChangeLastName(10, "Ivanov");
  runner.RunTest(CheckSN, "CheckSN");
  runner.RunTest(Incognito, "Incognito");
  runner.RunTest(CheckFirst, "CheckFirst");
  human.ChangeFirstName(200, "Pavel");
  runner.RunTest(CheckFirstChange, "CheckFirstChange");
  human.ChangeLastName(301, "Pavlov");
  runner.RunTest(CheckSecond, "CheckSecond");
  runner.RunTest(CheckSecondChange, "CheckSecondChange");
  runner.RunTest(Incognito, "Incognito");
  runner.RunTest(CheckSN, "CheckSN");



  return 0;
}
