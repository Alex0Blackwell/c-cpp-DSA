#include <iostream>
#include <string>
#include <assert.h>

#include "hashtable.hpp"

using std::cout;
using std::endl;


int main(void) {
  typedef std::pair<std::string, int> pair;
  Hashtable table1;

  for(int i = 0; i < 101; ++i)
    table1.insert(pair("a"+std::to_string(i),i));

  assert(table1.get("a41") == 41);
  std::cout << "after" << '\n';
  table1.print();

  std::cout << "after remove:" << '\n';
  table1.remove("a41");
  table1.print();

  std::cout << "Exited with status code 0!" << std::endl;

  return 0;
}
