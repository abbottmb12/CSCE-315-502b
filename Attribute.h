#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H
#include <iostream>
#include <vector>

using namespace std;

typedef string Cell;

enum Type {INT, STRING};

typedef pair<string, Type> Header;

class Attribute{//attribute can have int or string types, has a name, and has a vector of different cells
  public:
    string name;
  public:
    Type type;
    vector<string> cell;
    Attribute () {};
    Attribute(Type t, string n) : type(t), name(n) {};
   
    void push_back(string v)//used to insert strings
    {
      cell.push_back(v);
    }
    vector<string> getCells() const{//returns the vector of cells
      return cell;
    }
    string getName()//returns the attributes name
    {
      return name;
    }
	Type getType(){//returns the attributes type
		return type;
	}
	int getLength() const{//returns the cells size
		return cell.size();
	}
	void setName(string set_name)//changes the attributes name
    {
      name = set_name;
    }

  Cell& operator[](size_t row){//returns a cell
    return cell[row];
  }
};

#endif
