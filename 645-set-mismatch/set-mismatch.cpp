class Solution {
public:
    int n;

    vector<int> findErrorNums(vector<int>& nums) {
        n = nums.size();
        unordered_map<int, int> mp;
        for(int &x : nums) {
            mp[x]++;
        }
        int twice, missing;
        for(int d=1; d<=n; d++) {
            if(mp[d] == 2) {
                twice = d;
            }
            if(mp[d] == 0) {
                missing = d;
            }
        }
        return {twice, missing};
    }
};