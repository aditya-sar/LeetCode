class Solution {
public:
    int n;
    vector<int> ans;

    vector<int> sortByBits(vector<int>& a) {
        n = a.size();
        vector<pair<int, int>> v;
        for(int i=0; i<n; i++) {
            v.push_back({__builtin_popcount(a[i]), a[i]});
        }    
        sort(v.begin(), v.end());
        for(int i=0; i<n; i++) {
            ans.push_back(v[i].second);
        }    
        return ans;
    }
};





