class Solution {
public:
    int n;
    int ans = 0;

    int bagOfTokensScore(vector<int>& tokens, int power) {
        n = tokens.size();
        stable_sort(tokens.begin(), tokens.end());
        int score = 0;
        int left = 0, right = n-1;
        while(left <= right) {
            if(power >= tokens[left]) {
                power -= tokens[left];
                score++;
                left++;
                ans = max(ans, score);
            }
            else if(score > 0) {
                power += tokens[right];
                right--;
                score--;
            }
            else break;
        }    
        return ans;
    }
};