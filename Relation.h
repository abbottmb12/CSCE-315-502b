#ifndef RELATION_H
#define RELATION_H
#include <iostream>
#include <vector>
#include "Attribute.h"
#include "iomanip"
using namespace std;
//--------------------------------------------------------------------
//Table class for reading in data
//Input data format:
//First: # of cars Then: # of attributes
//Header: -Attribute Title- -Attribute Title- -Attribute Title- ...etc
//Tuples: -Attribute- -Attribute- -Attribute- ...etc
//--------------------------------------------------------------------

class Relation{
  public:
    vector< Attribute > attr;
	string name;
    Relation() {}
    void add_attr(Attribute& a) {
      attr.push_back(a);
    }
    Attribute getAttribute(int n)
    {
      return attr[n];
    }
    int getNumAttributes()
    {
      return attr.size();
    }
    vector<Cell> getTuple(int n)
    {
      vector<Cell> tuple;
      for(int i = 0; i < 3; i++)
      {
        tuple.push_back(getAttribute(i).cell[n]);
      }
      return tuple;
    }

    void read(string s);

    void Create(string rel_name, string s0, string s1 , string s2) {
		name = rel_name;
		Attribute a0, a1, a2;
		a0.setName(s0);
		a1.setName(s1);
		a2.setName(s2);
		attr.push_back(a0);
		attr.push_back(a1);
		attr.push_back(a2);
	}

    void Show() {
      vector<Cell> tuple;
      Attribute intsecho = getAttribute(0);
      Attribute charsecho = getAttribute(1);
      Attribute char2echo = getAttribute(2);
      cout << "\n-----------------------------------" << endl;
      cout <<"            DATABASE TABLE           " << endl;
      cout <<"-----------------------------------" << endl;
      cout << intsecho.getName() << setw(15) << charsecho.getName() << setw(15) << char2echo.getName() << endl;
      cout <<"-----------------------------------" << endl;
      int s = 0;
      int s2 = 1;
      int s3 = 2;

      for(int i=0; i < attr[0].getLength(); ++i) {
        tuple = getTuple(i);
        cout << tuple[0].value.c << setw(15) << tuple[1].value.i << setw(15) << tuple[2].value.c << endl;
		}
    }

    void Insert(char* s1, int i1 , char* s2) { 
      Value v1, v2 , v3;
      v1.c = s1;
	  v2.i = i1;
      v3.c = s2;
	
      attr[0].push_back(v1);
      attr[1].push_back(v2);
	  attr[2].push_back(v3);
    }

    void Write() {
      cout << "Requires File I/O, will be implemented in the next part " << endl;
    }
};
#endif
