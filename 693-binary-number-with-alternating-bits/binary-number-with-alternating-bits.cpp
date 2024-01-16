class Solution {
public:
    bool hasAlternatingBits(int n) {
        string s = "";
        while(n > 0) {
            s.push_back(n%2);
            n /= 2;
        }
        for(int i=1; i<s.size(); i++) {
            if(s[i] == s[i-1]) {
                return false;
            }
        }
        return true;
    }
};