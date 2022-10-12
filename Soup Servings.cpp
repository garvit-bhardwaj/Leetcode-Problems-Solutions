class Solution {
private:
     double step(int A, int B, unordered_map<int, unordered_map<int, double>> &memo){
        if(A <= 0) return B <= 0 ? 0.5 : 1.0;
        if(B <= 0) return 0.0;

        if(memo.find(A) != memo.end() && memo.at(A).find(B) != memo.at(A).end())
            return memo.at(A).at(B);


        double val = step(A - 100, B, memo);
        val += step(A - 75, B - 25, memo);
        val += step(A - 50, B - 50, memo);
        val += step(A - 25, B - 75, memo);

        return memo[A][B] = 0.25 * val;
    }   
    
public:
    double soupServings(int n){
        if(n > 4750) return 1;

        unordered_map<int, unordered_map<int, double>> memo;
        return step(n, n, memo);
    }
};
