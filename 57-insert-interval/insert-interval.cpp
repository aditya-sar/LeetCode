class Solution {
public:
    vector<vector<int>> ans;
    int n;

    vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& newInterval) {
        int pos = 0;
        n = a.size();
        while(pos < n && a[pos][1] < newInterval[0]) {
            ans.push_back(a[pos]);
            pos++;
        }
        while(pos < n && a[pos][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], a[pos][0]);
            newInterval[1] = max(newInterval[1], a[pos][1]);
            pos++;
        }        
        ans.push_back(newInterval);
        while(pos < n) {
            ans.push_back(a[pos]);
            pos++;
        }
        return ans;
    }
};