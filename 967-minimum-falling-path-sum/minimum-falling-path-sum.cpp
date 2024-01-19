class Solution {
public:
    int n;

    int minFallingPathSum(vector<vector<int>>& a) {
        n = a.size();
        if(n == 1) {
            return a[0][0];
        }
        for(int i=n-2; i>=0; i--) {
            for(int j=0; j < n; j++) {
                int count = a[i + 1][j];
                if(j > 0) {
                    count = min(count, a[i + 1][j - 1]);
                }
                if(j < n - 1) {
                    count = min(count, a[i + 1][j + 1]);
                }
                a[i][j] += count;
            }
        }
        int ans = INT_MAX;
        for(int j=0; j<n; j++) {
            ans = min(ans, a[0][j]);
        }
        return ans;
    }
};