class Solution {
public:
    int n, m;
    int ans = 0;

    int largestSubmatrix(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        vector<vector<int>> ones(n);
        for(int j=0; j<m; j++) {
            int count = 0;
            for(int i=0; i<n; i++) {
                if(matrix[i][j] == 1) {
                    count++;
                }
                else {
                    count = 0;
                }
                ones[i].push_back(count);
            }
        }
        for(int i=0; i<n; i++) {
            sort(ones[i].rbegin(), ones[i].rend());
            int mx = -1;
            for(int j=0; j<m; j++) {
                mx = max(mx, ones[i][j] * (j + 1));
            }
            ans = max(ans, mx);
        }
        return ans;
    }
};