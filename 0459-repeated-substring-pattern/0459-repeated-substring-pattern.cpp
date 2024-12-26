class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.size();
        for(int i=1; i<len; i++) {
            if(len%i == 0) {
                int notRepeated = 1;
                for(int j=i; j<len; j++) {
                    if(s[j] != s[j-i]) {
                        notRepeated = 0;
                        break;
                    }
                }
                if(notRepeated) 
                    return true;
            }
        }
        return false;
    }
};