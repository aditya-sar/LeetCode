class Solution {
public:
    int n;
    long long ans = 0;
    int mod = 1e9 + 7;

    int rev(int x) {
        int ans = 0;
        while(x != 0) {
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        return ans;
    }

    int countNicePairs(vector<int>& nums) {
        n = nums.size();
        for(int i=0; i<n; i++) {
            nums[i] = nums[i] - rev(nums[i]);
        }
        unordered_map<int, int> mp;
        for(int &x : nums) {
            mp[x]++;
        }
        for(pair<int, int> pr : mp) {
            long long f = pr.second;
            ans = ans % mod + (f * (f - 1) / 2) % mod;
        }
        return ans % mod;
    }
};