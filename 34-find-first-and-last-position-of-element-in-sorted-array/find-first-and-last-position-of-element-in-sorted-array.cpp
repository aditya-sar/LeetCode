class Solution {
public:
    int n;

    vector<int> searchRange(vector<int>& a, int k) {
        n = a.size();    
        int low = 0, high = n-1;
        while(low <= high) {
            int mid = low + (high-low)/2;
            if(a[mid] == k) {
                int left = mid, right = mid;
                while(left > 0 && a[left-1] == k) {
                    left--;
                }
                while(right < n-1 && a[right+1] == k) {
                    right++;
                }
                return {left, right};
            }
            else if(a[mid] < k) {
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        return {-1, -1};
    }
};