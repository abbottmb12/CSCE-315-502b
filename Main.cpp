#include <iostream>
#include "Relation.h"
#include "Database.h"
#include "Attribute.h"

using namespace std;

int main(){
  Database d;
  d.Create("Cars", "Make", "Year", "Model");
  d.Insert("Cars", "Audi", 2013,"R8");
  d.Insert("Cars", "Chevrolet", 2011,"Cobalt");
  d.Insert("Cars", "Mercedes",2010,"Benz");
  d.Insert("Cars", "Dodge",2009,"Charger");
  d.Insert("Cars", "Nissan", 2006 , "Altima");

  d.Show("Cars");

  return 0;
}
