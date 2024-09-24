/**
* The robot has to move total (m + n - 2) steps, include: (m - 1) steps down, (n - 1) steps right.
* The number of unique paths is the number of ways that robot moves (m - 1) steps down
* (or (n - 1) steps right) in total (m + n - 2) steps.
* The answer is C(m - 1, m + n - 2) (combination of m + n - 2 choose m - 1).
*/
unsigned long long int combination(int k, int n) {
    unsigned long long int result[1000][1000];
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= i; j++) {
            if(j == 0 || j == i) {
                result[i][j] = 1;
            }
            else {
                result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
            }
        }
    }
    return result[n][k];
}

int uniquePaths(int m, int n) {
    int result;
    if(m == 1 || n == 1) {
        //Edge case: Go right only or go down only
        result = 1;
    }
    else {
        result = combination(m - 1, m + n - 2);
    }
    return result;
}
