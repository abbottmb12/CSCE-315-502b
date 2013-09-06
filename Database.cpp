#include "Database.h"
void Database:: Selection(Relation name, string attr_name) {

}
void Database:: Insert(string rel_name, char* s1, int i1 , char* s2) {
	for (int i = 0; i < relation.size(); ++i){
		if (rel_name == relation[i].name){
			relation[i].Insert(s1, i1, s2);
		}
	}
}

void Database:: Create(string rel_name, string s0, string s1 , string s2) {
	Relation r;
	r.Create(rel_name, s0, s1 , s2);
	relation.push_back(r);
}

void Database:: Write() {
}

void Database:: Show(string rel_name) {
	for (int i = 0; i < relation.size(); ++i){
		if (rel_name == relation[i].name){
			relation[i].Show();
		}
	}
}
