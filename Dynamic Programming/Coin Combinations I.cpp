#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9+7;

/*
Para este ejercicio hay que usar la misma lógica que para Dice Combinations,
la forma para llegar a una suma dp[i] es la suma de las maneras para llegar a las sumas
anteriores dp[i-c[j]].
*/

int main() {
    int n,x;
    scanf("%d%d",&n,&x);
    vector<int> c(n);
    vector<long long> dp(x+1);
    dp[0] = 1;
    for (int i=0;i<n;i++) {
        scanf("%d",&c[i]);
    }
    for (int i=1;i<=x;i++) {
        for (int j=0;j<n;j++) {
            if (i - c[j] >= 0) {
                dp[i] += dp[i-c[j]];
                dp[i] %= MOD;
            }
        }
    }
    printf("%lld\n",dp[x]);
    return 0;
}
