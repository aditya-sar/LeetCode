class Solution {
public:
    int n;
    int ans = 1;

    int findMinArrowShots(vector<vector<int>>& a) {
        n = a.size();
        sort(a.begin(), a.end());
        int curr = a[0][1];
        for(int i=1; i<n; i++){
            if(a[i][0] > curr){
                curr = a[i][1];
                ans++;
            }
            else {
                curr = min(curr,a[i][1]);
            }
        }
        return ans;
    }
};