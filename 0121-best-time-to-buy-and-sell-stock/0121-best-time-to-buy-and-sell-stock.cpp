class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int min = prices[0];
        for(int i=1; i<prices.size(); i++) {
            if(prices[i] < min) {
                min = prices[i];
                continue;
            }
            maxProfit = max(maxProfit, prices[i]-min);
        }
        return maxProfit;
    }
};