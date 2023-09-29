class Solution {
public:
    int n;

    bool isMonotonic(vector<int>& nums) {
        n = nums.size();
        bool inc = false, dec = false;
        for(int i=1; i<n; i++) {
            if(nums[i]-nums[i-1] > 0) {
                inc = true;
            }
            if(nums[i]-nums[i-1] < 0) {
                dec = true;
            }
        }    
        return inc && !dec || dec && !inc || !inc && !dec;
    }
};