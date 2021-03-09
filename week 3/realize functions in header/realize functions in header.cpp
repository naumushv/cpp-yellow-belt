/*
 * sum_revese_sort.cpp
 *
 *  Created on: Oct 14, 2020
 *      Author: yosh
 */
#include "sum_reverse_sort.h"

int Sum(int x, int y){
	return x+y;
}

string Reverse(string s){
	string res;
	for (int i = s.size()-1, j=0; i >= 0; i--, j++){
		res.push_back(s[i]);
	}
	return res;
}


vector<int> merge(vector<int>& one, vector<int>& two){
	/*for (auto& it:two){
		one.push_back(it);
	}*/
	vector<int> one_tmp = one, two_tmp = two, res;
	size_t i=0, k=0;
	while(i < one_tmp.size() && k < two_tmp.size()){
		if (one_tmp[i] <= two_tmp[k]){
			res.push_back(one_tmp[i]);
			i++;
		}
		else {
			res.push_back(two_tmp[k]);
			k++;
		}
	}

	while(i < one_tmp.size()){
			res.push_back(one_tmp[i]);
			i++;
	}
	while(k < two_tmp.size()){
			res.push_back(two_tmp[k]);
			k++;
	}

	return res;
}

vector<int> mergesort(vector<int>& a, int l, int h){
	if ((h - l) == 0){
		vector<int> tmp;
		tmp.push_back(a[h]);
		return tmp;
	}
	int mid = l + (h-l)/2;
	vector<int> b = mergesort(a, l, mid);
	vector<int> c = mergesort(a, ++mid, h);
	vector<int> mg = merge(b,c);

	return mg;
}

	void Sort(vector<int>& a){
		a =mergesort(a, 0, a.size()-1);
	}
