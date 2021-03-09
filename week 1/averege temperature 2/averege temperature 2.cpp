#include <iostream>
#include <limits>
#include <vector>
using namespace std;

int main() {
	long unsigned int quantity,i;
	double input, avg=0;
	vector<double> numbers;
	cin >> quantity;
	if (quantity <= 0){
		cout << 0 << endl;
		return 0;
	}
	int l = 0;
	try{
	for (i=0; i < quantity; i++){
		cin >> input;
		numbers.push_back(input);
		avg += input;
	}
	avg = avg / quantity;
//	cout << avg << endl;
	for (long unsigned int k = 0; k < numbers.size();k++){
			if (numbers.at(k) > avg){
					i = k;
					++l;
			}
	}
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}


	cout << l << endl;

	for (long unsigned int k = 0; k < numbers.size();k++){
			if (numbers.at(k) > avg){
					cout << k ;
					if (k != i)
					 cout << " ";
	//				++i;
			}

	}



  return 0;
}
