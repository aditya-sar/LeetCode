class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int rowMin = INT_MAX, colMin = INT_MAX;
        if(ops.empty()) {
            return m*n;
        }
        for(vector<int> v : ops) {
            rowMin = min(v[0], rowMin);
            colMin = min(v[1], colMin);
        }
        return rowMin * colMin;
    }
};