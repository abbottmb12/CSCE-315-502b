#include <iostream>
#include "Relation.h"

using namespace std;

class Database {
  public:
  Database(){};
    vector<Relation> relation;
	void Selection(Relation name, string attr_name);
    void Create(string rel_name, string s0, string s1 , string s2);
    void Insert(string rel_name, char* s1, int i1 , char* s2);
    void Write();
    void Show(string rel_name);
};
