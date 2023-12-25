class Solution {
public:
    int solve(string s, int pos, unordered_map<int, int> &dp) {
        if(pos >= s.size()) {
            return 1;
        }
        if(dp.find(pos) != dp.end()) {
            return dp[pos];
        }
        int ans = 0, one = 0, two = 0;
        one = s[pos] - '0';
        if(pos + 1 < s.size()) {
            two = one * 10 + (s[pos+1] - '0');
        }
        if(one > 0) {
            ans += solve(s, pos+1, dp);
        }
        if(one > 0 && two >= 1 && two <= 26) {
            ans += solve(s, pos+2, dp);
        }
        dp[pos] = ans;
        return ans;
    }
    int numDecodings(string s) {
        unordered_map<int, int> dp;
        int pos = 0;
        return solve(s, pos, dp);
    }
};