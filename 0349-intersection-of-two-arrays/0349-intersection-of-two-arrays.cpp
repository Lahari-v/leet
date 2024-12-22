class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> st;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n1 = nums1.size();
        int n2 = nums2.size();
        int p1 = 0, p2 = 0;
        while(p1 < n1 && p2 < n2) {
            if(nums1[p1] == nums2[p2]) {
                st.insert(nums1[p1]);
                p1++;
                p2++;
            }
            else if(nums1[p1] < nums2[p2]) {
                p1++;
            }
            else {
                p2++;
            }
        }
        vector<int> res;
        for(int ele : st) {
            res.push_back(ele);
        }
        return res;
    }
};