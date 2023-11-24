class Solution {
public:
    int n;
    int ans = 0;

    int maxCoins(vector<int>& a) {
        n = a.size();
        stable_sort(a.begin(), a.end());
        for(int i=n/3; i<n; i+=2) {
            ans += a[i];
        }
        return ans;
    }
};


/*
    1 2 2 4 7 8 10 12 14 
      2 2 4 7 8 10
        2 4 7


    1 2 2 4 7 8 


*/