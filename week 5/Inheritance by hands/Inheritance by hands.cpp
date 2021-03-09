
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;


class Animal {
public:
	Animal(string n)
	: Name(n){}

    const string Name;
};


class Dog : public Animal {
public:
	Dog(string n) : Animal(n)
	{}

    void Bark() {
        cout << Name << " barks: woof!" << endl;
    }
};


int main() {
	Dog dg("Doggo");
	dg.Bark();

  return 0;
}
