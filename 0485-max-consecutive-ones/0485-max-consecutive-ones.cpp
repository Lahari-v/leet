class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_len = 0;
        int len = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == 1) {
                len++;
                max_len = max(max_len, len);
            }
            else {
                len = 0;
            }
        }
        return max_len;
    }
};