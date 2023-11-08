class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx == fx && sy == fy) {
            return t != 1;
        }
        int mn = min(abs(sx - fx), abs(sy - fy)) + 1;
        int mx = max(abs(sx - fx), abs(sy - fy)) + 1;
        return mn - 1 + (mx - mn) <= t;
    }
};