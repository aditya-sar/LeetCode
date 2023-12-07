class Solution {
public:
    int n;
    string ans = "";

    string largestOddNumber(string s) {
        n = s.size();
        for(int i=n-1; i>=0; i--) {
            if((s[i] - '0') % 2 == 1) {
                ans = s.substr(0, i+1);
                return ans;
            }
        }
        return "";
    }
};