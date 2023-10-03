class Solution {
public:
    string ans = "";

    string convertToBase7(int num) {
        bool neg = false;
        if(num < 0) {
            neg = true;
            num *= -1;
        }
        int pos = 0;
        int number = 0;
        while(num != 0) {
            int rem = num%7;
            number = number + rem * pow(10, pos);
            pos++;
            num /= 7;
        }
        ans = to_string(number);    
        if(neg) {
            ans = "-" + ans;
        }
        return ans;
    }
};