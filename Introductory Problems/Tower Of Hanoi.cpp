#include <bits/stdc++.h>
using namespace std;

void solve(int tower1,int tower2, int tower3, int n) {
    if (n == 1) {
        printf("%d %d\n",tower1,tower3);
        return;
    }
    solve(tower1,tower3,tower2,n-1);
    printf("%d %d\n",tower1,tower3);
    solve(tower2,tower1,tower3,n-1);
}

int main() {
    int n;
    scanf("%d",&n);
    printf("%d\n",(1<<n)-1);
    solve(1,2,3,n);
}
