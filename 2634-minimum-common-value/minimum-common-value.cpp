class Solution {
public:
    int n, m;

    int getCommon(vector<int>& a, vector<int>& b) {
        n = a.size();
        m = b.size();
        int i=0, j=0;
        while(i < n && j < m) {
            if(a[i] == b[j]) {
                return a[i];
            }
            if(a[i] > b[j]) {
                j++;
            }
            else {
                i++;
            }
        }
        return -1;
    }
};