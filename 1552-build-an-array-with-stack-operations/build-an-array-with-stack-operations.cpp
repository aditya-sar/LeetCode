class Solution {
public:
    vector<string> ans;

    vector<string> buildArray(vector<int>& target, int n) {
        string push = "Push";
        string pop = "Pop";
        int pos = 0;
        for(int i=1; i<=n; i++) {
            if(pos >= target.size()) {
                break;
            }
            if(target[pos] == i) {
                ans.push_back(push);
                pos++;
            }
            else {
                ans.push_back(push);
                ans.push_back(pop);
            }
        }
        return ans;
    }
};