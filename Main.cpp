#include <iostream>
#include "Relation.h"
using namespace std;
int main(){
	//Table T;
	//string file = "Cars.txt";
	//T.read(file);
	//T.dis_table();
	Attribute<int> a;
	Attribute<int> b;
	a.cell.push_back(2);
	b.cell.push_back(3);
	Relation r;
	r.add_attr((void*)&b);
	Attribute<int>* attr = static_cast<Attribute<int>*>(r.attr[0]);
	//cout << attr->getCells()[0] << endl;
	cout << (&a)->cell[0] << endl;
	cout << &b << endl;
	return 0;
}
