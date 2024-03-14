class Solution {
public:
    int n;
    int ans = 0;

    int numSubarraysWithSum(vector<int>& a, int goal) {
        n = a.size();
        unordered_map<int, int> mp;
        mp[0] = 1;
        int sum = 0;
        for(int i=0; i<n; i++) {
            sum += a[i];
            if(mp.find(sum - goal) != mp.end()) {
                ans += mp[sum - goal];
            }
            mp[sum]++;
        }
        return ans;
    }
};