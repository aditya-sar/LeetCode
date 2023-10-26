
class Solution {
public:
	const int MOD = 1e9 + 7;
	int n;

    int numFactoredBinaryTrees(vector<int>& a) {
    	n = a.size();
        sort(a.begin(), a.end());
        unordered_set<int> s(a.begin(), a.end());
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++) {
        	mp[a[i]] = 1;
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if (a[j] > sqrt(a[i])) {
                	break;
                }
                if(a[i] % a[j] == 0 && s.find(a[i] / a[j]) != s.end()) {
                    long long temp = (long long)mp[a[j]] * mp[a[i] / a[j]];
                    if (a[i] / a[j] == a[j]) {
                        mp[a[i]] = (mp[a[i]] + temp) % MOD;
                    } 
                    else {
                        mp[a[i]] = (mp[a[i]] + temp * 2) % MOD;
                    }
                }
            }
        }
        int ans = 0;
        for (auto pr : mp) {
            ans = (ans + pr.second) % MOD;
        }
        return ans;
    }
};