#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <cmath>

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

/*int GetDistinctRealRootCount(double a, double b, double c) {

	  double x1, x2, discriminant, realPart, imaginaryPart;
	    discriminant = b*b - 4*a*c;
	    if (discriminant > 0) {
	        x1 = (-b + sqrt(discriminant)) / (2*a);
	        x2 = (-b - sqrt(discriminant)) / (2*a);
	    	if (x1==x2 || (a==0)) return 1;
	    		    	else return 2;
//	        cout << "Roots are real and different." << endl;
//	        cout << "x1 = " << x1 << endl;
//	        cout << "x2 = " << x2 << endl;
	    }

	    else if (discriminant == 0) {
	        if (a==0) return 0;
	        else return 1;
//	        x1 = (-b) / (2*a);
	    }

	    else {
	        realPart = -b/(2*a);
	        imaginaryPart =sqrt(-discriminant)/(2*a);
	    	if ((realPart+imaginaryPart)==(realPart-imaginaryPart) || (a==0 ))
	    		return 1;
	    		    	else return 2;
//	        cout << "Roots are complex and different."  << endl;
	    }
}
*/

void Test1(){
	AssertEqual(GetDistinctRealRootCount(2,-5,-3), 2, "2,-5,-3 ");
}

void Test2(){
	AssertEqual(GetDistinctRealRootCount(0,-5,-3), 1, "0,-5,-3 ");
}

void Test3(){
	AssertEqual(GetDistinctRealRootCount(0,0,-3), 0, "0,0,-3 ");
}

void Test4(){
	AssertEqual(GetDistinctRealRootCount(11,-2,0), 2, "11,-2,0 ");
}
void Test5(){
	AssertEqual(GetDistinctRealRootCount(11,0,0), 1, "11,0,0 ");
}
void Test6(){
	AssertEqual(GetDistinctRealRootCount(0,-2,0), 1, "11,-2,0 ");
}

void Test7(){
	AssertEqual(GetDistinctRealRootCount(-4,-2,0), 2, "-4,-2,0 ");
}

void Test8(){
	AssertEqual(GetDistinctRealRootCount(7,48,7), 2, "7,48,7 ");
}
void Test9(){
	AssertEqual(GetDistinctRealRootCount(9,-15,4), 2, "9,-15,4 ");
}
void Test10(){
	AssertEqual(GetDistinctRealRootCount(25,10,-1), 2, "25,10,-1 ");
}
void Test11(){
	AssertEqual(GetDistinctRealRootCount(9,-73,8), 2, "9,-73,8 ");
}
void Test12(){
	AssertEqual(GetDistinctRealRootCount(2,-3,-2), 2, "2,-3,-2 ");
}
void Test13(){
	AssertEqual(GetDistinctRealRootCount(56,-15,1), 2, "56,-15,1 ");
}
void Test15(){
	AssertEqual(GetDistinctRealRootCount(25,-0.333,-1), 2, "25,-0.333,-1 ");
}
void Test16(){
	AssertEqual(GetDistinctRealRootCount(0,-0.333,-1), 1, "0,-0.333,-1 ");
}
void Test17(){
	AssertEqual(GetDistinctRealRootCount(1,-0.333,0), 2, "1,-0.333,0 ");
}
void Test18(){
	AssertEqual(GetDistinctRealRootCount(5,-0.333,0), 2, "5,-0.333,0 ");
}
void Test19(){
	AssertEqual(GetDistinctRealRootCount(0.333,-0.333,0), 2, "0.333,-0.333,0 ");
}
void Test20(){
	AssertEqual(GetDistinctRealRootCount(0.333,0,0), 1, "0.333,0,0 ");
}
void Test21(){
	AssertEqual(GetDistinctRealRootCount(0.333,0,4), 2, "0.333,0,4 ");
}
void Test22(){
	AssertEqual(GetDistinctRealRootCount(0,0,0.333), 0, "0,0,0.333 ");
}
void Test23(){
	AssertEqual(GetDistinctRealRootCount(0,-3,0.333), 1, "0,-3,0.333 ");
}
void Test24(){
	AssertEqual(GetDistinctRealRootCount(-3,0,0.333), 2, "0,-3,0.333 ");
}



