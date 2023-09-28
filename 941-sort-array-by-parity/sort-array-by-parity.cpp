class Solution {
public:
    int n;

    vector<int> sortArrayByParity(vector<int>& nums) {
        n = nums.size();
        int start = 0, end = n-1;
        vector<int> ans(n);
        for(int i=0; i<n; i++) {
            if(nums[i]%2) {
                ans[end--] = nums[i];
            }
            else {
                ans[start++] = nums[i];
            }
        }
        return ans;
    }
};