class Solution {
public boolean isMatch(String s, String p) {
    return helper(0,0,s,p,new Boolean[s.length()][p.length()]);
}
public boolean helper(int index1,int index2, String s, String p, Boolean[][] dp) {
    if(index1>=s.length()|| index2>= p.length()) {
        if(index1>=s.length()&& index2>= p.length())
            return true;
        else  if(index2+1<p.length() && p.charAt(index2+1)=='*')  {
        	return helper(index1, index2+2, s, p, dp);
        }
        
            return false;
        
    }
    if(dp[index1][index2] != null)
        return dp[index1][index2];
    
    if(index2+1<p.length() && p.charAt(index2+1)=='*')
    {
    	if(p.charAt(index2) == '.')
        {
            return  dp[index1][index2] = helper(index1+1,index2,s,p,dp) || helper(index1,index2+2,s,p,dp);
        }
    	else {
    		if(s.charAt(index1) == p.charAt(index2))    {
               return dp[index1][index2] =helper(index1+1,index2,s,p,dp) || helper(index1,index2+2,s,p,dp); 
            }
    		else {
    			return dp[index1][index2]=helper(index1,index2+2,s,p,dp);
    		}
    			
    	}
    }
    else {
    	 if(s.charAt(index1) == p.charAt(index2))  {
            return dp[index1][index2] =helper(index1+1,index2+1,s,p,dp); 
         }
         else if(p.charAt(index2) == '.')  {
             return  dp[index1][index2] = helper(index1+1,index2+1,s,p,dp);
         }
    }
    
    return false;
}
}
