#include <bits/stdc++.h>
using namespace std;

/*
Para este ejercicio la lógica es que si yo puedo formar todos los valores de 1
hasta n-1 pero no puedo formar n y me dan una moneda de valor m tal que m <= n
entonces puedo formar todos los valores de 1 hasta n+m-1 pero no puedo formar n+m
Esto se debe a que a cualquier valor entre 1 y n+m-1 al restarle el valor de la
moneda m, tengo como resultado un valor entre 1 y n-1 el cual ya sé que puedo formar

Por el contrario si m > n no podré seguir formando más números ya no puedo formar n.

Con esto en mente el algoritmo consiste en ordenar la entrada, se hace n = 1 como
primera opción y luego cada vez que se encuentre un x[i] <= n se le suma x[i] al valor
de n.
*/

int main() {
    int n;
    long long sum = 1;
    scanf("%d",&n);
    vector<long long> x(n);
    for (int i=0;i<n;i++) {
        scanf("%lld",&x[i]);
    }
    sort(x.begin(),x.end());
    for (int i=0;i<n;i++) {
        if (x[i] <= sum) {
            sum += x[i];
        }
        else
            break;
    }
    printf("%lld\n",sum);
    return 0;
}
