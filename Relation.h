#ifndef RELATION_H
#define RELATION_H
#include <iostream>
#include <vector>
#include "Attribute.h"
using namespace std;
//--------------------------------------------------------------------
//Table class for reading in data
//Input data format:
//First: # of cars Then: # of attributes
//Header: -Attribute Title- -Attribute Title- -Attribute Title- ...etc
//Tuples: -Attribute-       -Attribute-       -Attribute-       ...etc
//--------------------------------------------------------------------
class Relation{
	private:
		vector< vector<string> > tuples; 
	public:
		vector< void* > attr;
		Relation() {}
		void add_attr(void* a) {
			attr.push_back(a);
		}
		void read(string s);
		void dis_table();
};
#endif
