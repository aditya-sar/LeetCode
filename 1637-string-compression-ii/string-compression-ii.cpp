class Solution {
public:
    int n;
    int getLengthOfOptimalCompression(string s, int k) {
        n = s.size();
        vector<vector<int>> dp(120, vector<int>(120));
        for(int i=1; i <= n; ++i) {
            for(int j=0; j <= i && j <= k; j++) {
                int remove = 0;
                int count = 0;
                dp[i][j] = INT_MAX;
                if (j) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                for (int l=i; l >= 1; l--) {
                    if(s[l - 1] != s[i - 1]) {
                        remove += 1;
                    } 
                    else {
                        count += 1;
                    }
                    if(remove > j) {
                        break;
                    }
                    if(count == 1) {
                        dp[i][j] = min(dp[i][j], dp[l - 1][j - remove] + 1);
                    } 
                    else if (count < 10) {
                        dp[i][j] = min(dp[i][j], dp[l - 1][j - remove] + 2);
                    } 
                    else if (count < 100) {
                        dp[i][j] = min(dp[i][j], dp[l - 1][j - remove] + 3);
                    } 
                    else {
                        dp[i][j] = min(dp[i][j], dp[l - 1][j - remove] + 4);
                    }
                }
            }
        }
        return dp[n][k];
    }
};