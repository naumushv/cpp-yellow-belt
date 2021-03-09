#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

vector<string> SplitIntoWords(string& s){
	vector<string> res;
	string::iterator pos = begin(s), pos2;
	string tmp;
	while(pos2 != end(s)){
		pos2 = find(pos, end(s), ' ');
		tmp.assign(pos, pos2);
		res.push_back(tmp);
		if (pos2 != end(s))pos = ++pos2;
	}
	return res;
}


int main() {
  string s = "C Cpp Java Python";

  vector<string> words = SplitIntoWords(s);
  cout << words.size() << " ";
  for (auto it = begin(words); it != end(words); ++it) {
    if (it != begin(words)) {
      cout << "/";
    }
    cout << *it;
  }
  cout << endl;

  return 0;
}

