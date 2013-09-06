#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H
#include <iostream>
#include <vector>

using namespace std;

enum Type {INT, STRING};
union Value {
  int i;
  char* c;
};
struct Cell {
  Type type;
  Value value;
};

class Attribute{
  public:
    string name;
  public:
    Type type;
	vector<Cell> cell;
    Attribute () {};
    Attribute(Type t, string n) : type(t), name(n) {};
   
    void push_back(Value& v)
    {
      Cell c;
      c.type = type;
      c.value = v;
      cell.push_back(c);
    }
    vector<Cell> getCells(){
      return cell;
    }
    string getName()
    {
      return name;
    }
	int getLength(){
		return cell.size();
	}
	void setName(string set_name)
    {
      name = set_name;
    }
    //string getName();
};
#endif
