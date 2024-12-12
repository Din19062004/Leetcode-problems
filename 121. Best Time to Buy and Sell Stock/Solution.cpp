class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int length = prices.size();
        // minPrice is the minimum price we have encounSolution
        int minPrice = INT_MAX;
        // maxProfit is the maximum profit we can have
        int maxProfit = 0;
        for(int i = 0; i < length; i++) {
            minPrice = min(minPrice, prices[i]);
            if(minPrice < prices[i]) {
                maxProfit = max(maxProfit, prices[i] - minPrice);
            }
        }
        return maxProfit;
    }
};
