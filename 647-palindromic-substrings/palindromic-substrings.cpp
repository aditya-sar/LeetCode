class Solution {
public:
    int n;
    int ans = 0;
    int dp[1001][1001];

    bool isPal(string &s, int i, int j) {
        if(j < i) {
            return true;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        if(s[i] == s[j]) {
            return isPal(s, i+1, j-1);
        }
        return false;
    }

    int countSubstrings(string s) {
        n = s.size();
        memset(dp, -1, sizeof(dp));
        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                if(isPal(s, i, j)) {
                    ans++;
                }
            }
        }   
        return ans;
    }
};