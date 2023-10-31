class Solution {
public:
    int n;
    vector<int> ans;

    vector<int> findArray(vector<int>& pref) {
        n = pref.size();
        ans.resize(n);
        ans[0] = pref[0];
        for(int i=1; i<n; i++) {
            ans[i] = pref[i] ^ pref[i-1];
        }
        return ans;
    }
};