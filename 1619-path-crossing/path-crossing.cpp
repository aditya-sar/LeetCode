class Solution {
public:
    bool n;
    unordered_map<string, bool> mp;


    bool isPathCrossing(string path) {
        n = path.size();
        int x = 0, y = 0;
        mp["0,0"] = true;
        for(char c : path) {
            if(c == 'N') {
                y++;
            }
            else if(c == 'S') {
                y--;
            }
            else if(c == 'W') {
                x--;
            }
            else {
                x++;
            }
            if(mp.find(to_string(x) + ',' + to_string(y)) != mp.end()) {
                return true;
            }
            mp[to_string(x) + ',' + to_string(y)] = true;
        }
        return false;
    }
};