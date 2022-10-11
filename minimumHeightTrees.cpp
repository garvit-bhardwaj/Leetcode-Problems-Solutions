#include<bits/stdc++.h>
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        
        
        vector<int>g[edges.size()+1];
        vector<int>indegree(n,0);
        vector<int>ans;
        for(int  i=0 ;i<edges.size();i++){
            
            g[edges[i][0]].push_back(edges[i][1]);
            
                g[edges[i][1]].push_back(edges[i][0]);
               
               indegree[edges[i][0]]++;
                   indegree[edges[i][1]]++;
        
        }
        
        queue<int>q;
        
        for(int i=0;i<n;i++){
            
            if(indegree[i]==1)
                q.push(i);
        }
        while(!q.empty()){
            
            int a=q.size();
            ans.clear(); //agr queue kahili nhi hui to pichla wla ans mera ans nhi hoga
            for(int i=0;i<a;i++){
                
                auto x= q.front();
                q.pop();
                ans.push_back(x);
                
                for(auto y : g[x]){
                    
                    indegree[y]--;
                    if(indegree[y]==1)q.push(y);
                }
            }
        }
        
        if(n==1) return {0};
        return ans;
        
    }
};