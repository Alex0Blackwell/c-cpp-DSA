#include <stdio.h>


void mergeSort(int arr[], int first, int last) {
  /* sort left side of tree,
  sort right side of tree,
  merge them together */

  if (first >= last)
    return;

  int split = (first + last) / 2;

  mergeSort(arr, first, split);
  mergeSort(arr, split + 1, last);

  /* merge the two */
  int _newArr[50];
  int r = split + 1;
  int l, c;
  l = c = first;
  while (l <= split && r <= last) {
    if (arr[l] <= arr[r])
      _newArr[c++] = arr[l++];
    if (arr[l] > arr[r])
      _newArr[c++] = arr[r++];
  }

  while (l <= split)
    _newArr[c++] = arr[l++];

  while (r <= last)
    _newArr[c++] = arr[r++];

  for (int i = first; i <= last; i++)
    arr[i] = _newArr[i];
}

int main(void) {
  int arr1[5] = {2, 5, 3, 7, 4};

  mergeSort(arr1, 0, 4);

  for (int i = 0; i < 5; i++) {
    printf("%d ", arr1[i]);
  }
  printf("\n");

  return 0;
}
