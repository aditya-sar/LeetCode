class Solution {
public:
    int ans = 0;

    int totalMoney(int n) {
        int previous = 0;
        int base = 1;
        for(int i=0; i<n; i++) {
            if(i%7 == 0) {
                base = previous + 1;
                previous = base;
            }
            ans += base;
            base++;
        }
        return ans;
    }
};