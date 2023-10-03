class Solution {
public:
    int n;

    int numIdenticalPairs(vector<int>& a) {
        n = a.size();
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++) {
            mp[a[i]]++;
        }    
        int ans = 0;
        for(pair<int, int> pr : mp) {
            ans += (pr.second)*(pr.second-1)/2;
        }
        return ans;
    }
};