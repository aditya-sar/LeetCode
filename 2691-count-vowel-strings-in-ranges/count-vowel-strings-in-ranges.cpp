class Solution {
public:
    // 0 1 1 2 3 4 

    vector<int> ans;

    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    vector<int> vowelStrings(vector<string>& w, vector<vector<int>>& q) {
        vector<int> prefix(w.size() + 1);
        
        for(int i=0; i<w.size(); i++) {
            char left = w[i][0];
            char right = w[i][w[i].size()-1];
            if(isVowel(left) && isVowel(right)) {
                prefix[i+1] = prefix[i] + 1;
            }
            else {
                prefix[i+1] = prefix[i];
            }
        }

        for(int i=0; i<q.size(); i++) {
            int left = q[i][0];
            int right = q[i][1];
            ans.push_back(prefix[right+1] - prefix[left]);
        }

        return ans;
        
    }
};