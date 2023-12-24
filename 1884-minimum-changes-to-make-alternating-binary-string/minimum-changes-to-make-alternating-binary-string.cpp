class Solution {
public:
    int n;

    int minOperations(string s) {
        n = s.size();
        int zero = 0, one = 0;
        for(int i=0; i<n; i++) {
            i % 2 == 0 ? s[i] == '0' ? one++ : zero++ : s[i] == '1' ? one++ : zero++;
        }    
        return min(one, zero);
    }
};