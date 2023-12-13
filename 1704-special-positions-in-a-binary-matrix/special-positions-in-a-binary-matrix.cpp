class Solution {
public:
    int n;
    int m;
    int ans = 0;

    int numSpecial(vector<vector<int>>& mat) {
        n = mat.size();
        m = mat[0].size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(mat[i][j] == 1) {
                    int ones = 0;
                    for(int w=0; w<m; w++) {
                        if(w != j && mat[i][w] == 1) {
                            ones++;
                        }
                    }    
                    for(int h=0; h<n; h++) {
                        if(h != i && mat[h][j] == 1) {
                            ones++;
                        }
                    }
                    if(ones == 0) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};