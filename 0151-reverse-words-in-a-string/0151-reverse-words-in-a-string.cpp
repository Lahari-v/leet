class Solution {
public:
    string reverseWords(string s) {
        int n = s.size(), i=0, j=0;
        while(i < n) {
            if(s[i] == ' ')
                i++;
            break;
        }
        while(i < n) {
            if(s[i] != ' ' || (j>0 && s[i-1] != ' '))
                s[j++] = s[i];
            i++;
        }
        if(j>0 && s[j-1] == ' ') 
            j--;
        s.resize(j);
        reverse(s.begin(), s.end());
        int idx = 0;
        for(int i=0; i<=s.size(); i++) {
            if(i == s.size() || s[i] == ' ') {
                reverse(s.begin() + idx, s.begin() + i);
                idx = i+1;
            }
        }
        return s;
    }
};