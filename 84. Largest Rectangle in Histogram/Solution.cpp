/**
* Try to find the nearest value which is smaller than the current value to both left side and right side of current value
* The area of the rectangle is calculated by: heights * (right - left + 1)
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s1, s2;
        int n = heights.size();
        vector<int> left(n), right(n);

        //Find the nearest value which is smaller than the current value to the left side.
        //If it exists, return the position of it and plus 1, else return 0.
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

        //Find the nearest value which is smaller than the current value to the right side
        //If it exists, return the position of it and minus 1, else return n - 1.
        right[n - 1] = n - 1;
        s2.push(n - 1);
        for(int i = n - 2; i >= 0; i--) {
            while(!s2.empty() && heights[i] <= heights[s2.top()]) {
                s2.pop();
            }
            int tmp = (s2.empty()) ? (n - 1) : (s2.top() - 1);
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
};
