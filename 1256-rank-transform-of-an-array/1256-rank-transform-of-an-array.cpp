class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> arr1(arr);
        sort(arr1.begin(), arr1.end());
        unordered_map<int, int> mp;
        vector<int> res;
        int rank = 1;
        for(int i=0; i<n; i++) {
            if(mp.find(arr1[i]) == mp.end()) {
                mp[arr1[i]] = rank++;
            }
        } 
        for(int i=0; i<n; i++) {
            res.push_back(mp[arr[i]]);
        }
        return res;
    }
};