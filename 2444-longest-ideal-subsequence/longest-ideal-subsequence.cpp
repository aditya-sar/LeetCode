class Solution {
public:
    int n;
    vector<int> dp;

    int longestIdealString(string s, int k) {
        n = s.size();
        dp.resize(27);

        for(int i=n-1; i>=0; i--) {
            char c = s[i];
            int pos = c - 'a';
            int maxPos = INT_MIN;
            int left = max((pos - k), 0);
            int right = min((pos + k), 26);
            for(int j=left; j<=right; j++) {
                maxPos = max(maxPos, dp[j]);
            }
            dp[pos] = maxPos + 1;
        }

        int max = INT_MIN;

        for(int i=0; i<27; i++) {
            if(dp[i] > max) {
                max = dp[i];
            }
        }
        return max;
    }
};