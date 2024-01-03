class Solution {
public:
    int ans = 0;
    int n;

    int solve(string s) {
        int count = 0;
        for(int i=0; i<s.size(); i++) {
            if(s[i]=='1') {
                ++count;
            }
        }
        return count;
    }

    int numberOfBeams(vector<string>& bank) {
        n = bank.size();
        int mul = 0, count;
        for(int i=0; i<n; i++) {
            count = solve(bank[i]); 
            if(count > 0) {
                if(mul != 0) {
                    ans += mul * count; 
                    mul = count;
                }
                else {
                    mul = count; 
                }
            }
        }
        return ans;
    }
};