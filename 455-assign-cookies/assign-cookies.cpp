class Solution {
public:
    int ans = 0;

    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(g.size() == 0 || s.size() == 0) {
            return 0;
        }
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int gPos = 0, sPos = 0;
        for(int i=0; i<g.size(); i++) {
            while(s[sPos] < g[i]) {
                sPos++;
                if(sPos >= s.size()) {
                    return ans;
                }
            }
            sPos++;
            ans++;
            if(sPos >= s.size()) {
                return ans;
            }
        }
        return ans;
    }
};