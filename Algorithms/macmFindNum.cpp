#include <iostream>

using std::cout;
using std::endl;

/**
 * Returns factorial of an integer as an integer.
 * O(n).
 */
size_t factorial(const int & n) {
  size_t res = 1;
  if(n > 0) {
    int m = n;
    res = 1;

    while(m)
      res *= m--;
  }
  return res;
}



/**
 * Find a number where abc = a! + b! + c!.
 */
int main(void) {
  bool found = false;
  size_t target = 100;
  size_t res;
  int a, b, c;

  while(!found) {
    a = target / 100;
    b = (target / 10) % 10;
    c = target % 10;

    res = factorial(a) + factorial(b) + factorial(c);

    if(target == res)
      found = true;
    else
      target++;
  }

  cout << "Found a number!\n" <<
  target << " = " << a << "! + " << b << "! + " << c << "!." << endl;


  return 0;
}
