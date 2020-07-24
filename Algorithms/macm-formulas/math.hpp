#ifndef MATH_H
#define MATH_H

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


namespace macm {

  /**
   * Return the combination of n choose k.
   */
  size_t comb(const int & n, const int & k) {
    return (factorial(n) / factorial(k) / factorial(n-k));
  }

  /**
   * Return the permutation of n pick k.
   */
  size_t perm(const int & n, const int & k) {
    return (factorial(n) / factorial(n-k));
  }

  /**
   * Return the combination with repetition of n choose k.
   */
  size_t withRep(const int & n, const int & k) {
    return comb(n+k-1, k);
  }

  /**
   * Return the derangement of n.
   */
  size_t derange(const int & n) {
    float res = 0;

    for(int i = 0; i < n+1; ++i)
      (i+1) % 2 != 0 ? res += (1.0 / factorial(i)) : res -= (1.0 / factorial(i));

    res *= factorial(n);

    return (size_t)res;
  }
}

#endif /* end of include guard: MATH_H */
