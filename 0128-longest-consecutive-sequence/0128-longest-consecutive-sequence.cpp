class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            st.insert(nums[i]);
        }
        int res = 0;
        for(int num : nums) {
            int curr_num = num;
            int curr_streak = 1;
            if(st.find(curr_num - 1) == st.end()) {
                while(st.find(curr_num + 1) != st.end()) {
                    curr_num++;
                    curr_streak++;
                }
                res = max(res, curr_streak);
            }
        }
        return res;
    }
};