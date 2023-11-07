class Solution {
public:
    int n, m;

    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        n = dist.size();
        m = speed.size();
        vector<int> reach(n);
        for(int i=0; i<n; i++) {
            reach[i] = (dist[i] - 1) / speed[i];
        }
        sort(reach.begin(), reach.end());
        for(int i=0; i<n; i++) {
            if(i > reach[i]) {
                return i;
            }
        }
        return n;
    }
};