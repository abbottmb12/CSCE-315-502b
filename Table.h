#include <iostream>
#include <vector>
using namespace std;
//--------------------------------------------------------------------
//Table class for reading in data
//Input data format:
//Header: -Attribute Title- -Attribute Title- -Attribute Title- ...etc
//Tuples: -Attribute-       -Attribute-       -Attribute-       ...etc
//--------------------------------------------------------------------
class Table{
	private: 
		vector< vector<string> > attr; //attributes vectors
		vector< vector<string>* > tuples; //vector pointing to the tuples in the attr vector not sure about this yet but we need something like this to keep track of tuples
	public: 
}
