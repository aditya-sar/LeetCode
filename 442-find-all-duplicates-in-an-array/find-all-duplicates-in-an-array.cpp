class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> ans;
        for(int &x : nums) {
            mp[x]++;
        }
        for(pair<int, int> pr : mp) {
            if(pr.second == 2) {
                ans.push_back(pr.first);
            }
        }
        return ans;
    }
};