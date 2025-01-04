class Solution {
public:
    int solve(int i, int amount, vector<int>& coins, vector<vector<int>>& dp) { 
        if(i==0) {
            if(amount % coins[0] == 0)
                return amount/coins[0]; 
            return INT_MAX;
        } 
        if(dp[i][amount] != -1)
            return dp[i][amount];

        int take = INT_MAX;
        if(amount >= coins[i]) {
            int res = solve(i, amount - coins[i], coins, dp);
            if(res != INT_MAX)
                take = 1 + res;
        }
        int not_take = solve(i-1, amount, coins,dp);
        return dp[i][amount] = min(take, not_take);
    } 
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int res =  solve(n-1, amount, coins, dp);
        if(res == INT_MAX)
            return -1;
        return res;
    }
};