#include <bits/stdc++.h>
using namespace std;

/*
En este ejercicio la relación de recursión es sencilla sea dp[i][j] igual al número
de cortes que toca hacer para volver un rectángulo de ixj en cuadrados. Entonces
se tiene que dp[i][i] = 0 ya que este es un cuadrado y que
dp[i][j] = min(dp[i-1][j]+dp[1][j],dp[i-2][j]+dp[2][j],...,dp[1][j]+dp[i-1][j])
dp[i][j] = min(dp[i][j-1]+dp[i][1],dp[i][j-2]+dp[i][2],...,dp[i][1]+dp[i][j-1])
que representa todos los cortes que se le pueden hacer al rectángulo actual.
*/

int main() {
    int a,b;
    scanf("%d%d",&a,&b);
    vector<vector<int> > dp(a,vector<int>(b,1e9));
    for (int i=0;i<b;i++) {
        dp[0][i] = i;
    }
    for (int i=1;i<a;i++) {
        for (int j=0;j<b;j++) {
            if (i == j) {
                dp[i][j] = 0;
            }
            else {
                for (int k=i-1;k>=0;k--) {
                    dp[i][j] = min(dp[i][j],dp[k][j]+dp[i-k-1][j]+1);
                }
                for (int k=j-1;k>=0;k--) {
                    dp[i][j] = min(dp[i][j],dp[i][k]+dp[i][j-k-1]+1);
                }
            }
        }
    }
    printf("%d\n",dp[a-1][b-1]);
    return 0;
}
