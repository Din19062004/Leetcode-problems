int max(int a, int b) {
    return a > b? a : b;
}

int lengthOfLIS(int* nums, int numsSize) {
    int L[2501];
    int result = 1;
    for(int i = 0; i < numsSize; i++)
        L[i] = 1;
    for(int i = 0; i < numsSize; i++) {
        for(int j = 0; j < i; j++) {
            if(nums[i] > nums[j])
                L[i] = max(L[i], L[j] + 1);
        }
    }
    for(int i = 0; i < numsSize; i++) {
        result = max(result, L[i]);
    }   
    return result;
}
