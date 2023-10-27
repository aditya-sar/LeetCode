class Solution {
public:
    string span(string s, int left, int right) {
        string pal = "";
        int n = s.size();
        while(left >= 0 and right < n and s[left] == s[right]) {
            pal = s.substr(left, right - left + 1);
            left--;
            right++;
        }
        return pal;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        if(n == 1) {
            return s;
        }
        /*
            abba 
            aba
        */
        string ans = "";
        for(int i=1; i<n; i++) {
            string odd = span(s, i, i);
            string even = span(s, i, i-1);
            if(odd.size() > ans.size()) {
                ans = odd;
            }
            if(even.size() > ans.size()) {
                ans = even;
            }
        }
        return ans;
    }
};