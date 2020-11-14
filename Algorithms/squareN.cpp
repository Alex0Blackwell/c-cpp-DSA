#include <iostream>

using namespace std;


/**
 * Calculate the square of an integer with a generating function
 */
int power(int n) {
  int sum = 0;

  int c = 0;
  for(int i = 1; c < n; i+=2, ++c)
    sum += i;

  return sum;
}



int main() {
  int n;

  cout << "Enter a number: ";
  cin >> n;

  cout << endl
  << n << "^2 = " << power(n) << endl;



  return 0;
}
