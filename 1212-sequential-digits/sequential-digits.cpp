class Solution {
public:
    vector<int> ans;
    
    vector<int> sequentialDigits(int low, int high) {
        for(int i=1; i<=9; i++) {
            int number = i, units = i+1;
            while(number <= high && units <= 9) {
                number = (number * 10) + units;
                if(number >= low && number <= high) {
                    ans.push_back(number);
                }
                units++;
            }
        }
        stable_sort(ans.begin(), ans.end());
        return ans;
    }
};