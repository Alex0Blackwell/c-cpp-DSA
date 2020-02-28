#include <stdio.h>


void quicksort(int arr[], int len) {
    for(int i = 0; i < len; i++) {
	printf("%d ", arr[i]);
    } printf("\n");
    int pivot = 0; 
    if(len <= 1) 
	return;
    else {
	int _arr2[10];
	int l = 0
	for(int i = 1; i < len; i++) {
	    if(arr[i] <= arr[pivot]) {
		int _swap = arr[pivot];
		arr[pivot] = arr[i]; 
		arr[i] = _swap;
		pivot = i;
	    }/*
	    else if(arr[i] > arr[pivot])
		_arr2[r++] = arr[i];
	*/}
    }
    /* sort left side, then right side */
    quicksort(arr, pivot-1);
    quicksort(arr+pivot+1, len);

}


int main(void) {
    int arr[5] = {4,2,6,-1,7};

    quicksort(arr, 0, 5);

    for(int i = 0; i < 5; i++) {
	printf("%d ", arr[i]);
    } printf("\n");

    return 0;
}
