//I've rewritten the merge sort function.
//The time complexity is O(nlongn).

void merge(int array[], int L, int M, int R) {
    int i = L, j = M + 1, tempArray[100000];
    for(int k = L; k <= R; k++)
    {
        if(i > M)
        {
            tempArray[k] = array[j];
            j++;
        }
        else if(j > R)
        {
            tempArray[k] = array[i];
            i++;
        }
        else
        {
            if(array[i] < array[j])
            {
                tempArray[k] = array[i];
                i++;
            }
            else
            { 
                tempArray[k] = array[j];
                j++;
            }
        }
    }
    for(int k = L; k <= R; k++)
        array[k] = tempArray[k];
}

void mergeSort(int array[], int L, int R) {
    if(L < R)
    {
        int M = (L + R)/2;
        mergeSort(array, L, M);
        mergeSort(array, M + 1, R);
        merge(array, L, M, R);
    }
}

int returnMin(int a, int b) {
    return a < b ? a : b;
}

int findMinDifference(char** timePoints, int timePointsSize) {
    int convertToMinutes[100000];

    for(int i = 0; i < timePointsSize; i++) {
        convertToMinutes[i] = (timePoints[i][0] * 10 + timePoints[i][1]) * 60 + (timePoints[i][3] * 10 + timePoints[i][4]);
    }

    mergeSort(convertToMinutes, 0, timePointsSize - 1);

    int ans = 1000000000;
    for(int i = 0; i < timePointsSize - 1; i++) {
        ans = returnMin(ans, convertToMinutes[i + 1] - convertToMinutes[i]);
    }

    ans = returnMin(ans, 1440 - convertToMinutes[timePointsSize - 1] + convertToMinutes[0]);
    return ans;
}
