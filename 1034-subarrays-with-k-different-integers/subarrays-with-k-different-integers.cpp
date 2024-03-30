class Solution {
public:
    int n;

    int solve(vector<int> a, int k) {
        unordered_map<int, int> mp;
        int count = 0;
        int l = 0, r = 0;
        while(r < n) {
            mp[a[r]]++;
            while(l <= r && mp.size() > k) {
                mp[a[l]]--;
                if(mp[a[l]] == 0) {
                    mp.erase(a[l]);
                }
                l++;
            }
            count += (r-l+1);
            r++;
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& a, int k) {
        n = a.size();
        return solve(a, k) - solve(a, k-1);      
    }
};