class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), res = 0;
        int l = 0, r = n-1;
        int leftMax = height[l], rightMax = height[r];
        while(l < r) {
            if(leftMax <= rightMax) {
                l++;
                leftMax = max(leftMax, height[l]);
                int temp = leftMax - height[l];
                if(temp > 0)
                    res += temp;
            }
            else {
                r--;
                rightMax = max(rightMax,height[r]);
                int temp = rightMax - height[r];
                if(temp > 0) 
                    res += temp;
            }
        }
        return res;
    }
};