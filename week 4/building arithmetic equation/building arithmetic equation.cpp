#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <deque>

using namespace std;



int main() {
	//part 2
	int tmp, oper;
	string str;
		deque<string> deq;
		cin >> tmp >> oper;
		deq.push_back(to_string(tmp));

		while (oper){
			bool low = str == " + " || str == " - ";
			cin >> str;
			cin >> tmp;
			bool high = str == "*" || str == "/";
			if( (low && high))
				deq.push_front("(");
			if((low && high))
				deq.push_back(")");
			str.append(" ");
			str.insert(begin(str), ' ');
			deq.push_back(str);
			deq.push_back(to_string(tmp));

			--oper;
		}

		for (auto i: deq){
			cout << i ;
		}
		cout << endl;

  return 0;
}

	//part 1
	/*
	int tmp, oper;
	deque<string> deq;
	cin >> tmp >> oper;
	if (oper)
		deq.push_front("(");
	deq.push_back(to_string(tmp));
	if (oper)
		deq.push_back(")");

	while (oper){
		string str;
		cin >> str;
		cin >> tmp;
		if(! (oper == 1))
			deq.push_front("(");
//		str = " " + str + " ";
		str.append(" ");
		str.insert(begin(str), ' ');
		deq.push_back(str);
		deq.push_back(to_string(tmp));
		if(! (oper == 1))
			deq.push_back(")");

		--oper;
	}

	for (auto i: deq){
		cout << i ;
	}
	cout << endl;
*/
