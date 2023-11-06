class Solution {
public:
    int n;

    bool checkRecord(string s) {
        n = s.size();
        int absent = 0, late = 0;
        for(int i=0; i<n; i++) {
            if(s[i] == 'A' || s[i] == 'P') {
                late = 0;
                if(s[i] == 'A') {
                    absent++;
                }
            }
            else if(s[i] == 'L') {
                late++;
            }
            if(late >= 3 || absent >= 2) {
                return false;
            }
        }
        return true;
    }
};