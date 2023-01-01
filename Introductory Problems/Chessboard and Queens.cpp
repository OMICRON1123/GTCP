#include <bits/stdc++.h>
using namespace std;

long long res = 0;
vector<bool> col(8),diag1(15),diag2(15);
vector<vector<bool> > board;

void solve(int row) {
    if (row == 8) {
        res++;
        return;
    }
    for (int i=0;i<8;i++) {
        if (!col[i] && !diag1[i+row] && !diag2[i-row+7] && !board[row][i]) {
            col[i] = 1;
            diag1[i+row] = 1;
            diag2[i-row+7] = 1;
            solve(row+1);
            col[i] = 0;
            diag1[i+row] = 0;
            diag2[i-row+7] = 0;
        }
    }
}

int main() {
    string s;
    for (int i=0;i<8;i++) {
        cin>>s;
        vector<bool> nv;
        for (int j=0;j<8;j++) {
            if (s[j] == '.') {
                nv.push_back(0);
            }
            else {
                nv.push_back(1);
            }
        }
        board.push_back(nv);
    }
    solve(0);
    printf("%lld\n",res);
    return 0;
}
