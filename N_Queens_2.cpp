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
    int rec(int i = 0) {
        if (i == sz) {
            return 1;
        }
        int ans = 0;
        for (int j = 0; j < sz; j++) {
            if (valid(i, j)) {
                col[j] = row[i] = dl[i - j + 9] = dr[i + j] = 1;
                ans += rec(i + 1);
                col[j] = row[i] = dl[i - j + 9] = dr[i + j] = 0;
            }
        }
        return ans;
    }
    int totalNQueens(int n) {
        sz = n;
        row.assign(n, 0);
        col.assign(n, 0);
        dl.assign(n + 9 * 2, 0); // i + j
        dr.assign(n + 9 * 2, 0); // i - j
        return rec();
    }
};
