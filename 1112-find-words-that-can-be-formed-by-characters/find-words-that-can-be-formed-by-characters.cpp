class Solution {
public:
    int n, m;
    int ans = 0;

    int countCharacters(vector<string>& words, string chars) {
        n = words.size();
        m = chars.size();
        unordered_map<char, int> mp;
        for(char &c : chars) {
            mp[c]++;
        }
        for(string &w : words) {
            unordered_map<char, int> newMap = mp;
            int count = 0;
            for(char &c : w) {
                if(newMap[c] == 0) {
                    count = 0;
                    break;
                }
                count++;
                newMap[c]--;
            }
            ans += count;
        }
        return ans;
    }
};