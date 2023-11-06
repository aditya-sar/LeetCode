class Solution {
public:
    int n, m;

    int findLUSlength(string a, string b) {
        n = a.size();
        m = b.size();
        return a == b ? -1 : max(n, m);
    }
};