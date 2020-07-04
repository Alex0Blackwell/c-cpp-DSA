#include <iostream>

#include <vector>

#include <bits/stdc++.h>

using namespace std;

int solve(int budget, vector < int > & houses) {
  return 0;
}

int main(void) {
  int testCases, vectSize, input1, _tmp;
  vector < int > vect;
  cin >> testCases;

  for (int i = 0; i < testCases; i++) {
    cin >> vectSize >> input1;
    vect.clear();
    for (int j = 0; j < testCases; j++) {
      cin >> _tmp;
      vect.push_back(_tmp);
    }
    cout << "Case #" << i + 1 << ": " << solve(input1, vect) << endl;

  }
}
