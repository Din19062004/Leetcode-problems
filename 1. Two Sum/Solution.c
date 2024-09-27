/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct {
    int index, num;
} numWithIndex;

int compare(const void *a, const void *b) {
    numWithIndex *n1 = (numWithIndex *)a;
    numWithIndex *n2 = (numWithIndex *)b;
    return (n1->num) - (n2->num);
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    numWithIndex N[10000];
    for(int i = 0; i < numsSize; i++) {
        N[i].index = i;
        N[i].num = nums[i];
    }
    //Sort the array nums in ascending order corresponding with their indeces
    qsort(N, numsSize, sizeof(numWithIndex), compare);

    //Use two pointers i, j to find the target
    int i = 0, j = numsSize - 1;
    while(i < j) {
        if(N[i].num + N[j].num == target) {
            break;
        }
        else if(N[i].num + N[j].num < target) {
            i++;
        }
        else {
            j--;
        }
    }
    
    *returnSize = 2;
    int *returnArray = (int *)malloc(2 * sizeof(int));

    //Return the result
    returnArray[0] = N[i].index;
    returnArray[1] = N[j].index;
    return returnArray;
    free(returnArray);
}
