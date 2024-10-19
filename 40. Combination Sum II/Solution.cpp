class Solution {
private:
    vector<int> x;
    vector<vector<int>> result;
    int currSum = 0;
public:
    bool check(int v, int k, vector<int> &candidates, int target, int i) {
        if(currSum + v > target) {
            return false;
        }
        if(i > k && candidates[i] == candidates[i - 1]) {
            return false;
        }
        return true;
    }

    void Try(int k, vector<int> &candidates, int target) {
        for(int i = k; i < candidates.size(); i++) {
            int v = candidates[i];
            if(check(v, k, candidates, target, i)) {
                x.push_back(v);
                currSum += v;
                if(currSum == target) {
                    result.push_back(x);
                }
                else {
                    Try(i + 1, candidates, target);
                }
                currSum -= v;
                x.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        x.clear();
        result.clear();
        sort(candidates.begin(), candidates.end());
        Try(0, candidates, target);
        return result;
    }
};
