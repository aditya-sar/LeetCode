class Solution {
public:
    int n;

    string reverseWords(string s) {
        s.push_back('.');
        n = s.size();
        string t = "", ans = "";
        for(int i=0; i<n; i++) {
            if(s[i] == ' ' || s[i] == '.') {
                reverse(t.begin(), t.end());
                ans += t;
                if(s[i] == ' ') {
                    ans.push_back(' ');
                }
                t.clear();
            }
            else {
                t.push_back(s[i]);
            }
        }    
        return ans;
    }
};