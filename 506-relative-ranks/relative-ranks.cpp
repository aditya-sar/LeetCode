class Solution {
public:
    int n;
    vector<string> ans;

    vector<string> findRelativeRanks(vector<int>& a) {
        n = a.size();
        ans.resize(n);
        vector<int> players = a;
        vector<pair<int, int>> v;
        for(int i=0; i<n; i++) {
            v.push_back(make_pair(a[i], i));
        }
        sort(v.rbegin(), v.rend());
        for(int i=0; i<n; i++) {
            if(i == 0) {
                ans[v[i].second] = "Gold Medal";
            }
            else if(i == 1) {
                ans[v[i].second] = "Silver Medal";
            }
            else if(i == 2) {
                ans[v[i].second] = "Bronze Medal";
            }
            else {
                ans[v[i].second] = to_string(i+1);
            }
        }
        return ans;
    }
};