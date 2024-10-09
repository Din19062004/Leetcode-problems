class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0, end = 0;
        for(char c : s) {
            if(c == '(') {
                open++;
            }
            else {
                //The current ')' can match a previous '('.
                if(open > 0) {
                    open--;
                }
                //No matching '(', need to insert the new one
                else {
                    end++;
                }
            }
        }
        return (open + end);
    }
};
