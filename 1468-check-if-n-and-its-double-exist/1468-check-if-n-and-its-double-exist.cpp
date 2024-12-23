class Solution {
public:
    bool checkIfExist(vector<int>& arr) { 
        unordered_map<int, int> map;
        for(int n : arr) {
            map[n]++;
        }
        for(int i=0; i<arr.size(); i++) {
            int target = 2 * arr[i];
            if(arr[i] != 0 && map.find(target) != map.end()) {
                return true;
            }
            if(arr[i] == 0 && map[arr[i]] > 1) {
                return true;
            }
        }
        return false;
    }
};