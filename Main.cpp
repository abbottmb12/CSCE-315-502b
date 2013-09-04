#include <iostream>
#include "Table.h"
//using namespace std;
//Main Test File
int main(){
	Table T;
	string file = "Cars.txt";
	T.read(file);
	T.dis_table();
	return 0;
}
