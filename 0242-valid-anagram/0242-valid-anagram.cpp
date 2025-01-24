class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        unordered_map<char, int> map;
        for(char c : s) {
            map[c]++;
        }
        for(char c : t) {
            map[c]--;
            if(map[c] < 0)
                return false;
        }
        return true;
    }
};