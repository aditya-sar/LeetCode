class Solution {
public:
    int n;
    int mod = 1e9 + 7;

    int numberOfWays(string s) {
        int x = 1; 
        int y = 0; 
        int z = 0; 
        for(char &c : s)
            if (c == 'S') {
                x = (x + z) % mod;
                z = y;
                y = x;
                x = 0;
            }
            else {
                x = (x + z) % mod;
            }
        return z;
    }
};