class Solution {
public:
    long long findScore(vector<int>& nums) {
        int length = nums.size();
        vector<pair<int, int>> numWithIndex(length);

        // Store each element with its index
        for(int i = 0; i < length; i++) {
            numWithIndex[i] = {nums[i], i};
        }

        // Sort the vector in ascending order: by value, then by index
        sort(numWithIndex.begin(), numWithIndex.end());

        long long score = 0;

        // Loops:
        for(int i = 0; i < length; i++) {
            int num = numWithIndex[i].first;
            int index = numWithIndex[i].second;

            if(nums[index] != -1) {
                score += num;
                nums[index] = -1;         // Mark this value
                if(index > 0) {
                    nums[index - 1] = -1; // Mark its left neightbor
                }
                if(index < length - 1) {
                    nums[index + 1] = -1; // Mark its right neighbor
                }
            }
        }
        return score;
    }
};
