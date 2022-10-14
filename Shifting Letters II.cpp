class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size(),sum=0;
        vector <int> v(n+1,0);
        
        for(int i=0;i<shifts.size();i++){
            int l=shifts[i][0];
            int r=shifts[i][1];
            if(shifts[i][2]==0){
                v[l]--;
                v[r+1]++;
            }
            else{
                v[l]++;
                v[r+1]--;
            }
        }
    
        for(int i=0;i<n;i++){
            sum+=v[i];
            int k=sum%26;
            int p=(s[i]-'a'+k+26)%26;
            s[i]=char('a'+p);
        }
        return s;
    }
};
