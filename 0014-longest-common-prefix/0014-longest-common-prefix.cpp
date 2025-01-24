class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        for(int c=0; ; c++) {
            if(c == strs[0].size())
                return strs[0];
            for(int i=1; i<n; i++) {
                if(strs[0][c] != strs[i][c])
                    return strs[0].substr(0, c);
            }
        }
    }
};