#include <stdio.h>


int binarySearch(int arr[], int len, int target) {
    if(len < 1) {
	if(arr[0] == target)
	    return 1;
	return 0;
    }
    int split = len / 2;
    
    if(target == arr[split])
	return 1;
    if(target < arr[split])
	binarySearch(arr, split, target);
    if(target > arr[split])
	binarySearch(arr+split+1, len-split, target);


}


int main(void) {
    int arr[5] = {1,2,4,5,7};
    
    if(binarySearch(arr, 5, 7))
	printf("Found!\n");
    else
	printf("Not found :(\n");
}
