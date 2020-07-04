#include <iostream>

using namespace std;

void reverseMerge(int arr1[], int len1, int arr2[], int len2, int arr3[], int len3) {
  int left = len1 - 1;
  int right = len2 - 1;
  int count = 0;

  while (left >= 0 && right >= 0) {
    if (arr1[left] >= arr2[right]) {
      arr3[count++] = arr1[left--];
    } else if (arr2[right] > arr1[left]) {
      arr3[count++] = arr2[right--];
    }
  }

  while (left >= 0) {
    arr3[count++] = arr1[left--];
  }

  while (right >= 0) {
    arr3[count++] = arr2[right--];
  }
  return;
}

int main(void) {
  int arr1[5] = {2, 4, 6, 8, 10};
  int arr2[4] = {3, 5, 7, 9};
  int arr3[9];
  reverseMerge(arr1, 5, arr2, 4, arr3, 9);

  for (int i = 0; i < 9; i++) {
    cout << arr3[i] << ", ";
  }
  cout << endl;

  return 0;
}
