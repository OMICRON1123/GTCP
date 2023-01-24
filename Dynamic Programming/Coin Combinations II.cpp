#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9+7;

/*
La lógica recursiva de este ejercicio es similar a la de Coin Combinations I solo que
en este caso se va a añadir moneda por moneda, primero se observa a cuáles sumas
se puede llegar con la moneda 1, luego se recorren todas las sumas y se le suman
las formas utilizando las moneda 2, es decir en este caso primero se itera sobre las
monedas y dentro de este ciclo se itera sobre las sumas.
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
    for (int i=0;i<n;i++) {
        for (int j=1;j<=x;j++) {
            if (j-c[i] >= 0) {
                dp[j] += dp[j-c[i]];
                dp[j] %= MOD;
            }
        }
    }
    printf("%lld\n",dp[x]);
    return 0;
}
