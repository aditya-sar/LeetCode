class Solution {
public:
    int n;

    int getWinner(vector<int>& a, int k) {
        n = a.size();
        int mx = *max_element(a.begin(), a.end());
        if(k == 1) {
            return max(a[0], a[1]);
        }
        if(k >= n) {
            return mx;
        }
        int winner = a[0];
        int f = 0;
        for(int i=1; i<n; i++) {
            if(winner > a[i]) {
                f++;
            }
            else {
                f = 1;
                winner = a[i];
            }
            if(winner == mx || f == k) {
                return winner;
            }
        }
        return winner;
    }
};