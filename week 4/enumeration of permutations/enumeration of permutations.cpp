
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
void RemoveDuplicates(vector<T>& elements){
	if (elements.size() == 0) return;
	sort(elements.begin(), elements.end());
	elements.erase(
	      unique(begin(elements), end(elements)),
	      elements.end());
}

int main() {
	int num;
	cin >> num;
	vector<int> v1(num);
	for (int i=0; i < v1.size(); i++){
		v1.at(i) = i+1;
	}
	for (int i=0; i < v1.size(); i++){
			cout << v1.at(v1.size()-i-1) << " ";
	}
	cout<< endl;

	while (prev_permutation(rbegin(v1), rend(v1) )){
		for (int i=0; i < v1.size(); i++){
					cout << v1.at(v1.size()-i-1) << " ";
			}
		cout<< endl;
	}

  return 0;
}
