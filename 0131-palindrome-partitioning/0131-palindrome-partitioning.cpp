class Solution {
public:
    bool isPalindrome(int l, int r, string& s) {
        while(l<r) {
            if(s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    void solve(int idx, int n, vector<string>& ds, vector<vector<string>>& res, string& s) {
        if(idx == n) {
            res.push_back(ds);
        }
        for(int i=idx; i<n; i++) {
            if(isPalindrome(idx, i, s)) {
                ds.push_back(s.substr(idx, i-idx+1));
                solve(i+1, n, ds, res, s);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> ds;
        solve(0, s.size(), ds, res, s);
        return res;
    }
};