void TestAll(){

	cout << GetDistinctRealRootCount(-3,0,0.333) << endl;
	TestRunner runner;
	runner.RunTest(Test1, "Test1");
	runner.RunTest(Test2, "Test2");
	runner.RunTest(Test3, "Test3");
	runner.RunTest(Test4, "Test4");
	runner.RunTest(Test5, "Test5");
	runner.RunTest(Test6, "Test6");
	runner.RunTest(Test7, "Test7");
	runner.RunTest(Test8, "Test8");
	runner.RunTest(Test9, "Test9");
	runner.RunTest(Test10, "Test10");
	runner.RunTest(Test11, "Test11");
	runner.RunTest(Test12, "Test12");
	runner.RunTest(Test13, "Test13");
	runner.RunTest(Test15, "Test15");
	runner.RunTest(Test16, "Test16");
	runner.RunTest(Test17, "Test17");
	runner.RunTest(Test18, "Test18");
	runner.RunTest(Test19, "Test19");
	runner.RunTest(Test20, "Test20");
	runner.RunTest(Test21, "Test21");
	runner.RunTest(Test22, "Test22");
	runner.RunTest(Test23, "Test23");
	runner.RunTest(Test24, "Test24");
}

int main() {

		AssertEqual(GetDistinctRealRootCount(2,-5,-3), 2, "2,-5,-3 ");
		AssertEqual(GetDistinctRealRootCount(0,-5,-3), 1, "0,-5,-3 ");
		AssertEqual(GetDistinctRealRootCount(0,0,-3), 0, "0,0,-3 ");
		AssertEqual(GetDistinctRealRootCount(11,-2,0), 2, "11,-2,0 ");
		AssertEqual(GetDistinctRealRootCount(11,0,0), 1, "11,0,0 ");
		AssertEqual(GetDistinctRealRootCount(0,-2,0), 1, "11,-2,0 ");
		AssertEqual(GetDistinctRealRootCount(-4,-2,0), 2, "-4,-2,0 ");
		AssertEqual(GetDistinctRealRootCount(7,48,7), 2, "7,48,7 ");
		AssertEqual(GetDistinctRealRootCount(9,-15,4), 2, "9,-15,4 ");
		AssertEqual(GetDistinctRealRootCount(25,10,-1), 2, "25,10,-1 ");
		AssertEqual(GetDistinctRealRootCount(9,-73,8), 2, "9,-73,8 ");
		AssertEqual(GetDistinctRealRootCount(2,-3,-2), 2, "2,-3,-2 ");
		AssertEqual(GetDistinctRealRootCount(56,-15,1), 2, "56,-15,1 ");
		AssertEqual(GetDistinctRealRootCount(25,-0.333,-1), 2, "25,-0.333,-1 ");
		AssertEqual(GetDistinctRealRootCount(0,-0.333,-1), 1, "0,-0.333,-1 ");
		AssertEqual(GetDistinctRealRootCount(1,-0.333,0), 2, "1,-0.333,0 ");
		AssertEqual(GetDistinctRealRootCount(5,-0.333,0), 2, "5,-0.333,0 ");
		AssertEqual(GetDistinctRealRootCount(0.333,-0.333,0), 2, "0.333,-0.333,0 ");
		AssertEqual(GetDistinctRealRootCount(0.333,0,0), 1, "0.333,0,0 ");
		AssertEqual(GetDistinctRealRootCount(0.333,0,4), 0, "0.333,0,4 ");
		AssertEqual(GetDistinctRealRootCount(0,0,0.333), 0, "0,0,0.333 ");
		AssertEqual(GetDistinctRealRootCount(0,-3,0.333), 1, "0,-3,0.333 ");
		AssertEqual(GetDistinctRealRootCount(-3,0,0.333), 2, "0,-3,0.333 ");



  // добавьте сюда свои тесты
  return 0;
}
