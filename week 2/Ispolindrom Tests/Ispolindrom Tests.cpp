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

bool IsPalindrom(string s){
	int i=0;

	if (s.empty()) return true;

	for (int i = 0; i < s.size() / 2; ++i) {
	        if (s[i] != s[s.size() - i - 1]) {
	            return false;
	        }
	    }
	    return true;
}

void All(){
	AssertEqual(IsPalindrom(""), 1, "empty");
	AssertEqual(IsPalindrom("1"), 1, "1");
	AssertEqual(IsPalindrom("q"), 1, "1");
	AssertEqual(IsPalindrom("B"), 1, "1");
	AssertEqual(IsPalindrom("#"), 1, "1");
	AssertEqual(IsPalindrom("#"), 1, "1");
	AssertEqual(IsPalindrom(" "), 1, "1");
	AssertEqual(IsPalindrom("level"), 1, "1");
	AssertEqual(IsPalindrom("ab ba"), 1, "1");
	AssertEqual(IsPalindrom("ab  ba"), 1, "1");
	AssertEqual(IsPalindrom("ab ba  ab ba"), 1, "1");
	AssertEqual(IsPalindrom("ab ba ab ba"), 1, "1");
	AssertEqual(IsPalindrom("a3F D8__ __8D F3a"), 1, "1");
	AssertEqual(IsPalindrom("a3F D8__  __8D F3a"), 1, "1");
	AssertEqual(IsPalindrom("a3F D8____8D F3a"), 1, "1");
	AssertEqual(IsPalindrom("a3F D8___8D F3a"), 1, "1");
	AssertEqual(IsPalindrom("cas sac"), 1, "1");
	AssertEqual(IsPalindrom("c as sa c"), 1, "1");
	AssertEqual(IsPalindrom("c a s s a c"), 1, "1");
	AssertEqual(IsPalindrom("c a s  s a c"), 1, "1");
	AssertEqual(IsPalindrom("c a  s  s  a c"), 1, "1");
	AssertEqual(IsPalindrom("c   a  s  s  a   c"), 1, "1");
	AssertEqual(IsPalindrom("c     a  s s  a     c"), 1, "1");
	AssertEqual(IsPalindrom("101"), 1, "1");
	AssertEqual(IsPalindrom("1001"), 1, "1");
	AssertEqual(IsPalindrom("10001"), 1, "1");
	AssertEqual(IsPalindrom("2100012"), 1, "1");
	AssertEqual(IsPalindrom("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"), 1, "1");
	AssertEqual(IsPalindrom("baaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"), 1, "1");
	AssertEqual(IsPalindrom("b1aaaaaaaaaaaaaaaaaaaaaaaaaaaa1b"), 1, "1");


}

void Not(){
	AssertEqual(IsPalindrom("10"), 0, "no");
	AssertEqual(IsPalindrom("shit"), 0, "no");
	AssertEqual(IsPalindrom("more shit"), 0, "no");
	AssertEqual(IsPalindrom("leve1"), 0, "no");
	AssertEqual(IsPalindrom("1evel"), 0, "no");
	AssertEqual(IsPalindrom("1evel"), 0, "no");
	AssertEqual(IsPalindrom("1ev el"), 0, "no");
	AssertEqual(IsPalindrom("nono"), 0, "no");
	AssertEqual(IsPalindrom("yes yes"), 0, "no");
	AssertEqual(IsPalindrom("yes  yes"), 0, "no");
	AssertEqual(IsPalindrom("y  yes"), 0, "no");
	AssertEqual(IsPalindrom("yes  es"), 0, "no");
	AssertEqual(IsPalindrom("yes  s"), 0, "no");
	AssertEqual(IsPalindrom("yes s"), 0, "no");
	AssertEqual(IsPalindrom("ye s s"), 0, "no");
	AssertEqual(IsPalindrom("y e s s"), 0, "no");
	AssertEqual(IsPalindrom("y #4e 4 s"), 0, "no");
	AssertEqual(IsPalindrom("y e 4 y"), 0, "no");
	AssertEqual(IsPalindrom("y e E y"), 0, "no");
	AssertEqual(IsPalindrom("y E e y"), 0, "no");
	AssertEqual(IsPalindrom("y Ee y"), 0, "no");
	AssertEqual(IsPalindrom("y E__e y"), 0, "no");
	AssertEqual(IsPalindrom("y E_e y"), 0, "no");
	AssertEqual(IsPalindrom("b1aaaaaaaaaaaaaaaaaaaaaaaaaaaaab"), 0, "no");
	AssertEqual(IsPalindrom("baaa aa a aaaaaaaaaaaaaaaa aaa aa aaab"), 0, "no");
	AssertEqual(IsPalindrom("baaa aa a aaaaaaaaaaaaaaaa aaaaa aaab"), 0, "no");
	AssertEqual(IsPalindrom("baaa aa a aa a aaaaaaaaaaaaa aaaaa aaab"), 0, "no");
	AssertEqual(IsPalindrom("baaa aaaaa a aaa aaaaaaaaaa aaaaa aaab"), 0, "no");
	AssertEqual(IsPalindrom("baaa aaaaa a aaa aaa aaaaaaa aaaaa aaab"), 0, "no");
	AssertEqual(IsPalindrom("b1aaaaaaaaaaaaaaaaaabaaaaaaaaaab"), 0, "no");
	AssertEqual(IsPalindrom("baaaaaaaaaaaaaaaaaaabaaaaaaaaaab"), 0, "no");
	AssertEqual(IsPalindrom("baa aaaaaaaaaaaaaaaaabaaaaaaaa aab"), 0, "no");
	AssertEqual(IsPalindrom("baa aaaa aaaaaaaaaaaaabaaaa aaaa aab"), 0, "no");
	AssertEqual(IsPalindrom("baa aaaa aa aaaa aaaaaaa b aaaa aaaa aab"), 0, "no");
	AssertEqual(IsPalindrom("a0"), 0, "no");
	AssertEqual(IsPalindrom("ab"), 0, "no");
	AssertEqual(IsPalindrom("abb"), 0, "no");
	AssertEqual(IsPalindrom("aab"), 0, "no");
	AssertEqual(IsPalindrom(" b"), 0, "no");
	AssertEqual(IsPalindrom("b "), 0, "no");
	AssertEqual(IsPalindrom(" b  "), 0, "no");
	AssertEqual(IsPalindrom(" b  b"), 0, "no");
	AssertEqual(IsPalindrom("bb  b"), 0, "no");
	AssertEqual(IsPalindrom("bb  b"), 0, "no");
	AssertEqual(IsPalindrom("aaabb"), 0, "no");
	AssertEqual(IsPalindrom("aabbb"), 0, "no");
	AssertEqual(IsPalindrom("aab bb"), 0, "no");
	AssertEqual(IsPalindrom("aa bbb"), 0, "no");

}


int main() {
  TestRunner runner;

  runner.RunTest(All, "All");
  runner.RunTest(Not, "Not");
  return 0;
}
