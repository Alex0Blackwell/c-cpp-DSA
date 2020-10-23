#include <iostream>

#include <vector>
#include <map>
#include <math.h>

using namespace std;

/* naive recursive solution, O(n^2) */
int fib1(int num) {
  if (num == 1 || num == 2)
    return 1;
  return fib1(num - 1) + fib1(num - 2);
}

/* memoized recursive solution, O(n) */
int fib2(int num, vector < int > prev) {
  int res;

  if (prev[num - 1] != 0)
    res = prev[num - 1];
  else if (num == 1 || num == 2)
    res = 1;
  else
    res = fib2(num - 2, prev) + fib2(num - 1, prev);

  prev[num - 1] = res;

  return res;
}

/** memoized recursive solution, O(n) */
map<int, int> cache;

int fib3(int N) {
    int res = cache[N];
    if(res != 0)
        return res;

    if(N == 0)
        res = 0;
    else if(N == 1)
        res = 1;
    else
        res = fib3(N-1) + fib3(N-2);

    cache[N] = res;
    return res;
}

/* sequential solution, not cool but the best :), O(n) */
int fib4(int num) {
  vector < int > vect(num, 0);

  vect[0] = vect[1] = 1;
  for (int i = 2; i < num; i++) {
    vect[i] = vect[i - 2] + vect[i - 1];
  }

  return vect[num - 1];
}


/* another sequential solution, O(n) */
int fib5(int num) {
  if(num == 0 || num == 1)
    return num;

  int res = 0;
  int twoAgo = 0;
  int oneAgo = 1;
  for(int i = 2; i <= num; ++i) {
      res = twoAgo + oneAgo;
      twoAgo = oneAgo;
      oneAgo = res;
  }

  return res;
}

/** Constant time solution from solving a recurrence relation :) */
int fib6(float num) {
  float sqrt5 = sqrt(5);

  return ( 1.0/sqrt5*pow(0.5+sqrt5/2.0, num) - 1.0/sqrt5*pow(0.5-sqrt5/2.0, num) );
}



int main(void) {
  int num;
  cout << "Enter a number: " << endl;
  cin >> num;

  cout << "fib 1: " << fib1(num) << endl;

  vector < int > prev(num, 0);

  cout << "fib 2: " << fib2(num, prev) << endl;

  cout << "fib 3: " << fib3(num) << endl;

  cout << "fib 4: " << fib4(num) << endl;

  cout << "fib 5: " << fib5(num) << endl;

  cout << "fib 6: " << fib6(num) << endl;

  return 0;
}
