void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    n = nums2Size;
    m = nums1Size - nums2Size;
    int *newNums1 = (int *)malloc(m * sizeof(int));
    for(int i = 0; i < m; i++) {
        newNums1[i] = nums1[i];
    }
    
    int i = 0, j = 0;
    for(int k = 0; k < nums1Size; k++) {
        if(i >= m) {
            nums1[k] = nums2[j];
            j++;
        }
        else if(j >= n) {
            nums1[k] = newNums1[i];
            i++;
        }
        else {
            if(newNums1[i] < nums2[j]) {
                nums1[k] = newNums1[i];
                i++;
            }
            else {
                nums1[k] = nums2[j];
                j++;
            }
        }
    }
    free(newNums1);
}
