class Solution {
public:
    int n;
    double ans = INT_MIN;

    double findMaxAverage(vector<int>& nums, int k) {
        n = nums.size();
        double sum = 0;
        for(int i=0; i<k; i++) {
            sum += nums[i];
        }
        double initial = sum / k;
        for(int i=k; i<n; i++) {
            sum -= nums[i-k];
            sum += nums[i];
            double avg = sum / k;
            ans = max(ans, avg);
        }
        return max(ans, initial);
    }
};