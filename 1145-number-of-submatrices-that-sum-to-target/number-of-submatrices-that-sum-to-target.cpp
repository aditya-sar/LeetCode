class Solution {
public:
    int n, m;
    int ans = 0;

    int numSubmatrixSumTarget(vector<vector<int>>& a, int target) {
        n = a.size();
        m = a[0].size();    
        for(int i=0; i<n; i++) {
            for(int j=1; j<m; j++) {
                a[i][j] += a[i][j-1];
            }
        }
        for(int i=0; i<m; i++) {
            for(int j=i; j<m; j++) {
                unordered_map<int, int> mp;
                mp[0] = 1;
                int sum = 0;
                for(int r=0; r<n; r++) {
                    sum += a[r][j];
                    if(i > 0) {
                        sum -= a[r][i-1];
                    }
                    ans += mp[sum - target];
                    mp[sum]++;
                }
            }
        }
        return ans;
    }

};