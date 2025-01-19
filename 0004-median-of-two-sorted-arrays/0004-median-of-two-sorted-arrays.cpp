class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        int n1 = nums1.size(), n2 = nums2.size();
        int n = n1+n2;
        int cnt = 0, idx1 = (n/2) - 1 , idx2 = n/2;
        int idx1ele = -1, idx2ele = -1;
        while(i<n1 && j<n2) {
            if(nums1[i] <= nums2[j]) {
                if(cnt == idx1) 
                    idx1ele = nums1[i];
                else if(cnt == idx2)
                    idx2ele = nums1[i];
                cnt++;
                i++;
            }
            else {
                if(cnt == idx1) 
                    idx1ele = nums2[j];
                else if(cnt == idx2)
                    idx2ele = nums2[j];
                cnt++;
                j++;
            }
        }
        while(i<n1) {
            if(cnt == idx1) 
                idx1ele = nums1[i];
            else if(cnt == idx2)
                idx2ele = nums1[i];
            cnt++;
            i++;
        }
        while(j<n2) {
            if(cnt == idx1) 
                idx1ele = nums2[j];
            else if(cnt == idx2)
                idx2ele = nums2[j];
            cnt++;
            j++;
        }
        if(n%2 != 0)
            return idx2ele;
        return (double(idx1ele + idx2ele)) / 2.0;
    }
};