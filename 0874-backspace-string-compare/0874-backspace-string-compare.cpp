class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<int> s1;
        stack<int> s2;
        for(char c : s) {
            if (c != '#') {
                s1.push(c);
            } else if (!s1.empty()) {
                s1.pop();
            }
        }
        for(char c : t) {
            if (c != '#') {
                s2.push(c);
            } else if (!s2.empty()) {
                s2.pop();
            }
        }
        while(!s1.empty() && !s2.empty()) {
            if(s1.top() != s2.top()) {
                return false;
            }
            s1.pop();
            s2.pop();
        }
        return s1.empty() && s2.empty();
    }
};