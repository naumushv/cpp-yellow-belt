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


template <typename T> T Sqr(const T& kk);
template <typename T> vector<T> Sqr(const vector<T>& vec);
template <typename key, typename value> pair<key, value> Sqr(const pair<key, value>& par);
template <typename key, typename value> map<key, value> Sqr(const map<key, value>& mp);

template <typename T>
T Sqr(const T& kk){
	return kk*kk;
}

template <typename key, typename value>
pair<key, value> Sqr(const pair<key, value>& par){
	const key ke = Sqr(par.first);
	const value val = Sqr(par.second);
	return make_pair(ke, val);
}

template <typename key, typename value>
map<key, value> Sqr(const map<key, value>& mp){
	map<key, value> tmp;
	for (auto& it:mp){
		tmp[it.first] = Sqr(it.second);
	}
	return tmp;
}

template <typename T>
vector<T> Sqr(const vector<T>& vec){
	vector<T> tmp;
	for (auto& it:vec){
		tmp.push_back(Sqr(it));
	}
	return tmp;
}

int main() {
	// Пример вызова функции
	vector<int> v = {1, 2, 3};
	cout << "vector:";
	for (int x : Sqr(v)) {
	  cout << ' ' << x;
	}
	cout << endl;

	map<int, pair<int, int>> map_of_pairs = {
	  {4, {2, 2}},
	  {7, {4, 3}}
	};
	cout << "map of pairs:" << endl;
	for (const auto& x : Sqr(map_of_pairs)) {
	  cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
	}


  return 0;
}



