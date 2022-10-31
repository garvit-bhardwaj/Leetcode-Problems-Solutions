class Solution {
   public:
    int calc(int n, vector<int> &s, int p) {
        // cout<<n<<" "<<p<<'\n';
        if (s[n] != -1) return s[n] ^ p;
        if (s[n - 1] == 0) {
            s[n] = 1 ^ p;
            return s[n];
        }

        int x = sqrt(n);
        for (int i = x; i >= 1; i--) {
            int a = calc(n - i * i, s, !p);
            // cout<<n-i*i<<" "<<!p<<" a="<<a<<"\n";
            if (a) {
                s[n] = 1 ^ p;
                return s[n] ^ p;
            }
        }
        s[n] = 0 ^ p;
        return s[n] ^ p;
    }

    bool winnerSquareGame(int n) {
        vector<int> v(n + 1, -1);
        v[0] = 0;
        v[1] = 1;

        // int a = calc(n, v, 0);
        int a;
        for (int i = 0; i <= n; i++) {
            a = calc(i, v, 0);
            // cout<<i<<" "<<v[i]<<"\n";
        }
        // return false;
        return v[n] ? true : false;
    }
};