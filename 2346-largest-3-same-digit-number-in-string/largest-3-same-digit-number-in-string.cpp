class Solution {
public:
    int n;
    string ans = "";

    string largestGoodInteger(string s) {
        n = s.size();
        char mx = '0'-1;
        for(int i=0; i<n-2; i++) {
            if(s[i] == s[i+1] && s[i+1] == s[i+2]) {
                mx = max(mx, s[i]);
            }
        }
        if(mx == '0'-1) {
            return "";
        }
        for(int i=0; i<3; i++) {
            ans.push_back(mx);
        }    
        return ans;
    }
};