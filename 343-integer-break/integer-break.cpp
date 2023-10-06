class Solution {
public:
    int integerBreak(int n) {
        if(n <= 3) {
            return n-1;
        }
        int quo = n/3, rem = n%3;
        if(rem == 0) {
            return pow(3, quo);
        }
        if(rem == 1) {
            return pow(3, quo-1) * 4;
        }
        return pow(3, quo) * 2;
    }
};