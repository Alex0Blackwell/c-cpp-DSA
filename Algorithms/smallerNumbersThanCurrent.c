int cmpfunc(const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize) {
    int *res = malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;
    
    int * numsCpy = malloc(sizeof(int) * numsSize);
    for(int i = 0; i < numsSize; ++i)
        numsCpy[i] = nums[i];
    
    qsort(numsCpy, numsSize, sizeof(int), cmpfunc);
    
    for(int i = 0; i < numsSize; ++i) {
        int ii = 0;
        while(numsCpy[ii++] != nums[i]);
        
        res[i] = ii-1;
    }
    
    free(numsCpy);
    
    return res;
}
