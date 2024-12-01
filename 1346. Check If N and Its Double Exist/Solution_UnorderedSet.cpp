class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> seen;
        int countZero = 0;

        for(int a : arr) {
            if(a == 0) {
                countZero++;
                if(countZero == 2) {
                    return true;
                }
            }
            else {
                if(seen.count(a * 2) || (a % 2 == 0) && seen.count(a / 2)) {
                    return true;
                }
            }
            seen.insert(a);
        }
        return false;
    }
};
