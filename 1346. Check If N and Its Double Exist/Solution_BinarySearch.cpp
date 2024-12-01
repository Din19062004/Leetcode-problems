class Solution {
public:
    bool binarySearch(vector<int>& arr, int l, int r, int key) {
        while(l <= r) {
            int m = (l + r)/2;
            if(arr[m] == key) {
                return true;
            }
            else if(arr[m] > key) {
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return false;
    }
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int i = 0;
        int j = arr.size() - 1;
        for(int a : arr) {
            if(a != 0 && binarySearch(arr, i, j, a * 2)) {
                return true;
            }
        }
        //Edge case: The array includes more than one 'zero' elements
        int zeroCount = count(arr.begin(), arr.end(), 0);
        return zeroCount > 1;
    }
};
