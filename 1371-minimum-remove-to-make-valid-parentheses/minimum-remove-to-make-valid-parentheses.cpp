class Solution {
public:
    int n;
    string ans = "";

    string minRemoveToMakeValid(string s) {
        n = s.size();
        int open = 0;
        for(int i=0; i<n; i++) {
            if(s[i] == '(') {
                open++;
            }
            else if(s[i] == ')') {
                if(open == 0) {
                    s[i] = '*';
                }
                else {
                    open--;
                }
            }
        }            
        for(int i=n-1; i>=0; i--) {
            if(open > 0 && s[i] == '(') {
                s[i] = '*';
                open--;
            }
        }
        for(int i=0; i<n; i++) {
            if(s[i] == '*') {
                continue;
            }
            ans += s[i];
        }
        return ans;
    }
};