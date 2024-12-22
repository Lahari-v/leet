class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int pos = 0;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            if(nums[i] != 0) {
                nums[pos] = nums[i];
                pos++;
            }
        }
        for(int i=pos; i<n; i++) {
            nums[i] = 0;
        }
    }
};