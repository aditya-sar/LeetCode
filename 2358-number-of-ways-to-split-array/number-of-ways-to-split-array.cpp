
class Solution {
public:
    int ans = 0;

    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        long long left = 0;

        for(int i=0; i<n-1; i++) {
            left += nums[i];
            if(left >= total - left) {
                ans++;
            }
        }

        return ans;
    }

};


/*

6 -1 9 
6  5 14

10 4 -8 7
10 14 6 13

*/

