class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<int, int> mp; 
        for(int i=0; i<magazine.size(); i++) {
            mp[magazine[i] - 'a']++;
        }
        for(int i=0; i<ransomNote.size(); i++) {
            mp[ransomNote[i] - 'a']--;
        }
        for(int i=0; i<26; i++) {
            if(mp[i] < 0) {
                return false;
            } 
        }
        return true;
    }
};