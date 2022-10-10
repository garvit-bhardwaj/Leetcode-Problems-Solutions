class Solution {
    public boolean isNumber(String s) {
        boolean num = false, exp = false, dot = false;
        for(int i=0;i<s.length();i++) {
            char ch = s.charAt(i);
            if(Character.isDigit(ch)) num = true;
            else if(ch=='e'|| ch=='E') {
                if(exp || !num) return false;
                exp = true;
                num = false;
            }
            else if(ch=='.') {
                if(dot|| exp) return false;
                dot = true;
            }
            else if(ch=='+' || ch=='-') {
                if(i!=0 && s.charAt(i-1)!='e' && s.charAt(i-1)!='E') return false;
            }
            else return false;
        }
        return num;
    }
}
