/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDuplicates(int* nums, int numsSize, int* returnSize) {
    int Freq[100000];
    int *returnArray = (int *)malloc(numsSize * sizeof(int));
    for(int i = 1; i <= numsSize; i++) {
        Freq[i] = 0;
    }
    for(int i = 0; i < numsSize; i++) {
        Freq[nums[i]]++;
    }
    int j = 0;
    for(int i = 1; i <= numsSize; i++) {
        if(Freq[i] == 2) {
            returnArray[j] = i;
            j++;
        }
    }
    *returnSize = j;
    return returnArray;
    free(returnArray);
}
