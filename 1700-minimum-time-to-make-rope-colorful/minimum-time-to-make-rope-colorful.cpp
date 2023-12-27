class Solution {
public:
    int n;
    int ans = 0;

    int minCost(string s, vector<int>& a) {
        n = s.size();
        int left = 0;
        for(int i=1; i<n; i++){
            if(s[left] != s[i]){
                left = i;
            }
            else { 
                if(a[left] < a[i]) {
                    ans += a[left];
                    left=i;
                }
                else {
                    ans += a[i];
                }
            }
        }
        return ans;
    }
};