import java.util.*;
import java.lang.*; 

class Solution {
    public boolean isHappy(int n) 
    {   int s=0;
        for(int i=n;i>0;i=i/10)
        {
            int d=i%10;
            s=s+d*d;
        }
        
       if(s>1 && s!=4)
         return isHappy(s);
       else if(s==1)
            return true;
       else 
            return false;
       
         
        }
        
        
    }
