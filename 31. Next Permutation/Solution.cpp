/**
* Algorithm to find the next permutation of an array:
* Step 1: From right to left, find the first element where array[i - 1] < array[i].
* Step 2: From right to left, find the first element where array[j] > array[i - 1].
* Step 3: Swap array[i - 1] and array[j].
* Step 4: Reverse the array[i...n]
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1;
        while(i > 0 && nums[i - 1] >= nums[i]) {
            i--;
        }
        if(i == 0) {
            sort(nums.begin(), nums.end());
            return;
        }

        int j = nums.size() - 1;
        while(nums[j] <= nums[i - 1]) {
            j--;
        }

        swap(nums[i - 1], nums[j]);
        reverse(nums.begin() + i, nums.end());
    }
};
