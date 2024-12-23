class Solution {
public:
    void recurPermute(int index, vector<int>& nums, vector<vector<int>>& res) {
        if(index == nums.size()) {
            res.push_back(nums);
            return;
        }
        for(int i=index; i<nums.size(); i++) {
            swap(nums[i], nums[index]);
            recurPermute(index+1, nums, res);
            swap(nums[i], nums[index]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        recurPermute(0, nums, res);
        return res;
    }
};