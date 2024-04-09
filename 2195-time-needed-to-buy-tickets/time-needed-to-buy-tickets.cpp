class Solution {
public:
    int n;
    int ans = 0;

    int timeRequiredToBuy(vector<int>& a, int k) {
        n = a.size();
        bool done = false;
        while(true) {
            for(int i=0; i<n; i++) {
                if(a[i] == 0) {
                    continue;
                }
                a[i]--;
                ans++;
                if(a[i] == 0 && i == k) {
                    done = true;
                    break;
                }
            }
            if(done) {
                break;
            }
        }
        return ans;
    }
};