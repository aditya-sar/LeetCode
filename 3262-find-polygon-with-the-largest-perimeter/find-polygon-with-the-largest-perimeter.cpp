class Solution {
public:
    int n;
    using ll = long long;
    ll ans = 0;
    ll sum = 0;

    long long largestPerimeter(vector<int>& nums) {
        n = nums.size();
        stable_sort(nums.begin(), nums.end());
        sum = nums[0] + nums[1];
        for(int i=2; i<n; i++) {
            if(nums[i] < sum) {
                ans = sum + nums[i];
            }
            sum += nums[i];
        }        
        return ans == 0 ? -1 : ans;
    }
};