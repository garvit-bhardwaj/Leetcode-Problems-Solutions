# [Bitwise XOR of All Pairings](https://leetcode.com/contest/biweekly-contest-88/problems/bitwise-xor-of-all-pairings/)

## Solution

```C++
class Solution {
public:
    
    // xor of the vector
    int get_xor(vector < int >& vec){
        int xr = 0;
        for(auto& x : vec)
            xr ^= x;
        return xr;
    }
    
    int xorAllNums(vector < int >& a, vector < int >& b) {

        int xor_a = get_xor(a), xor_b = get_xor(b);
        int n_a = a.size(), n_b = b.size(), xr = 0;

        if(n_a & 1)
            xr ^= xor_b;
        
        if(n_b & 1)
            xr ^= xor_a;
        
        return xr;
    }
};
```

### Explanation

- If the size of vector `b` is odd, then the xor of `a` will used odd times, each to times will cancel out, so the xor will be `a` otherwise will be `0`.
- If the size of vector `a` is odd, then the xor of `b` will used odd times, each to times will cancel out, so the xor will be `b` otherwise will be `0`.
- The xor of all pairs will be the xor of the two xors.

### Complexity

- Time Complexity: `O(n)`
- Space Complexity: `O(1)`
