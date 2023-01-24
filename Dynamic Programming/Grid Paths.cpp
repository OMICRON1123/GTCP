#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9+7;

/*
La fórmula recursiva es dp[i][j] = dp[i-1][j] + dp[i][j-1] ya que la forma de llegar
a un punto es la suma de las formas de llegar al punto de arriba y al punto de la
izquierda. Si en el punto hay una trampa sencillamente se hace dp[i][j] = 0 y si el
punto está en el borde izquierdo o en el borde superior solo se toma dp[i][j-1]
o dp[i-1][j] respectivamente.
*/

int main() {
    int n;
    scanf("%d",&n);
    vector<string> grid(n);
    vector<vector<long long> > dp(n,vector<long long>(n));
    for (int i=0;i<n;i++) {
        cin>>grid[i];
    }
    dp[0][0] = grid[0][0] == '*' ? 0 : 1;
    for (int i=1;i<n;i++) {
        dp[0][i] = grid[0][i] == '*' ? 0 : dp[0][i-1];
    }
    for (int i=1;i<n;i++) {
        dp[i][0] = grid[i][0] == '*' ? 0 : dp[i-1][0];
    }
    for (int i=1;i<n;i++) {
        for (int j=1;j<n;j++) {
            if (grid[i][j] == '*') {
                dp[i][j] = 0;
            }
            else {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
                dp[i][j] %= MOD;
            }
        }
    }
    printf("%lld\n",dp[n-1][n-1]);
    return 0;
}
