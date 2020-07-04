#include <iostream>

using namespace std;

int countTrees(int n) {
  if (n <= 1)
    return 1;

  int sum = 0;
  int left, right, root;

  for (root = 1; root <= n; root++) {
    left = countTrees(root - 1);
    right = countTrees(n - root);

    sum += left * right;
  }
  return sum;
}

int main(void) {
  int n;

  cout << "enter n for values 1-n:\n";
  cin >> n;

  int res = countTrees(n);
  cout << res;
  return 0;
}
