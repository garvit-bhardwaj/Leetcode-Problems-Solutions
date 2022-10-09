# 2337. Move Pieces to Obtain a String
class Solution:
    def canChange(self, start: str, target: str) -> bool:
        s = [(ch, i) for i, ch in enumerate(start) if ch != '_']
        e = [(ch, i) for i, ch in enumerate(target) if ch != '_']
        
        if len(s) != len(e):
            return False
        
        
        for i in range(len(s)):
            sChar, sIdx = s[i]
            eChar, eIdx = e[i]
            
            if sChar != eChar:
                return False
            
            if sChar == 'L' and sIdx < eIdx:
                return False
            
            if sChar == 'R' and sIdx > eIdx:
                return False
            
        
        
        return True
