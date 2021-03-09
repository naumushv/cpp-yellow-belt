#include <iostream>
#include <limits>
#include <vector>
using namespace std;

struct capacity{
	int64_t W, H, D;
};

int main() {

	int n, r;
	vector<capacity> v1;

	try {
		cin >> n >> r;
		if (n < 0 || r < 0) throw;
		for (int i=0; i < n; i++){
			if (cin.fail() || cin.eof()) throw;
			capacity cap;
			cin >> cap.W >> cap.H >> cap.D;
			if (cap.W  < 0 || cap.H < 0 || cap.D < 0) throw;
			v1.push_back(cap);
		}


	}
	catch(exception& e){
		cout << e.what() << endl;
	}

//	for (int i=0; i < static_cast<int>(v1.size()); i++){
//				cout << v1[i].W << " " << v1[i].H  << " "<< v1[i].D << " " << endl;
//	}

	vector<int64_t> v2;
	uint64_t sum = 0;

	for (int i=0; i < static_cast<int>(v1.size()); i++){
		v2.push_back(v1[i].D * v1[i].H * v1[i].W * r);
		sum += v2[i];
//		cout << v2[i] << endl;
	}
	cout << sum << endl;


  return 0;
}
