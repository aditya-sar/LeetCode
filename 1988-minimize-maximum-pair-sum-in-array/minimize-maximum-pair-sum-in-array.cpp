class Solution {
public:
    int ans = -1;
    int n;

    int minPairSum(vector<int>& a) {
        n = a.size();
        sort(a.begin(), a.end());
        int left = 0, right = n-1;
        while (left < right) {
            ans = max(ans, a[left++] + a[right--]);
        }
        return ans;
    }
};