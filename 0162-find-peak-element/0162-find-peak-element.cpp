class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int i = 1;
        for(i=1; i<nums.size(); i++) {
            if(nums[i] < nums[i-1]) {
                break;
            }
        }
        return i-1;
    }
};