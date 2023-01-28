#include <bits/stdc++.h>
using namespace std;

/*
Este ejercicio consiste en recorrer todos los números del 1 al n, en cada número
voy a recorrer del 1 al n*(n+1)/4 (n*(n+1)/4 es la suma esperada ya que n*(n+1)/2
es la suma total y entonces la mita de esa es la suma que deben tener los dos
subconjuntos. Si yo estoy en el número x tal que 1<x<n y estoy en el número z
1<z<n*(n+1)/4 entonces dp[z] += dp[z-x] es decir la cantidad de formas de sumar z se
le agregan la cantidad de formas de sumar z-x que había anteriormente. Para no
confundir cuántas hay anteriormente y cuántas hay ahora se recomienda usar dos arreglos.

*/

const long long MOD = 1e9+7;

int main() {
    long long n,res;
    scanf("%lld",&n);
    res = n*(n+1)/2;
    if (res%2 == 0) {
        res /= 2;
        bool ok = 0;
        vector<long long> dp1(res+1),dp2(res+1);
        dp1[0] = dp2[0] = 1;
        for (int i=1;i<=n;i++) {
            if (!ok) {
                for (int j=0;j<=res;j++) {
                    dp2[j] = dp1[j]+(j-i >= 0 ? dp1[j-i] : 0);
                    dp2[j] %= 2*MOD;
                }
            }
            else {
                for (int j=0;j<=res;j++) {
                    dp1[j] = dp2[j]+(j-i >= 0 ? dp2[j-i] : 0);
                    dp1[j]%= 2*MOD;
                }
            }
            ok = !ok;
        }
        if (ok)
            printf("%lld\n",dp2[res]/2);
        else
            printf("%lld\n",dp1[res]/2);
    }
    else {
        printf("0\n");
    }
    return 0;
}
