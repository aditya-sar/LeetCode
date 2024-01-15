class Solution {
public:
    int n;
    bool ans = false;

    bool isPalindrome(string s) {
        int l = 0, r = s.size()-1;
        while(l <= r) {
            if(s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        n = s.size();
        int l = 0, r = n-1;
        bool ok = false;
        while(l <= r) {
            if(s[l] != s[r]) {
                string s1 = s, s2 = s;
                s1.erase(s1.begin() + l);
                s2.erase(s2.begin() + r);
                ok = isPalindrome(s1) || isPalindrome(s2);
                break;
            }
            l++;
            r--;
        }
        return ok == true ? true : isPalindrome(s);
    }
};











