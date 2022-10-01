class Solution {
public:
    vector<vector<string>> answer;
    vector<string> tmp;
    vector<bool> row, col, dl, dr;
    int sz;
    string s;
    bool valid(int i, int j) {
        return !row[i] && !col[j] && !dl[i - j + 9] && !dr[i + j];
    }
    void rec(int i = 0) {
        if (i == sz) {
            answer.push_back(tmp);
            return;
        }
        for (int j = 0; j < sz; j++) {
            if (valid(i, j)) {
                col[j] = row[i] = dl[i - j + 9] = dr[i + j] = 1;
                s = string(sz, '.');
                // cout << "he";
                s[j] = 'Q';
                tmp.push_back(s);
                rec(i + 1);
                tmp.pop_back();
                col[j] = row[i] = dl[i - j + 9] = dr[i + j] = 0;
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        sz = n;
        row.assign(n, 0);
        col.assign(n, 0);
        dl.assign(n + 9 * 2, 0); // i + j
        dr.assign(n + 9 * 2, 0); // i - j 
        rec();
        return answer;
    }
};
