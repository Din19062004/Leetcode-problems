/**
 * Note: The returned array must be malloced, assume caller calls free().
 * Idea: Covert integer into string, then use strcmp to sort all the strings in lexicographical order.
 * Time complexity: O(nlogn). (Using qsort in C)
 */
int compare(const void *a, const void *b) {
    char str1[10], str2[10];
    sprintf(str1, "%d", *(int *)a);
    sprintf(str2, "%d", *(int *)b);
    return strcmp(str1, str2);
}
int* lexicalOrder(int n, int* returnSize) {
    int *array = (int *)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        array[i] = i + 1;
    }
    *returnSize = n;
    qsort(array, n, sizeof(int), compare);
    return array;
    free(array);
}
