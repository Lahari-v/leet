class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<int, int> map;
        for(int i=0; i<s.size(); i++) {
            if(s[i] >= 'a' && s[i] <= 'z')
                map[s[i] - 'a']++;
            if(s[i] >= 'A' && s[i] <= 'Z')
                map[s[i] - 'A']++;
        }
        int res = 0, r = 0;
        for(int i=0; i<54; i++) {
            if(map[i] % 2 == 0) {
                res += map[i];
            }
            else {
                res += map[i] - 1;
                r = 1;
            }
        }
        return res + r;
    }
};