class Solution {
public:
    int n;

    bool winnerOfGame(string s) {
        n = s.size();
        int a = 0, b = 0;
        for(int i=0; i<n; i++) {
            if(i-1>=0 && i+1<n && s[i] == s[i-1] && s[i] == s[i+1]) {
                if(s[i] == 'A') {
                    a++;
                }
                else {
                    b++;
                }
            }
        }
        return a>b;
    }
};