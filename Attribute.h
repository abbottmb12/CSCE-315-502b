#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H
#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Attribute{
	private:
		string name;
	public:
		vector<T> cell;
		Attribute() {};
		vector<T> getCells(){
			return cell;
		}
		string test() {
			return "jlfkds";
		}
		//string getName();
};
#endif
