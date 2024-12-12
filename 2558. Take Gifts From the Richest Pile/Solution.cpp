class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> remain;
        for(int gift : gifts) {
            remain.push(gift);
        }

        for(int i = 1; i <= k; i++) {
            int max = remain.top();
            remain.pop();
            remain.push(sqrt(max));
        }

        long long result = 0;
        while(!remain.empty()) {
            result += remain.top();
            remain.pop();
        }
      
        return result;
    }
};
