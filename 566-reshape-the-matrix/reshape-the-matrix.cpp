class Solution {
public:
    int n, m;

    vector<vector<int>> matrixReshape(vector<vector<int>>& a, int r, int c) {
        n = a.size();
        m = a[0].size();
        if(m*n != r*c) {
            return a;
        }    
        vector<vector<int>> ans(r, vector<int>(c));
        int x = 0, y = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                int elem = a[i][j];
                if(y >= c) {
                    y = 0;
                    x += 1;
                }
                ans[x][y] = elem;
                y++;
            }
        }
        return ans;
    }
};