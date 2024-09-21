//This solution is using dynamic programming algorithm
//Time complexity is O(n)

int returnMax(int a, int b, int c) {
    int max = a;
    if(b > max) {
        max = b;
    }
    if(c > max) {
        max = c;
    }
    return max;
}

int returnMin(int a, int b, int c) {
    int min = a;
    if(b < min) {
        min = b;
    }
    if(c < min) {
        min = c;
    }
    return min;
}
int maxProduct(int* nums, int numsSize) {
    int maxPro[100000];
    int maxEndHere[100000], minEndHere[100000];
    maxPro[0] = nums[0];
    maxEndHere[0] = nums[0];
    minEndHere[0] = nums[0];
    for(int i = 1; i < numsSize; i++) {
        maxEndHere[i] = returnMax(nums[i], maxEndHere[i - 1] * nums[i], minEndHere[i - 1] * nums[i]);
        minEndHere[i] = returnMin(nums[i], maxEndHere[i - 1] * nums[i], minEndHere[i - 1] * nums[i]);
        maxPro[i] = (maxPro[i - 1] > maxEndHere[i])? maxPro[i - 1] : maxEndHere[i];
    }
    return maxPro[numsSize - 1];
}
