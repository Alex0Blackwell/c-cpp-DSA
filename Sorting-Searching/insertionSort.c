#include <stdio.h>


void insertionSort(int arr[], int len) {
  for (int i = 0; i < len - 1; i++) {
    int placeEl = arr[i + 1];
    int foundFlag = 0;
    for (int j = i + 1; j > 0; j--) {
      arr[j] = arr[j - 1]; // make room
      if (arr[j - 1] < placeEl) {
        arr[j] = placeEl; // that's my stop!
        foundFlag = 1;
        break;
      }

    }
    if (!foundFlag) {
      /* if it was never inserted, then insert at beginning */
      arr[0] = placeEl;
    }
  }
}

int main(void) {
  int arr[5] = {1, 5, -3, 4, -3};

  printf("Original list: ");
  for (int i = 0; i < 5; i++)
    printf("%d ", arr[i]);
  printf("\n");

  insertionSort(arr, 5);

  printf("Sorted list: ");
  for (int i = 0; i < 5; i++)
    printf("%d ", arr[i]);
  printf("\n");

}
