
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

void PrintVectorPart(const vector<int>& numbers){
	auto it = find_if(begin(numbers), end(numbers), [](int n){
		return n < 0;
	});
	if (it == end(numbers)) {
		while(it != begin(numbers)){
			--it;
			cout << *it << " ";
		}
	}
	else {
		if (it == begin(numbers)){}
		else
		{
			while(it != begin(numbers)){
				--it;
				cout << *it << " ";
			}
		}
	}
}

int main(){

	vector<int> one = {1,2,3,4,5}, two = {-2, -1, 0, 1 ,2 ,3},
			th = {3,4,5,-2,3,4,-5},
	test1 = {6, 1, 8, -5, 4}, test2 = {-6, 1, 8, -5, 4}, test3 = {6, 1, 8, 5, 4};
	PrintVectorPart(test1);
	cout << endl;

	PrintVectorPart(test2);
	cout << endl;
	PrintVectorPart(test3);
	cout << endl;

	return 0;
}

