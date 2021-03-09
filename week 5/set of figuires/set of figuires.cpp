
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include <cmath>
#include <iomanip>

using namespace std;

const double pi = 3.14;

class Figure {
public:
	virtual string Name() const = 0;
	virtual double Perimeter() const = 0;
	virtual double Area() const = 0;
protected:
	const string type;
	vector<int> param;
};

class Triangle : public Figure {
public:
	Triangle(int i1, int i2, int i3){
		param = {i1, i2, i3};
	}
	string Name() const override{
		return "TRIANGLE";
	}
	double Perimeter() const override {
		double per = 0.0;
		for_each(begin(param), end(param), [&](const auto& k){per += k;});
		return per;
	}
	double Area() const override{
		double p = (param[0] + param[1] + param[2]);
		p /= 2;
		double res = sqrt( p * (p - param[0]) * (p - param[1]) * (p - param[2]) );
		return res;
	}
};

class Rect : public Figure {
public:
	Rect(int i1, int i2){
		param = {i1, i2};
	}
	string Name() const override{
		return "RECT";
	}
	double Perimeter() const override {
		double per = 0.0;
		for_each(begin(param), end(param), [&](const auto& k){per += k;});
		return per*2;
	}
	double Area() const override{
		return param[0] * param[1];
	}
};

class Circle : public Figure {
public:
	Circle(int i1){
		param = {i1};
	}
	string Name() const override{
		return "CIRCLE";
	}
	double Perimeter() const override {
		double per = 0.0;
		per = 2 * pi * param[0];
		return per;
	}
	double Area() const override{
		return param[0] * param[0] * pi;
	}
};

shared_ptr<Figure> CreateFigure(istringstream& is){
	string type;
	is >> type;
	is >> ws;
	if (type == "RECT"){
		int i1, i2;
		is >> i1;
		is >> ws;
		is >> i2;
		shared_ptr<Figure> pt = make_shared<Rect>(i1, i2);
		return pt;
	}
	else if (type == "TRIANGLE"){
		int i1, i2, i3;
		is >> i1;
		is >> ws;
		is >> i2;
		is >> ws;
		is >> i3;
//		Triangle tr(i1, i2, i3);
		shared_ptr<Figure> pt = make_shared<Triangle>(i1, i2, i3);
		return pt;
	}
	else if (type == "CIRCLE"){
		int i1;
		is >> i1;
		shared_ptr<Figure> pt = make_shared<Circle>(i1);
		return pt;
	}

}

int main() {
	 vector<shared_ptr<Figure>> figures;
	  for (string line; getline(cin, line); ) {
	    istringstream is(line);

	    string command;
	    is >> command;
	    if (command == "ADD") {
	      // Пропускаем "лишние" ведущие пробелы.
	      // Подробнее об std::ws можно узнать здесь:
	      // https://en.cppreference.com/w/cpp/io/manip/ws
	      is >> ws;
	      figures.push_back(CreateFigure(is));
	    } else if (command == "PRINT") {
	      for (const auto& current_figure : figures) {
	        cout << fixed << setprecision(3)
	             << current_figure->Name() << " "
	             << current_figure->Perimeter() << " "
	             << current_figure->Area() << endl;
	      }
	    }
	  }
  return 0;
}
