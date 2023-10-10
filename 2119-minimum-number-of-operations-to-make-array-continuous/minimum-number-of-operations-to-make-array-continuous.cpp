class Solution {
public:
    int n;
    int minOperations(vector<int>& a) {
        sort(a.begin(), a.end());
        n = a.size();
        int l = 0; 
        int mx = 1; 
        int count = 1; 
        for(int r=1; r<n; ++r) {
            if (a[r] == a[r-1]) {
                continue; 
            }
            while(a[r] - a[l] > n - 1) {
                if(l < n && a[l+1] == a[l]){
                    count++;
                }
                l++;
                count--;
            }
            count++;
            mx = max(mx, count);
        }
        return n - mx;
    }
};