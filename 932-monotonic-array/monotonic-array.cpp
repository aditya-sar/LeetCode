class Solution {
public:
    int n;

    bool isMonotonic(vector<int>& a) {
        n = a.size();
        bool incr = false, decr = false;
        for(int i=1; i<n; i++) {
            if(a[i]-a[i-1] > 0) {
                incr = true;
            }
            if(a[i]-a[i-1] < 0) {
                decr = true;
            }
        }
        return incr && !decr || decr && !incr || !incr && !decr;
    }
};