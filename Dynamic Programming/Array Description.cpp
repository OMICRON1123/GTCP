#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9+7;

/*
En este caso dp[i][j] representa cuántos arreglos se pueden conseguir llegando hasta
la posición i del arreglo original y que terminan en j. Si x[i] es diferente a 0. El
último arreglo deberá terminar en x[i] y por ende dp[i][j] = 0 para j != x[i] y
dp[i][x[i]] = dp[i-1][x[i]-1]+dp[i-1][x[i]]+dp[i-1][x[i]+1] por otro lado,
si x[i] = 0 entonces para todo j se cumple que dp[i][j] = dp[i-1][j-1]+dp[i-1][j]+dp[i-1][j+1].
*/

int main() {
    bool aux = 0;
    int n,m;
    long long sum = 0;
    scanf("%d%d",&n,&m);
    vector<int> x(n);
    vector<long long> dp1(m+2),dp2(m+2);
    for (int i=0;i<n;i++) {
        scanf("%d",&x[i]);
    }
    if (x[0]) {
        dp1[x[0]] = 1;
    }
    else {
        for (int i=1;i<=m;i++) {
            dp1[i] = 1;
        }
    }
    for (int i=1;i<n;i++) {
        if (!aux) {
            if (x[i] != 0) {
                fill(dp2.begin(),dp2.end(),0);
                dp2[x[i]] = dp1[x[i]]+dp1[x[i]-1]+dp1[x[i]+1];
                dp2[x[i]] %= MOD;
            }
            else {
                for (int j=1;j<=m;j++) {
                    dp2[j] = dp1[j]+dp1[j-1]+dp1[j+1];
                    dp2[j] %= MOD;
                }
            }
        }
        else {
            if (x[i] != 0) {
                fill(dp1.begin(),dp1.end(),0);
                dp1[x[i]] = dp2[x[i]]+dp2[x[i]-1]+dp2[x[i]+1];
                dp1[x[i]] %= MOD;
            }
            else {
                for (int j=1;j<=m;j++) {
                    dp1[j] = dp2[j]+dp2[j-1]+dp2[j+1];
                    dp1[j] %= MOD;
                }
            }
        }
        aux = !aux;
    }
    if (aux) {
        for (int i=1;i<=m;i++) {
            sum += dp2[i];
            sum %= MOD;
        }
    }
    else {
        for (int i=1;i<=m;i++) {
            sum += dp1[i];
            sum %= MOD;
        }
    }
    printf("%lld\n",sum);
    return 0;
}
