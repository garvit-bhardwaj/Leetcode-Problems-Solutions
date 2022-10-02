# [Number of Flowers in Full Bloom](https://leetcode.com/contest/weekly-contest-290/problems/number-of-flowers-in-full-bloom/)

## Solution

```C++

#pragma GCC optimize("Ofast")
#define all(vec) vec.begin(), vec.end()
#define sz(x) int(x.size())

static auto _ = [] () {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    return 0;
};

class Solution {
public:
    
    int get_idx(int idx, vector < int >& vec){
        return lower_bound(all(vec), idx) - vec.begin();
    }
    
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons){
        
        constexpr int N = 4e5;
        
        vector < int > vec;
        
        for(auto& v : flowers)
            vec.push_back(v[0]), vec.push_back(v[1]);
        
        for(auto& p : persons)
            vec.push_back(p);
        
        sort(all(vec));
        vec.resize(unique(all(vec)) - vec.begin());
        
        vector < int > part(N + 100);
        for(auto& v : flowers)
            part[get_idx(v[0], vec)]++, part[get_idx(v[1], vec) + 1]--;
        
        for(int i = 1; i <= N; i++)
            part[i] += part[i - 1];
        
        vector < int > ans(sz(persons));
        for(int i = 0; i < sz(persons); i++)
            ans[i] = part[get_idx(persons[i], vec)];
        
        return ans;
    }
};
```

### Complexity

- Time Complexity: `O(n log(n))`
- Space Complexity: `O(n log(n))`
