class Solution {
public:
    int n;
    unordered_map<int, int> mp;

    int dfs(vector<int> &nums, int pos) {
        if(pos >= n) {
            return 0;
        }
        if(mp.find(pos) != mp.end()) {
            return mp[pos];
        }
        int take = nums[pos] + dfs(nums, pos+2);
        int skip = dfs(nums, pos+1);
        return mp[pos] = max(take, skip);
    }

    int rob(vector<int>& nums) {
        n = nums.size();
        return max(dfs(nums, 0), dfs(nums, 1));
    }
};