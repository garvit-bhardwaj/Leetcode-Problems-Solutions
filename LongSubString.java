class Solution {
    public int lengthOfLongestSubstring(String s) {
           /*  int len = s.length() ;
            if(len == 0) return 0 ;
            char ch = s.charAt(0);
            String ans = " ";
            ans = ans + ch ;
            int max = 1 ;
            
            for(int i = 0 ; i <len ; i++){
                    ch=s.charAt(i);
            int index=ans.indexOf(ch);
            if(index == -1){
                ans=ans+ch;
                max=Math.max(max,ans.length());
            }
            else{
                ans=ans.substring(index+1)+ch;     
            }
            }
            return  max ;
            */
            
            
          //using hashmap
            
           Map<Character, Integer>  map = new HashMap<>() ;
            int i = 0 ;
            int j = 0 ;
            int max = 0 ;
            while(j < s.length()){
            map.put(s.charAt(j), map.getOrDefault(s.charAt(j), 0) + 1);
            if(map.size() == j - i + 1){
                max = Math.max(max, j - i + 1);
                j++;
            }
            else if(map.size() < j - i + 1){
                while(map.size() < j - i + 1){
                    map.put(s.charAt(i), map.get(s.charAt(i)) - 1);
                    if(map.get(s.charAt(i)) == 0) map.remove(s.charAt(i));
                    i++;
                }
                j++;
            }
        }
        return max;
            
                      
            
        
    }
}
