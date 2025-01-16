class Solution {
public:
    void solve(int idx, int n, vector<int>& ds, vector<vector<int>>& res, vector<int>& nums) {
        res.push_back(ds);
        for(int i=idx; i<n; i++) {
            ds.push_back(nums[i]);
            solve(i+1, n, ds, res, nums);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ds;
        solve(0, nums.size(), ds, res, nums);
        return res;
    }
};