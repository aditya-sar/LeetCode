class Solution {
public:
    int n;

    int findLHS(vector<int>& a) {
        n = a.size();   
        sort(a.begin(), a.end());
        int left = 0, right = 1;
        int ans = 0;
        while(right < n) {
            if(a[right] - a[left] == 1) {
                ans = max(right - left + 1, ans);
            }
            else if(a[right] - a[left] > 1) {
                while(a[right] - a[left] > 1) {
                    left++;
                }
            }
            right++;
        }
        return ans;
    }
};