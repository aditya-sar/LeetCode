class Solution {
public:
    int n;
    string ans = "";

    char alpha(char c) {
        if(c >= '0' && c <= '9') {
            return c;
        }
        if(c >= 'A' && c <= 'Z') {
            return c;
        }
        return c-'a'+'A';
    }

    string licenseKeyFormatting(string s, int k) {
        n = s.size();
        vector<char> v;
        for(int i=0; i<n; i++) {
            if(s[i] != '-') {
                v.push_back(alpha(s[i]));
            }
        }    
        int nv = v.size();
        int pos = nv-1;
        int count = 0;
        while(pos >= 0) {
            count++;
            ans.push_back(v[pos--]);
            if(count == k) {
                count = 0;
                ans.push_back('-');
            }

        }
        reverse(ans.begin(), ans.end());
        if(ans[0] == '-') {
            return ans.substr(1, ans.size()-1);
        }
        return ans;
    }
};