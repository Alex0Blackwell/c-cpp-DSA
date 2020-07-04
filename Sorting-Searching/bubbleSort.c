#include <stdio.h>


void printArr(int array[], int len) {
  /* void function for printing the array */
  printf("The values of returned are:\n");
  for (int j = 0; j < len; j++)
    printf("%d ", array[j]);
  printf("\n");

  return;
}

void sort(int array[], int len) {
  /* bubble sort, O(n^2) */
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (array[j] < array[i]) {
        /* swap the two */
        int _temp = array[i];
        array[i] = array[j];
        array[j] = _temp;
      }
    }
  }
  return;
}

int main() {
  int arrIn[50] = {};
  int i = 0;

  while (scanf("%d", & arrIn[i++]) != EOF);

  sort(arrIn, i - 1);
  printArr(arrIn, i - 1);

  return 0;
}
