#include <bits/stdc++.h>
using namespace std;

/*
Para este caso la fórmula recursiva se basa en restarle al número actual cada uno
de los dígitos que tiene y ver cuál de estas restas requiere la mínima cantidad
de movimientos, solo tener en cuenta que el caso base es 0 cuya cantidad de movimientos
es 0.
*/

vector<int> digits(int x) {
    vector<int> res;
    while (x > 0) {
        res.push_back(x%10);
        x /= 10;
    }
    return res;
}

int main() {
    int n;
    scanf("%d",&n);
    vector<long long> dp(n+1,1e18);
    dp[0] = 0;
    for (int i=1;i<=n;i++) {
        vector<int> dig = digits(i);
        for (int j=0;j<dig.size();j++) {
            dp[i] = dp[i] < dp[i-dig[j]]+1 ? dp[i] : dp[i-dig[j]]+1;
        }
    }
    printf("%lld\n",dp[n]);
    return 0;
}
