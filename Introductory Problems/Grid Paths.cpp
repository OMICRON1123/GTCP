#include <bits/stdc++.h>
using namespace std;

vector<vector<bool> > grid = {{1,1,1,1,1,1,1,1,1},
                              {1,0,0,0,0,0,0,0,1},
                              {1,0,0,0,0,0,0,0,1},
                              {1,0,0,0,0,0,0,0,1},
                              {1,0,0,0,0,0,0,0,1},
                              {1,0,0,0,0,0,0,0,1},
                              {1,0,0,0,0,0,0,0,1},
                              {1,0,0,0,0,0,0,0,1},
                              {1,1,1,1,1,1,1,1,1}};
string s;
int res;

void solve(int y, int x,int n) {
    if (y == 7 && x == 1 && n != 48)
        return;
    if (y == 7 && x == 1) {
        res++;
        return;
    }
    if (n >= 48)
        return;

    if (grid[y][x-1] && grid[y][x+1] && !grid[y+1][x] && !grid[y-1][x]) {
        return;
    }
    if (grid[y+1][x] && grid[y-1][x] && !grid[y][x+1] && !grid[y][x-1]){
        return;
    }
    grid[y][x] = 1;
    if (s[n] == '?') {
        if (!grid[y-1][x]){
            solve(y-1,x,n+1);
        }
        if (!grid[y+1][x]){
            solve(y+1,x,n+1);
        }
        if (!grid[y][x-1]){
            solve(y,x-1,n+1);
        }
        if (!grid[y][x+1]) {
            solve(y,x+1,n+1);
        }
    }
    else if (s[n] == 'D' && !grid[y+1][x]) {
        solve(y+1,x,n+1);
    }
    else if (s[n] == 'U' && !grid[y-1][x]) {
        solve(y-1,x,n+1);
    }
    else if (s[n] == 'L' && !grid[y][x-1]){
        solve(y,x-1,n+1);
    }
    else if (s[n] == 'R' && !grid[y][x+1]){
        solve(y,x+1,n+1);
    }
    grid[y][x] = 0;
}

int main() {
    cin>>s;
    solve(1,1,0);
    printf("%d",res);
    return 0;
}
