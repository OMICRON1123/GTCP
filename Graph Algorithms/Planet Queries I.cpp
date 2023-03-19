#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,q;
    scanf("%d%d",&n,&q);
    vector<vector<int>> t(1,vector<int>(n+1));
    for (int i=1;i<=n;i++) {
        scanf("%d",&t[0][i]);
    }
    for (int i=1;(1<<i)<=1e9;i++) {
        t.push_back(vector<int>(n+1));
        for (int j=1;j<=n;j++) {
            t[i][j] = t[i-1][t[i-1][j]];
        }
    }
    while (q--) {
        int x,k;
        scanf("%d%d",&x,&k);
        for (int i=0;(1<<i) <= 1e9;i++) {
            if ((1<<i)&k) {
                x = t[i][x];
            }
        }
        printf("%d\n",x);
    }
    return 0;
}
