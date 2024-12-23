class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1, s2;

        // Process the first string
        for (char c : s) {
            if (c == '#' && !s1.empty())
                s1.pop();  // Remove the top if it's a backspace and the stack is not empty
            else 
                s1.push(c);  // Otherwise, add the character to the stack
        }

        // Process the second string
        for (char c : t) {
            if (c == '#' && !s2.empty())
                s2.pop();  // Same as above, handle backspace
            else 
                s2.push(c);  // Otherwise, push the character onto the stack
        }

        // Compare the two stacks element by element
        while (!s1.empty() && !s2.empty()) {
            if (s1.top() != s2.top()) {
                return false;  // If any character doesn't match, return false
            }
            s1.pop();
            s2.pop();
        }

        // After comparison, check if both stacks are empty
        return s1.empty() && s2.empty();
    }
};