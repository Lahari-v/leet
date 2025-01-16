class Solution {
public:
    void solve(int idx, int n, vector<int>& ds, vector<vector<int>>& res, vector<int>& nums) {
        res.push_back(ds);
        for(int i=idx; i<n; i++) {
            if(i != idx && nums[i] == nums[i-1]) continue;
            ds.push_back(nums[i]);
            solve(i+1, n, ds, res, nums);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        solve(0, n, ds, res, nums);
        return res;
    }
};