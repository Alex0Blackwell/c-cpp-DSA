#include <stdio.h>


int linearSearch(int arr[], int len, int target) {
  /* return -1 if not found. If found, return index */
  int index = -1;
  for (int i = 0; i < len; i++) {
    if (arr[i] == target) {
      index = i;
      break;
    }
  }
  return index;
}

int main(void) {
  int arr[5] = {1, 3, 4, 5, 7};

  printf("index at %d\n", linearSearch(arr, 5, 7));

  return 0;
}
