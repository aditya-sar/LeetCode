class Solution {
public:
    int n;

    string reverseStr(string s, int k) {
        n = s.size();
        for(int i=0; i<n; i+=2*k) {
            if(i + k > n) {
                reverse(s.begin() + i, s.end());
            }
            else {
                reverse(s.begin() + i, s.begin() + i + k);
            }
        }
        return s;
    }
};