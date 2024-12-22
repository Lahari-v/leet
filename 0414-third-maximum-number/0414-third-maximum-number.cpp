class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> st;
        vector<int> res;
        for(int i=0; i<nums.size(); i++) {
            st.insert(nums[i]);
        }
        for(int i : st) {
            res.push_back(i);
        }
        
        int n = res.size();
        for(int i=0; i<n; i++) {
            cout<<res[i];
        }
        if(n < 3) {
            return res[n-1];
        }
        return res[n-3];
    }
};