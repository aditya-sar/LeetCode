class Solution {
public:
    int n;
    long long ans = 0;

    long long maximumTripletValue(vector<int>& a) {
        n = a.size();    
        for(int i=0; i<n-2; i++) {
            for(int j=i+1; j<n-1; j++) {
                if(a[j] > a[i]) {
                    continue;
                }
                int mx = INT_MIN;
                for(int k=j+1; k<n; k++) {
                    if(a[k] > mx) {
                        mx = a[k];
                    }
                }
                ans = max(ans, static_cast<long long>(a[i] - a[j]) * mx);
            }
        }
        return ans;
    }
};