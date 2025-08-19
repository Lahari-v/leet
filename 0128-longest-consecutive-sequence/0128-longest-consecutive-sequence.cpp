class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int i=0; i<nums.size(); i++) {
            s.insert(nums[i]);
        }
        int currentStreak = 0, maxStreak = 0;
        for(int num : s) { 
            if(s.find(num-1) == s.end()) {
                currentStreak = 1;
                while(s.find(num+1) != s.end()) {
                    currentStreak++;
                    num++;
                }
                maxStreak = max(maxStreak, currentStreak);
            }
        }
        return maxStreak;
    }
};