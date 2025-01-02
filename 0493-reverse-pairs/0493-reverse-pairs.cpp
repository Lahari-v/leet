class Solution {
public:
    void merge(int l, int m, int r, vector<int>& nums) {
        vector<int> temp;
        int left = l;
        int right = m+1; 
        while(left <= m && right <= r) {
            if(nums[left] <= nums[right]) {
                temp.push_back(nums[left]);
                left++;
            }
            else {
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left <= m) {
            temp.push_back(nums[left]);
            left++;
        }
        while(right <= r) {
            temp.push_back(nums[right]);
            right++;
        }
        for(int i=l; i<=r; i++) {
            nums[i] = temp[i-l];
        }
    }
    int countPairs(int l, int m, int r, vector<int>& nums) {
        int right = m+1;
        int count = 0;
        for(int i=l; i<=m; i++) {
            while(right <= r && nums[i] > 2LL*nums[right]) {
                right++;
            }
            count += (right - (m+1));
        }
        return count;
    }
    int mergeSort(int l, int r, vector<int>& nums) {
        int count = 0;
        int m = l + (r-l)/2; 
        if(l>=r)
            return count;
        count += mergeSort(l, m, nums);
        count += mergeSort(m+1, r, nums);
        count += countPairs(l, m, r, nums);
        merge(l, m, r, nums);
        return count;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(0, n-1, nums);
    }
};