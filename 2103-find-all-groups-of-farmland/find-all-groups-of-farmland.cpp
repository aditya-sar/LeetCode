class Solution {
public:
    int n, m;
    vector<vector<int>> ans;

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        n=land.size();
        m=land[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(land[i][j] == 1 && ((i == 0 || land[i-1][j] == 0) && (j == 0  || land[i][j-1] == 0))) {
                    int left = i, right = j;
                    while(left < n && land[left][right] == 1) {
                        left++;
                    }
                    left--;
                    while(right < m && land[left][right] == 1) {
                        right++;
                    }
                    right--;
                    ans.push_back({i, j, left, right});
                    j = right;
                }
            }
        }  
        return ans;
    }
};