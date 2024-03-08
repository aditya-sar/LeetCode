class Solution {
public:
    int n;

    int maxFrequencyElements(vector<int>& nums) {
        n = nums.size();
        unordered_map<int, int> mp;
        for(int &x : nums) {
            mp[x]++;
        }
        int mx = -1;
        for(pair<int, int> pr : mp) {
            mx = max(mx, pr.second);
        }
        int ans = 0;
        for(pair<int, int> pr : mp) {
            if(pr.second == mx) {
                ans += pr.second;
            }
        }
        return ans;
    }
};