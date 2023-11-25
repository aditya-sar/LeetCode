class Solution {
public:
    int n;
    vector<int> ans;

    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        n = nums.size();
        vector<int> prefix(n), suffix(n);
        prefix[0] = nums[0];
        suffix[n-1] = nums[n-1];
        for(int i=1; i<n; i++) {
            prefix[i] = prefix[i-1] + nums[i];
            suffix[n-1-i] = suffix[n-i] + nums[n-1-i];
        }
        for(int i=0; i<n; i++) {
            int absolute = nums[i] * i;
            int relative = nums[i] * (n - 1 - i);
            ans.push_back(absolute - prefix[i] + suffix[i] - relative);
        }
        return ans;
    }
};