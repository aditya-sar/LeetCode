class Solution {
public:
    int ans = 0;
    int minimumOneBitOperations(int n) {
        while(n > 0) {
            ans = -(ans + (n ^ (n - 1)));
            n &= (n - 1);
        }
        return abs(ans);
    }
};