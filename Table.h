#ifndef TABLE_H
#define TABLE_H
#include <iostream>
#include <vector>
using namespace std;
//--------------------------------------------------------------------
//Table class for reading in data
//Input data format:
//First: # of cars Then: # of attributes
//Header: -Attribute Title- -Attribute Title- -Attribute Title- ...etc
//Tuples: -Attribute-       -Attribute-       -Attribute-       ...etc
//--------------------------------------------------------------------
class Table{
	private:
		vector< vector<string> > attr; //attributes vectors
		vector< vector<string> > tuples; //vector pointing to the tuples in the attr vector
	public: 
		Table() : attr(), tuples() {}//default constructor
		void read(string s);//reading in the data with string s as the filename
		void dis_table(); //display the table
};
#endif
