#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9+7;

/*
Para este ejercicio se usa la recursión dp[i] = dp[i-1]+..+dp[i-6] ya que la forma
de llegar a una suma es la suma de las maneras en las que se puede llegar a las 6
anteriores.
*/

int main() {
    int n;
    scanf("%d",&n);
    vector<long long> dp(n+1);
    dp[0] = 1;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=6;j++) {
            if (i - j >= 0) {
                dp[i] += dp[i-j];
                dp[i] %= MOD;
            }
        }
    }
    printf("%lld\n",dp[n]);
    return 0;
}
