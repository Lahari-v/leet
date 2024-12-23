class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp1; 
        for(char c : magazine) {
            mp1[c]++;
        }
        for(char c : ransomNote) {
            mp1[c]--;
        }
        for(char i='a'; i<='z'; i++) {
            if(mp1[i] < 0) {
                return false;
            }
            cout<<mp1[i];
        }
        return true;
    }
};