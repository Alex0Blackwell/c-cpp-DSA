#include <iostream>
#include "math.hpp"

using std::cout;
using std::endl;


int main() {
  enum Choice { comb, perm, withRep, derange };
  cout << "What calculation: " << endl
  << "(1) combination" << endl
  << "(2) permutation" << endl
  << "(3) combination with repetition" << endl
  << "(4) derangement" << endl;

  int choice;
  std::cin >> choice;

  int n, k;
  switch (choice-1) {
    // let's not sanitize this for right now
    case comb:
    case perm:
    case withRep:
      cout << "Enter valid number of objects" << endl;
      std::cin >> n;
      cout << "Enter valid number to choose" << endl;
      std::cin >> k;

      if(choice-1 == comb)
        cout << "Answer: " << macm::comb(n, k) << endl;
      else if(choice-1 == perm)
        cout << "Answer: " << macm::perm(n, k) << endl;
      else if(choice-1 == withRep)
        cout << "Answer: " << macm::withRep(n, k) << endl;

      break;
    case derange:
      cout << "Enter valid number of objects" << endl;
      std::cin >> n;

      cout << "Answer: " << macm::derange(n) << endl;

      break;
    default:
      cout << "enter a valid number!" << endl;
  }

  return 0;
}
