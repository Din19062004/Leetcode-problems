class Solution {
private:
    vector<int> x;
    vector<vector<int>> result;
public:
    void Try(int m, int n, int k) {
        for(int v = x[k - 1] + 1; v <= n - m + k; v++) {
            x[k] = v;
            if(k == m) {
                result.push_back(vector<int>(x.begin() + 1, x.begin() + m + 1));
            }
            else {
                Try(m, n, k + 1);
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        x.resize(k + 1, 0);
        Try(k, n, 1);
        return result;
    }
};
