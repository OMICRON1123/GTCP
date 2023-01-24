#include <bits/stdc++.h>
using namespace std;

/*
Un problema knapsack en el que las p�ginas son la variable a optimizar se va llenando
la matriz n�mero por n�mero. En cada caso se puede tomar dos decisiones, ya sea comprar
el libro y sumar el n�mero de p�ginas a la cantidad m�xima de p�ginas que puedo comprar
con el dinero que tengo menos el costo del libro o no comprarlo y ver cu�ntas p�ginas
anteriormente pod�a tomar con ese mismo precio. Se escoge el m�ximo de p�ginas entre
estas dos opciones y as� sucesivamente se va llenando la matriz. Luego se puede optimizar
el espacio de memoria haciendo el knapsack solo con un vector.
*/

int main() {
    int n,x;
    scanf("%d%d",&n,&x);
    vector<pair<int,int> > book(n);
    vector<long long> dp(x+1);
    for (int i=0;i<n;i++) {
        scanf("%d",&book[i].first);
    }
    for (int i=0;i<n;i++) {
        scanf("%d",&book[i].second);
    }
    for (int i=0;i<n;i++) {
        for (int j=x;j>=1;j--) {
            if (j - book[i].first >= 0) {
                dp[j] = dp[j-book[i].first]+book[i].second > dp[j] ? dp[j-book[i].first]+book[i].second : dp[j];
            }
        }
    }
    printf("%lld\n",dp[x]);
    return 0;
}
