class Solution {
public:
    int ans = 0;
    int n;

    int findLengthOfLCIS(vector<int>& nums) {
        n = nums.size();
        if(n == 1) {
            return 1;
        }
        int left = 0, right = 1;
        int count = 1;
        while(right < n) {
            if(nums[right] > nums[right-1]) {
                count++;
            }
            else {
                ans = max(ans, right - left);
                left = right;
            }
            right++;
        }
        ans = max(ans, right - left);
        return ans;
    }
};