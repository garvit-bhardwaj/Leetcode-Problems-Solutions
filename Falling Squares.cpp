class Solution {
    vector<double> mem;
    double P(int i, int k, int maxPts) {
        if(mem[i] != -1) {
            return mem[i];
        }
        
        mem[i] = 0;
        for(int j = 1; j <= maxPts; j++) {
            if(i - j >= 0 && i - j < k) mem[i] += P(i - j, k, maxPts) / maxPts;
        }
        
        return mem[i];
    }
    
public:
    double new21Game(int n, int k, int maxPts) {
        if(k == 0 || k + maxPts <= n) return 1;
        mem = vector<double>(n + 1, -1);
        mem[0] = 1;
        double ret = 0;
        for(int i = k; i <= n; i++) {
            ret += P(i, k, maxPts);
        }
        
        return ret;
    }
};
