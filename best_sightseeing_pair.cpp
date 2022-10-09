#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int res=INT_MIN;
        for(int i=1,mini=values[0]-1;i<values.size();i++,--mini)
        {
            int cost=values[i]+mini;
            res=max(res,cost);
            mini=max(values[i],mini);
        }
        return res;
    }
};