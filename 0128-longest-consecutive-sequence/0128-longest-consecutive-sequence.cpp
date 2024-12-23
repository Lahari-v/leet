class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            st.insert(nums[i]);
        }
        int max_streak = 0;
        for(int i=0; i<n; i++) {
            int current_streak = 1;
            int current_num = nums[i];
            if(st.find(current_num - 1) == st.end()) {
                while(st.find(current_num + 1) != st.end()) {
                    current_streak++;
                    current_num++;
                }
                max_streak = max(max_streak, current_streak);
            }
        }
        return max_streak;
    }
};