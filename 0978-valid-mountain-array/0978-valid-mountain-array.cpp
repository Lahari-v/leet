class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size(); 
        if(n<3)
            return false;
        int peak = 0;
        for(int i=1; i<n; i++) {
            if(arr[i-1] >= arr[i]) {
                peak = i-1;
                break;
            }
        }
        if(peak == 0)
            return false;
        for(int i=peak+1; i<n; i++) {
            if(arr[i-1] <= arr[i])
                return false;
        }
        return true;
    }
};