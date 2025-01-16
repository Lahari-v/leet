class Solution {
public:
    void solve(int i, int n, int target, vector<int>& ds,
               vector<vector<int>>& res, vector<int>& candidates) {
        if (i == n) {
            if (target == 0) {
                res.push_back(ds);
                return;
            }
            return;
        }
        if (target >= candidates[i]) {
            ds.push_back(candidates[i]); 
            solve(i, n, target - candidates[i], ds, res, candidates);
            ds.pop_back();
        }
        solve(i+1, n, target, ds, res, candidates);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ds;
        solve(0, candidates.size(), target, ds, res, candidates);
        return res;
    }
};