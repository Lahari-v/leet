class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for(int i=0; i<nums.size(); i++) {
            if(ans.empty() || ans.back() != nums[i])
                ans.push_back(nums[i]);
        }
        int n = ans.size();
        if(n<3)
            return ans[n-1];
        else
            return ans[n-3];
    }
};