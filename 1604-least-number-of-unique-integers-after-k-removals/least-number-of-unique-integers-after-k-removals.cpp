class Solution {
public:
    int n;
    int ans = 0;

    int findLeastNumOfUniqueInts(vector<int>& a, int k) {
        n = a.size();
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++) {
            mp[a[i]]++;
        }
        vector<int> v;
        for(pair<int, int> pr : mp) {
            v.push_back(pr.second);
        }
        stable_sort(v.begin(), v.end());
        for(int i=0; i<v.size(); i++) {
            if(v[i] < k) {
                k -= v[i];
                v[i] = 0;
            }
            else {
                v[i] -= k;
                k = 0;
            }
            if(v[i] != 0) {
                ans++;
            }
        }
        return ans;
    }
};