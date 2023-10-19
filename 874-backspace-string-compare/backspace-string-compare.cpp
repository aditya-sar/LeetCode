class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> stk1, stk2;
        for(char &c : s) {
            if(c != '#') {
                stk1.push(c);
            }
            else {
                if(!stk1.empty()) {
                    stk1.pop();
                }
            }
        }
        for(char &c : t) {
            if(c != '#') {
                stk2.push(c);
            }
            else {
                if(!stk2.empty()) {
                    stk2.pop();
                }
            }
        }
        if(stk1.size() != stk2.size()) {
            return false;
        }
        while(!stk1.empty()) {
            char c1 = stk1.top();
            char c2 = stk2.top();
            stk1.pop();
            stk2.pop();
            if(c1 != c2) {
                return false;
            }
        }
        return true;
    }
};