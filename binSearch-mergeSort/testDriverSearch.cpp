#include <iostream>

#include "mergeSort.hpp"
#include "binarySearch.hpp"

using namespace std;


int main(void) {
    int arr[10];
    int target;

    printf("Enter the 10 array numbers\n");
    for(int i = 0; i < 10; i++) {
	scanf("%d", &arr[i]);
    } 
    printf("Enter the number you want to find:\n");
    scanf("%d", &target);

    mergeSort(arr, 0, 9); 

    printArr(arr, 10);

    if(search(arr, 0, 9, 5)) {
	cout << "found\n";
    } else {
	cout << "not found\n";
    }  
    return 0;
}
