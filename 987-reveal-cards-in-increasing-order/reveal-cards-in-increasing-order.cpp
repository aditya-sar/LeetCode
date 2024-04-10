class Solution {
public:
    vector<int> ans;
    int n;

    vector<int> deckRevealedIncreasing(vector<int>& a) {
        n = a.size();
        queue<int> q;
        sort(a.begin(),a.end()); 
        for(int i=n-1; i>=0; i--){
            if(!q.empty()){ 
                q.push(q.front()); 
                q.pop(); 
            }
            q.push(a[i]); 
        }
        for(int i = a.size()-1; i>=0; i--){
            a[i] = q.front(); 
            q.pop();
        }
        return a;
    }
};