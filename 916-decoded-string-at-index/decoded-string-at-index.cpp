class Solution {
public: 
    int n;

    bool isAlpha(char c) {
        return c >= 'a' && c <= 'z';
    }

    string decodeAtIndex(string s, int k) {
        n = s.size();
        long long size = 0;
        for(int i=0; i<n; i++) {
            if(isAlpha(s[i])) {
                size++;
            }
            else {
                size *= (s[i]-'0');
            }
        }
        for(int i=n-1; i>=0; i--) {
            if(isAlpha(s[i])) {
                if(k == 0 || k == size) {
                    string ans = "";
                    ans.push_back(s[i]);
                    return ans;
                }
                size--;
            }
            else {
                size /= (s[i]-'0');
                k %= size;
            }
        }
        return "";
    }
};