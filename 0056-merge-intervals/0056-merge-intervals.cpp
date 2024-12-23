class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end()); 
        res.push_back(intervals[0]);
        for(int i=1; i<n; i++) {
            vector<int>& last = res.back();
            if(last[1] >= intervals[i][0]) {
                last[1] = max(last[1], intervals[i][1]);
            }
            else
                res.push_back(intervals[i]);
        }
        return res;
    }
};