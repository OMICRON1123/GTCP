#include <bits/stdc++.h>
using namespace std;

/*
Para este ejercicio se toma la forma recursiva en la manera de llegar a una suma.
La manera de llegar a una suma dp[i] es la forma de llegar a las sumas dp[i-c[j]]
con una moneda más, se toma la menor de estas maneras.
*/

int main() {
    int n,x;
    scanf("%d%d",&n,&x);
    vector<int> c(n);
    for (int i=0;i<n;i++) {
        scanf("%d",&c[i]);
    }
    vector<long long> dp(x+1,1e18);
    dp[0] = 0;
    for (int i=1;i<=x;i++) {
        for (int j=0;j<n;j++) {
            if (i-c[j] >= 0) {
                dp[i] = dp[i] < dp[i-c[j]]+1 ? dp[i] : dp[i-c[j]]+1;
            }
        }
    }
    if (dp[x] == 1e18) {
        printf("-1\n");
    }
    else {
        printf("%lld\n",dp[x]);
    }
    return 0;
}
