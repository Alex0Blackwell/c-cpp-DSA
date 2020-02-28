#include <stdio.h>

/* 1 if found, 0 otherwise. Note the array must be sorted*/
int bSearch(int *begin, int len, int target) {
    int mid = len / 2;  // truncates
    
    if (target == begin[mid]){
        return 1;
    }

    if(len <= 1) {
        return 0;
    }
    
    if(target < begin[mid])
        return bSearch(begin, len-mid, target);
    if(target > begin[mid])
        return bSearch(begin+mid, len-mid, target);
}



int main()
{
    int array[5] = {1,2,3,4,5};
    
    printf("bSearch returned %d\n", bSearch(array, 5, 6));
    

    return 0;
}