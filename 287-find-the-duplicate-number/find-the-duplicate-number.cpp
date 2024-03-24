class Solution {
public:
    int n;

    int findDuplicate(vector<int>& nums) {
        n = nums.size();
        int slow = nums[0], fast = nums[0];
        while(true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast) {
                break;
            }
        }
        fast = nums[0];
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};