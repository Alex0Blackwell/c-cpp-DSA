#include <iostream>

#include <vector>

#include <bits/stdc++.h>

using namespace std;

int solve(int budget, vector < int > & houses) {
  int c = 0;
  sort(houses.begin(), houses.end());

  while (c < houses.size() && (budget - houses[c] >= 0)) {
    budget -= houses[c];
    c++;
  }

  return c;
}

int main(void) {
  int loops, testNum, budget, _tmp;
  cin >> loops;
  vector < int > houses;

  for (int i = 0; i < loops; i++) {
    cin >> testNum >> budget;
    houses.clear();
    for (int j = 0; j < testNum; j++) {
      cin >> _tmp;
      houses.push_back(_tmp);
    }
    cout << "Case #" << i + 1 << ": " << solve(budget, houses) << endl;

  }
}
