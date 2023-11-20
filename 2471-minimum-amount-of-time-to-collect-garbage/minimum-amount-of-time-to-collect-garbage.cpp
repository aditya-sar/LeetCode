class Solution {
public:
    int n, m;
    int ans = 0;

    int garbageCollection(vector<string>& garbage, vector<int>& travel) 
    {
        n = garbage.size();
        m = travel.size();
        int glassIndex = 0, paperIndex = 0, metalIndex = 0; 

        for(int i=n-1; i>=0; i--){
            string s = garbage[i];
            ans += s.size();
            if(glassIndex==0 && s.find('G') != -1) {
                glassIndex=i;
            }
            if(paperIndex==0 && s.find('P') != -1) {
                paperIndex=i;
            }
            if(metalIndex==0 && s.find('M') != -1) {
                metalIndex=i;
            }
        }

        ans += accumulate(travel.begin(), travel.begin() + glassIndex, 0)
            + accumulate(travel.begin(), travel.begin() + paperIndex, 0)
            + accumulate(travel.begin(), travel.begin() + metalIndex, 0);
        return ans;
    }
};
