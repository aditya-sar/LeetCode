class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0) {
            return {1};
        }
        vector<int> start = {1, 1};
        for(int i=0; i<rowIndex - 1; i++) {
            vector<int> cal;
            cal.push_back(1);
            for(int i=0; i<start.size()-1; i++) {
                cal.push_back(start[i] + start[i+1]);
            }
            cal.push_back(1);
            start = cal;
        }
        return start;
    }
};