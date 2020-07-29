#include <iostream>
#include <string>
#include <assert.h>

#include "hashtable.hpp"

using std::cout;
using std::endl;


int main(void) {
  typedef std::pair<std::string, int> pair;
  Hashtable table1;

  table1.insert(pair("test", 1));
  cout << table1.get("test") << endl;

  table1.insert(pair("test", 2));
  cout << table1.get("test") << endl;

  table1.insert(pair("test2", 10));
  cout << table1.get("test2") << endl;

  return 0;
}
