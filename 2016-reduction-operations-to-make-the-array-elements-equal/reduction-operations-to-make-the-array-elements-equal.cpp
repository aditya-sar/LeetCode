class Solution {
public:
    int n;
    int ans = 0;

    int reductionOperations(vector<int>& a) {
        n = a.size();
        sort(a.begin(), a.end());
        for(int i=n-1; i>0; i--) {
            if(a[i-1] != a[i]) {
                ans += n-i;
            }
        }    
        return ans;
    }
};