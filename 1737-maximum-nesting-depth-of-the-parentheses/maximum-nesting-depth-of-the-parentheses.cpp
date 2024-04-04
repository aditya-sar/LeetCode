class Solution {
public:
    int n;
    int ans = 0;

    int maxDepth(string s) {
        n = s.size();
        int count = 0;
        for(int i=0; i<n; i++) {
            if(s[i] == '(') {
                count++;
            }
            else if(s[i] == ')') {
                count--;
            }
            ans = max(ans, count);
        }    
        return ans;
    }
};