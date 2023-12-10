class Solution {
public:
    int n, m;
    vector<vector<int>> ans;

    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        for(int j=0; j<m; j++) {
            vector<int> v;
            for(int i=0; i<n; i++) {
                v.push_back(matrix[i][j]);
            }
            ans.push_back(v);
        }        
        return ans;
    }
};