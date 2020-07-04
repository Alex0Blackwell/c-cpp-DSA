#include <iostream>

#include <vector>

#include <bits/stdc++.h>

using namespace std;

int solve(int size, int choose, vector < int > & plates) {
  vector < int > potential;
  int thisBeauty;
  auto eraseI = plates.begin();

  for (int i = 0; i < choose - 1; i++)
    eraseI++;

  for (int i = 0; i < choose; i++) {
    thisBeauty = 0;
    for (int j = 0; j < choose; j++) {
      thisBeauty += plates[j];
    }
    potential.push_back(thisBeauty);
    plates.erase(eraseI--);
  }

  int max = 0;
  for (int i = 0; i < potential.size(); i++) {
    if (potential[i] > max)
      max = potential[i];
  }

  return max;
}

int main(void) {
  int testCases, numVects, vectSize, choose, _tmp;
  vector < int > vect;
  cin >> testCases;

  for (int i = 0; i < testCases; i++) {
    cin >> numVects >> vectSize >> choose;
    vect.clear();
    for (int j = 0; j < vectSize * numVects; j++) {
      cin >> _tmp;
      vect.push_back(_tmp);
    }
    cout << "Case #" << i + 1 << ": " << solve(vectSize, choose, vect) << endl;

  }
}
