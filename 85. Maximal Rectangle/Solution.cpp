/**
* Use histogram (problem 84) to find each row's maximal area
*/

class Solution {
public:
    int histogram(vector<int> &heights) {
        int n = heights.size();
        stack<int> s1, s2;
        vector<int> left(n), right(n);

        s1.push(0);
        left[0] = 0;
        for(int i = 1; i < n; i++) {
            while(!s1.empty() && heights[i] <= heights[s1.top()]) {
                s1.pop();
            }
            int tmp = (s1.empty()) ? 0 : s1.top() + 1;
            s1.push(i);
            left[i] = tmp;
        }

        s2.push(n - 1);
        right[n - 1] = n - 1;
        for(int i = n - 2; i >= 0; i--) {
            while(!s2.empty() && heights[i] <= heights[s2.top()]) {
                s2.pop();
            }
            int tmp = (s2.empty()) ? n - 1 : s2.top() - 1;
            s2.push(i);
            right[i] = tmp;
        }
        int result = 0;
        for(int i = 0; i < n; i++) {
            int width = right[i] - left[i] + 1;
            int area = width * heights[i];
            result = max(result, area);
        }
        return result;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> heights(col, 0);
        
        int result = 0;
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                heights[j] = (matrix[i][j] == '1') ? heights[j] + 1 : 0;
            }
            result = max(result, histogram(heights));
        }
        return result;
    }
};
