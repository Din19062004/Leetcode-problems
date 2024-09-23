=/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct NumWithFreq {
    int num, freq;
} NumWithFreq;

int compareNums(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

int compareFreq(const void *a, const void *b) {
    NumWithFreq *nA = (NumWithFreq *)a;
    NumWithFreq *nB = (NumWithFreq *)b;
    return (nA->freq - nB->freq);
}

int* frequencySort(int* nums, int numsSize, int* returnSize) {
    //Sort the array nums[] in decreasing order
    qsort(nums, numsSize, sizeof(int), compareNums);

    int cnt = 1, j = 0;
    *returnSize = numsSize;
    NumWithFreq N[100];
    for(int i = 0; i < numsSize - 1; i++) {
        if(nums[i] != nums[i + 1]) {
            //Store the current num and its frequency into N[j]
            N[j].num = nums[i];
            N[j].freq = cnt;
            j++;
            //Reset the cnt variable to count the next num's frequency
            cnt = 1;
        }
        else {
            //Continue to increase the frequency of the current nums
            cnt++;
        }
    }
    //Store the last num and its frequency
    N[j].num = nums[numsSize - 1];
    N[j].freq = cnt;
    
    //Sort the frequency in increasing order
    //If two numbers have the same frequency then sort them in decreasing order
    //j + 1 is the size of array N[]
    qsort(N, j + 1, sizeof(NumWithFreq), compareFreq);
    
    int v = 0;
    int *returnArray = (int *)malloc(numsSize * sizeof(int));
    for(int i = 0; i <= j; i++) {
        for(int k = v; k < N[i].freq + v; k++) {
            returnArray[k] = N[i].num;
        }
        v = v + N[i].freq;
    } 
    return returnArray;
    free(returnArray);
}
