class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        for(int i=0; i<n-m+1; i++) {
            int flag = 1;
            for(int j=0; j<m; j++) {
                if(needle[j] != haystack[i+j]) {
                    flag = 0;
                    break;
                }
            }
            if(flag)
                return i;
        }
        return -1;
    }
};