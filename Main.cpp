#include <iostream>
#include "Relation.h"
#include "Database.h"
#include "Attribute.h"
#include "Token.h"

using namespace std;

Token_stream ts;
bool identifier(Token_stream& ts)
{
	string identifier_name = "";
	Token t = ts.get();
	if(t.kind == ' '){
		t = ts.get();
	}
	if(t.kind != 'a')
	{
		ts.putback(t);
		cout << "false" << t.kind << endl;
		return false;
	}
	while(t.kind == 'a' || t.kind == '0')
	{
		identifier_name += t.value;
		t = ts.get();
	}
	if(t.kind == ' '){
		t = ts.get();
	}
	ts.putback(t);
	cout << "REL: " << identifier_name << endl;
	return true;
}
bool relation_name(Token_stream& ts){
	return identifier(ts);
}
bool parenthesis(Token_stream& ts){
	cout << "parenth" << endl;
	vector<Token> tt;
	Token t = ts.get();
	if (t.kind == ' '){
		t = ts.get();
		tt.push_back(t);
	}
	else
		tt.push_back(t);
	if (t.kind != '('){
		while(!tt.empty()){
			ts.putback(tt.back());
			tt.pop_back();
		}
		return false;
	}
	else{
		t = ts.get();
		tt.push_back(t);
	}
	while (t.kind != ')'){
		if(t.kind == ';'){
			while(!tt.empty()){
				cout << tt.back().kind;
				ts.putback(tt.back());
				tt.pop_back();
			}
			cout << "parenth false" << endl;
			return false;
		}
		t = ts.get();
		tt.push_back(t);
	}
	while(!tt.empty()){
		cout << "o: " << tt.back().kind << endl;
		
		if(tt.back().kind != '(' && tt.back().kind != ')'){
			ts.putback(tt.back());
			cout << "p: " << tt.back().kind << endl;
		}
		tt.pop_back();
	}
	return true;
}
bool name_check(Token_stream& ts, string input){
	string comp = "";
	Token t = ts.get();
	if(t.kind == ' '){
		t = ts.get();
	}
	if(t.kind != 'a')
	{
		ts.putback(t);
		return false;
	}
	vector<Token> tt; //keeps track of tokens that are cycled through
	tt.push_back(t);
	while(t.kind == 'a'){
		comp += t.value;
		t = ts.get();	
		tt.push_back(t);
	}
	if(comp == input){
		cout << "CMD: " << input << endl;
		ts.putback(t);
		return true;
	}
	while(!tt.empty()){
		ts.putback(tt.back());
		tt.pop_back();
	}
	return false;
}
bool operator_check(Token_stream& ts, char c){
	vector<Token> tt;
	Token t = ts.get();
	tt.push_back(t);
	if(t.kind == ' '){
		t = ts.get();
		tt.push_back(t);
	}
	if(t.kind != c){
		while(!tt.empty()){
				ts.putback(tt.back());
				tt.pop_back();
		}
		return false;
	}
	for(int i = 0; i < tt.size(); ++i){
			cout << tt[i].kind << endl;
	}
	cout << "i did this for: " << c << endl;
	return true;
}
bool atomic_expr(Token_stream& ts);
bool U_diff_prod(Token_stream& ts){
	cout << "union" << endl;
	//parenthesis(ts);
	return atomic_expr(ts) && (operator_check(ts, '+') || operator_check(ts, '-') || operator_check(ts, '*')) && atomic_expr(ts);
}
/*bool diff(Token_stream& ts){
	cout << "diff" << endl;
	return atomic_expr(ts) && operator_check(ts, '-') && atomic_expr(ts);
}
bool product(Token_stream& ts){
	cout << "prod" << endl;
	return atomic_expr(ts) && operator_check(ts, '*') && atomic_expr(ts);
}*/
bool expr(Token_stream& ts){
	cout << "expr" << endl;
	return U_diff_prod(ts);
}
bool atomic_expr(Token_stream& ts){
	cout << "atomic" << endl;
	return relation_name(ts) || (parenthesis(ts) && expr(ts));
}
bool literal_list(Token_stream& ts){
	vector<Token> tt;
	Token t = ts.get();
	tt.push_back(t);
	if(t.kind == ' '){
		t = ts.get();
		tt.push_back(t);
	}
	if(t.kind != '('){
		ts.putback(t);
		return false;
	}
	else{
		t = ts.get();
		tt.push_back(t);
	}
	while(t.kind != ')'){
		if(t.kind == ' '){
			t = ts.get();
			tt.push_back(t);
		}
		if (t.kind == ';'){
			while(!tt.empty()){
				ts.putback(tt.back());
				tt.pop_back();
			}
			return false;
		}
		if(t.kind!= '"'){
			while(!tt.empty()){
				ts.putback(tt.back());
				tt.pop_back();
			}
			return false;
		}
		else{
			t = ts.get();
			tt.push_back(t);
		}
		while(t.kind != '"'){
			if(t.kind == ' '){
				t = ts.get();
				tt.push_back(t);
			}
			if (t.kind == ';'){
				while(!tt.empty()){
					ts.putback(tt.back());
					tt.pop_back();
				}
				return false;
			}
			if(t.kind != 'a' && t.kind != '"'){
				while(!tt.empty()){
					ts.putback(tt.back());
					tt.pop_back();
				}
				return false;
			}
			if(t.kind != '"'){
				t = ts.get();
				tt.push_back(t);
			}
		}
		if(t.kind != ')'){
				t = ts.get();
				tt.push_back(t);
		}
    }
	return true;
}
bool insert(Token_stream& ts){
	return (name_check(ts, "INSERT") && name_check(ts, "INTO") && relation_name(ts) 
			&& name_check(ts, "VALUES") && name_check(ts, "FROM")) && literal_list(ts) ||
			(name_check(ts, "INSERT") && name_check(ts, "INTO") && relation_name(ts) 
			&& name_check(ts, "VALUES") && name_check(ts, "FROM") && name_check(ts, "RELATION") && expr(ts)) ;
}
bool show(Token_stream& ts){
	return name_check(ts, "SHOW") && atomic_expr(ts);
}
bool exit(Token_stream&ts){
	return name_check(ts, "EXIT");
}
bool write(Token_stream& ts){
	return name_check(ts, "WRITE") && relation_name(ts);
}
bool close(Token_stream& ts){
	return name_check(ts, "CLOSE") && relation_name(ts);
}
bool open(Token_stream& ts){
	return name_check(ts, "OPEN") && relation_name(ts);
}
bool command(Token_stream& ts)
{
	return open(ts) || close(ts) || write(ts) || exit(ts) || show(ts) || insert(ts);
}
bool query(Token_stream& ts)
{
	return relation_name(ts) && operator_check(ts, ':') && expr(ts);
}
bool termination(Token_stream& ts){
	Token t = ts.get();
	if (t.kind == ' '){
		t = ts.get();
	}
	if (t.kind == ';'){
		return true;
	}
	return false;
}
bool program(Token_stream& ts)
{
	return (command(ts) || query(ts)) && termination (ts);
}
int main(){
  /*d.Create("Table1");
  d.AddColumn("Table1", Header("Str1", STRING));
  d.AddColumn("Table1", Header("Str2", STRING));
  d.AddColumn("Table1", Header("Str3", STRING));
  vector<Cell> cell;
  cell.push_back("1.1");
  cell.push_back("1.2");
  cell.push_back("1.3");
  d.Insert("Table1", cell);
  cell.clear();
  cell.push_back("1.4");
  cell.push_back("1.5");
  cell.push_back("1.6");
  d.Insert("Table1", cell);
  cell.clear();
  cell.push_back("1.7");
  cell.push_back("1.8");
  cell.push_back("1.9");
  d.Insert("Table1", cell);
  
  d.Create("Table2");
  d.AddColumn("Table2", Header("Str1", STRING));
  d.AddColumn("Table2", Header("Str2", STRING));
  d.AddColumn("Table2", Header("Str3", STRING));
  cell.clear();
  cell.push_back("2.1");
  cell.push_back("2.2");
  cell.push_back("2.3");
  d.Insert("Table2", cell);
  cell.clear();
  cell.push_back("2.4");
  cell.push_back("2.5");
  cell.push_back("2.6");
  d.Insert("Table2", cell);
  cell.clear();
  cell.push_back("2.7");
  cell.push_back("2.8");
  cell.push_back("2.9");
  d.Insert("Table2", cell);
  
  d.Create("Table3");
  d.AddColumn("Table3", Header("Str1", STRING));
  d.AddColumn("Table3", Header("Str2", STRING));
  d.AddColumn("Table3", Header("Str3", STRING));
  cell.clear();
  cell.push_back("2.1");
  cell.push_back("2.2");
  cell.push_back("2.3");
  d.Insert("Table3", cell);
  cell.clear();
  cell.push_back("3.4");
  cell.push_back("3.5");
  cell.push_back("3.6");
  d.Insert("Table3", cell);
  cell.clear();
  cell.push_back("2.7");
  cell.push_back("2.8");
  cell.push_back("2.9");
  d.Insert("Table3", cell);
  
  d.Show("Table3");
  d.Update("Table3", "Str2", "6", "Str3", "==", "2.9");
  d.Show("Table3");*/
  Token_stream ts;
  ts.ss.clear();
  ts.ss.str("");
  cout << "Input line: ";
  string line;
  getline(cin, line);
  ts.ss << line;
  bool valid = true;
  /*while(true)
  {
	Token t = ts.get();
	//cout << t.kind << ", " << t.value << endl;
	if(t.kind == ';')
		//break;
		return 0;
	ts.putback(t);
	cout << program(ts) << endl;
  }*/
  cout << program(ts) << endl;
  return 0;
}
