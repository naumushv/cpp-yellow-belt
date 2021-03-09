#pragma once

#include <string>
#include <exception>
#include <stdexcept>
#include <sstream>
#include <iostream>
#include <vector>

using std::ostream;
using std::vector;
using std::string;

ostream& operator<< (ostream& ss, const vector<string>& s);

template<class T, class U>
void AssertEqual(const T& t, const U& u,
    const std::string& hint)
{
  if (t != u) {
	  std::ostringstream os;
    os << "Assertion failed: " << t << " != " << u << " hint: " << hint;
    throw std::runtime_error(os.str());
  }
}


inline void Assert(bool b, const std::string& hint) {
	AssertEqual(b, true, hint);
}
class TestRunner {
public:
    template <typename TestFunc> void
	RunTest(TestFunc func, const std::string& test_name)
    {
           try {
               func();
               std::cerr << test_name << " OK" << std::endl;
           } catch (std::runtime_error& e) {
               ++fail_count;
               std::cerr << test_name << " fail: " << e.what() << std::endl;
           }
       }




private:
    int fail_count = 0;
};
