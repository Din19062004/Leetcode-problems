//In this solution, I'm using bubble sort. Therefor, the time complexity is O(n^2).
//The complexity can be reduced to O(nlogn) if you use qsort in C.

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

char* largestNumber(int* nums, int numsSize) {
    char str1[40] = " ";
    char str2[40] = " ";
    char catStr1[40] = " ";
    char catStr2[40] = " ";
    
    for(int i = 0; i < numsSize - 1; i++) {
        for(int j = i + 1; j < numsSize; j++) {
            sprintf(str1, "%d", nums[i]);
            sprintf(str2, "%d", nums[j]);
            sprintf(catStr1, "%s%s", str1, str2);
            sprintf(catStr2, "%s%s", str2, str1);

            if(strcmp(catStr1, catStr2) < 0) {
                swap(&nums[i], &nums[j]);
            }
        }
    }

    char *resultStr = (char *)malloc(40 * sizeof(char));

    if(nums[0] == 0) {
        strcpy(resultStr, "0");   //Edge case: Largest number is 0
    }
    else {
        sprintf(resultStr, "%d", nums[0]);
        for(int i = 1; i < numsSize; i++) {
            char tempStr[40] = " ";
            sprintf(tempStr, "%d", nums[i]);
            strcat(resultStr, tempStr);
        }
    }
    
    return resultStr;
    free(resultStr);
}
