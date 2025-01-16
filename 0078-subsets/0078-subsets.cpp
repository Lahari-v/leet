class Solution {
public:
    void solve(int idx, int n, vector<int>& ds, vector<vector<int>>& res, vector<int>& nums) {
        if(idx == n) {
            res.push_back(ds);
            return;
        }
        ds.push_back(nums[idx]);
        solve(idx + 1, n, ds, res, nums);
        ds.pop_back();

        solve(idx + 1, n, ds, res, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ds;
        solve(0, nums.size(), ds, res, nums);
        return res;
    }
};