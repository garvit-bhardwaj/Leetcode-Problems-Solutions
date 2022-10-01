class Solution {
public:
    pair<int,int> palin(string &s,int x1,int x2)
    {
       
        int mx=1;
        string str;
        pair<int,int> p1={-1,-1};
        while(x1>=0&&x2<s.size())
        {
            if(s[x1]==s[x2])
            {
              
                
                p1={x1,x2};
                x1--;
                x2++;
                
            }
            else
            {
                break;
            }
        }
        return p1;
    }
    string longestPalindrome(string s) {
        int i,n=s.size();
       string mxs;
        for(i=0;i<n;i++)
        {
            pair<int,int> s1,s2;
            s1=palin(s,i,i);
            s2=palin(s,i,i+1);
           
            if(s1.first!=-1&&s1.second!=-1)
            {
               int zx=s1.second-s1.first+1;
                if(zx>mxs.size())
                    mxs=s.substr(s1.first,s1.second-s1.first+1);
            }
            if(s2.first!=-1&&s2.second!=-1)
            {
                int zx=s2.second-s2.first+1;
                if(zx>mxs.size())
                    mxs=s.substr(s2.first,s2.second-s2.first+1); 
            }
          
            
        }
        return mxs;
    }
};
