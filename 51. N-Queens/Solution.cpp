//Back-tracking

class Solution {
private:
    vector<vector<string>> answer; 
    vector<int> x;
public:
    bool check(int v, int k) {
        for(int i = 1; i <= k - 1; i++) {
            if(x[i] == v || x[i] + i == v + k || x[i] - i == v - k) {
                return false;
            }
        }
        return true;
    }

    void getSolution(int n) {
        vector<string> board(n, string(n, '.'));
        for(int i = 1; i <= n; i++) {
            board[x[i] - 1][i - 1] = 'Q';
        }
        answer.push_back(board);
    }

    void Try(int k, int n) {
        for(int v = 1; v <= n; v++) {
            if(check(v, k)) {
                x[k] = v;
                if(k == n) {
                    getSolution(n);
                }
                else {
                    Try(k + 1, n);
                }
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        x.resize(n + 1);
        Try(1, n);
        return answer;
    }
};
