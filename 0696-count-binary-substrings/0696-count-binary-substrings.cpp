class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        int temp[n];
        temp[0] = 1; 
        int idx = 0, sum = 0;
        for(int i=1; s[i]; i++) {
            if(s[i] == s[i-1]) {
                temp[idx]++;
            }
            else {
                temp[++idx] = 1;
            }
        }
        for(int i=0; i<idx; i++) {
            sum += min(temp[i], temp[i+1]);
        }
        return sum;
    }
};