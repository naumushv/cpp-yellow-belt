#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <set>
#include <algorithm>
#include <sstream>

using namespace std;

template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border){
	vector<T> res;
	copy_if(begin(elements), end(elements), back_inserter(res), [&](T t) {return t > border;});
	return res;
}

int main() {
  for (int x : FindGreaterElements(set<int>{1, 5, 7, 8}, 5)) {
    cout << x << " ";
  }
	auto br = set<int>{1, 5, 7, 8};
	  cout << endl;


  string to_find = "Python";
  cout << FindGreaterElements(set<string>{"C", "C++"}, to_find).size() << endl;
  return 0;
}
