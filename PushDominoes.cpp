class Solution {
public:
    string pushDominoes(string s) {
        if(s.find('R') == string::npos){
            bool f = 0;
            for(int i = s.size() - 1; i >= 0; i--){
                if(s[i] == 'L') f = 1;
                if(f) s[i] = 'L';
            }
            return s;
        }else if(s.find('L') == string::npos){
            bool f = 0;
            for(int i = 0 ; i < s.size(); i++){
                if(s[i] == 'R') f = 1;
                if(f) s[i] = 'R';
            }
            return s;
        }
        
        int fisR = -1, fisL = -1, lstR, lstL;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'R'){
                if(fisR == -1) fisR = i;
                lstR = i;
            }
            
            if(s[i] == 'L'){
                if(fisL == -1) fisL = i;
                lstL = i;
            }
        }
        
        if(fisL < fisR){
            for(int i = 0; i < fisL; i++) s[i] = 'L';
        }
        
        if(lstR > lstL){
            for(int i = lstR; i < s.size(); i++) s[i] = 'R';
        }
        
        int prevseen = -1;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != '.'){
                if(prevseen == -1){ prevseen = i; continue;}
                else if(s[i] == 'R' && s[prevseen] == 'L') prevseen = i;
                else if(s[i] == s[prevseen]){
                    for(int j = prevseen + 1; j < i; j++) s[j] = s[prevseen];
                    prevseen = i;
                }
                else{
                    int l = prevseen, r = i;
                    while(l < r){
                        s[l++] = 'R';
                        s[r--] = 'L';
                    }
                    prevseen = i;
                }
            }
        }
        return s;
    }
};
