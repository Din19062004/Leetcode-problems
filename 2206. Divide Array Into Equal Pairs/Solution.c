typedef struct numWithFreq {
    int nums, freq;
} numWithFreq;

int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}
bool divideArray(int* nums, int numsSize) {
    //Sort the array nums[] in ascending order
    qsort(nums, numsSize, sizeof(int), compare);
    numWithFreq N[500];
    int count = 1, index = 0;
    for(int i = 0; i < numsSize - 1; i++) {
        if(nums[i] != nums[i + 1]) {
            N[index].nums = nums[i];
            N[index].freq = count;
            count = 1;
            index ++;
        }
        else {
            count ++;
        }
    }
    N[index].nums = nums[numsSize - 1];
    N[index].freq = count;
    
    int numOfPairs = numsSize / 2;
    int numInPair = numsSize / numOfPairs;
    int start = 0;
    for(int i = 0; i <= index; i++) {
        if(N[i].freq % numInPair == 0) {
            //Count the number of pairs which is possible
            start += N[i].freq / numInPair;
        }
    }
    bool result;
    if(start != numOfPairs) {
        result = false;
    }
    else {
        result = true;
    }
    return result;
}
