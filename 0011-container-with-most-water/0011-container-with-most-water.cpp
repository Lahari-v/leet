class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxA = 0;
        int n = height.size();
        int l = 0, r = n-1 ;
        while(l < r) {
            int dist = r-l;
            int ht = min(height[l], height[r]);
            maxA = max(maxA, ht*dist);
            if(height[l] < height[r])
                l++;
            else
                r--;
        }
        return maxA;
    }
};