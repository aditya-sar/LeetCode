class Solution {
public:
    bool isPowerOfTwo(int n) {
        double num = 1;
        bool ans = false;
        while(true) {
            if(num == n) {
                ans = true;
                break;
            }
            if(num > n) {
                ans = false;
                break;
            }
            num *= 2;
        }
        return ans;
    }
};