#include <iostream>
#include "math.hpp"

using std::cout;
using std::endl;

int main() {


  cout << macm::comb(20, 10) << endl;
  cout << macm::perm(20, 5) << endl;
  cout << macm::withRep(20, 2) << endl;
  cout << macm::derange(4) << endl;


  return 0;
}
