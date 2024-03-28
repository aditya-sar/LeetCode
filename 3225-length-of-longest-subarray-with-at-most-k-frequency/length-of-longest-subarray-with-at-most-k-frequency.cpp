class Solution {
public:
    int n;
    int ans = 0;

    int maxSubarrayLength(vector<int>& nums, int k) {
        n = nums.size();
        unordered_map<int, int> mp;
        int l = 0, r = 0;
        while(r < n) {
            int num = nums[r++];
            mp[num]++;
            while(l < r && mp[num] > k) {
                mp[nums[l++]]--;
            }
            ans = max(ans, r - l);
        }
        return ans;
    }
};