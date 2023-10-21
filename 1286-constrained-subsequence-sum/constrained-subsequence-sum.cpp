class Solution {
public:
    int n;

    int constrainedSubsetSum(vector<int>& a, int k) {
        deque<int> dq;
        n = a.size();
        for(int i=0; i<n; ++i) {
            a[i] += !dq.empty() ? a[dq.front()] : 0;
            while(!dq.empty() && (i - dq.front() >= k || a[i] >= a[dq.back()])) {
                if (a[i] >= a[dq.back()]) {
                    dq.pop_back();
                }
                else {
                    dq.pop_front();
                }
            }
            if(a[i] > 0) {
                dq.push_back(i);
            }
        }
        return *max_element(a.begin(), a.end());
    }
};