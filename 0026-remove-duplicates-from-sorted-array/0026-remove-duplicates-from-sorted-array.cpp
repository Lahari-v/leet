class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 0;
        int n = nums.size();
        for(int i=1; i<n; i++) {
            if(nums[idx] != nums[i]) {
                nums[++idx] = nums[i];
            }
        }
        return idx+1;
    }
};