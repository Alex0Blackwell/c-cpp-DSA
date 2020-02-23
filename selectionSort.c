#include <stdio.h>


void selectionSort(int arr[], int len) {
    /* selection sort running in O(N^2) */

    for(int i = 0; i < len; i++) {
	int lowest = arr[i];
	int index = -1;
	for(int j = i; j < len; j++) {
	    if(arr[j] < lowest) {
		lowest = arr[j];
		index = j;
	    }
	}
	if(index != -1) {
	    int temp = arr[index];
	    arr[index] = arr[i];
	    arr[i] = temp;
	}
    }

    return;
}


int main(void) {
    int arr[5] = {2,4,0,-1,1};

    for(int i = 0; i < 5; i++)
	printf("%d ", arr[i]);
    printf("\n");

    selectionSort(arr, 5);

    for(int i = 0; i < 5; i++)
	printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

