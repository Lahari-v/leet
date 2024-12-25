class Solution {
public:
    string reverseWords(string s) {
        string res;
        int idx = 0;
        for(int i=0; i<=s.size(); i++) {
            if(i == s.size() || s[i] == ' ') {
                if(idx < i) {
                    if(!res.empty())
                        res = " " + res;
                    res = s.substr(idx, i-idx) + res;
                }
                idx = i+1;
            } 
        }
        return res;
    }
};