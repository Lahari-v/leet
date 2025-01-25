class Solution {
public:
    int myAtoi(string s) {
        int i=0, n = s.size();
        int res = 0, sign = 1;
        while(i<n && s[i] == ' ') {
            i++;
        }
        if(i<n && (s[i] == '+' || s[i] == '-')) {
            if(s[i] == '-')
                sign = -1;
            else
                sign = 1;

            i++;
        }
        while(i<n && isdigit(s[i])) {
            int digit = s[i] - '0';

            if(res > (INT_MAX - digit) / 10) {
                if(sign == 1)
                    return INT_MAX;
                else 
                    return INT_MIN;
            }

            res = res * 10 + digit;
            i++;
        }
        return res * sign;
    }
};