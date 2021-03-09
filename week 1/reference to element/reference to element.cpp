#include <iostream>
#include <limits>
#include <vector>
#include <map>
#include <tuple>
#include <utility>

using namespace std;

/*
template <typename key, typename value>
pair<key, value> operator*(const pair<key, value> lhs, const pair<key, value> rhs){
	const value val = lhs.second * rhs.second;
	const key kk = lhs.first * rhs.first;
	return make_pair(kk, val);
}
*/

template <typename key, typename value>
value& GetRefStrict(map<key, value>& mp, key kk){
	if (mp.count(kk) == 0){
	throw runtime_error("some text");
	}
	return mp[kk];
}




int main() {
	map<int, string> m = {{0, "value"}};
	string& item = GetRefStrict(m, 0);
	item = "newvalue";
	cout << m[0] << endl; // выведет newvalue


  return 0;
}



