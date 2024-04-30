class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int prod = 0;
        for(int n : nums) {
            prod = prod ^ n;
        }
        int ans = 0;
        while(k || prod != 0) {
            if ((k % 2) != (prod % 2)) {
                ans++;
            }            
            k /= 2;
            prod /= 2;
        }
        return ans;
    }
};