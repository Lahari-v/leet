class Solution {
public:
    bool solve(int i, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if (target == 0)
            return true;
        if (i == 0)
            return nums[i] == target;
        if (dp[i][target] != -1) {
            return dp[i][target];
        }
        int not_take = solve(i - 1, target, nums, dp);
        int take = false;
        if (target >= nums[i]) {
            take = solve(i - 1, target - nums[i], nums, dp);
        }
        return dp[i][target] = take || not_take;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        if (sum % 2 == 0) {
            int target = sum / 2;
            vector<vector<int>> dp(n, vector<int>(target + 1, -1));
            return solve(n - 1, target, nums, dp);
        }
        return false;
    }
};