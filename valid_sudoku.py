class Solution(object):
    def isValidSudoku(self, board):
        vset = [0] * 9
        hset = [0] * 9
        bset = [0] * 9
        for i in range(9):
            for j in range(9):
                curr = board[i][j]
                if curr != '.':
                    index = 1 << (ord(curr) - ord('0'))
                    if (hset[i] & index) > 0 or\
                                    (vset[j] & index) > 0 or\
                                    (bset[(i / 3) * 3 + j / 3] & index) > 0:
                        return False
                    hset[i] |= index
                    vset[j] |= index
                    bset[(i / 3) * 3 + j / 3] |= index
        return True