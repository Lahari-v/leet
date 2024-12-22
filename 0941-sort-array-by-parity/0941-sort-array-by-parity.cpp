class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        while(l<r) {
            if(nums[r] % 2 == 0 || nums[r] == 0) {
                int temp = nums[l];
                nums[l] = nums[r];
                nums[r] = temp;
                l++;
                if(nums[r] % 2 != 0)
                    r--;
            }
            else {
                r--;
            }
        }
        return nums;
    }
};