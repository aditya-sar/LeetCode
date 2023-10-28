class Solution {
public:
	int MOD = 1e9 + 7;
	
    int countVowelPermutation(int n) {
        long a = 1, e = 1, i = 1, o = 1, u = 1;
        for (int length = 1; length < n; length++) {
            long nextA = e;
            long nextE = (a + i) % MOD;
            long nextI = (a + e + o + u) % MOD;
            long nextO = (i + u) % MOD;
            long nextU = a;
            a = nextA;
            e = nextE;
            i = nextI;
            o = nextO;
            u = nextU;
        }
        return (a + e + i + o + u) % MOD;

    }
};