#include <bits/stdc++.h>
using namespace std;

/*
En este ejercicio se va recorriendo moneda por moneda, para ver si una suma es posible
añadiendo esta nueva moneda se coge la suma y se le resta el valor de la moneda.
Si esta diferencia ya era posible anteriormente entonces esto quiere decir que
esta suma sí es posible, y si la suma no era posible antes de añadir la nueva moneda
se aumenta en uno el contador de sumas. Si la diferencia no era posible anteriormente
entonces la suma analizada no es posible, de esta manera se analizan todas las posibles
sumas.
*/

int main() {
    bool ok = 0;
    int n,s = 0,cont = 0;
    scanf("%d",&n);
    vector<int> x(n);
    for (int i=0;i<n;i++) {
        scanf("%d",&x[i]);
        s += x[i];
    }
    vector<bool> dp1(s+1),dp2(s+1);
    dp1[0] = dp2[0] = 1;
    for (int i=0;i<n;i++) {
        if (!ok) {
            for (int j=1;j<=s;j++) {
                dp2[j] = dp1[j];
                if (!dp2[j] && j-x[i] >= 0) {
                    dp2[j] = dp1[j-x[i]];
                    cont += dp2[j] ? 1 : 0;
                }
            }
        }
        else {
            for (int j=1;j<=s;j++) {
                dp1[j] = dp2[j];
                if (!dp1[j] && j-x[i] >= 0) {
                    dp1[j] = dp2[j-x[i]];
                    cont += dp1[j] ? 1 : 0;
                }
            }
        }
        ok = !ok;
    }
    printf("%d\n",cont);
    if (ok) {
        int aux = 0;
        for (int i=1;i<=s;i++) {
            if (dp2[i]) {
                printf(aux == cont-1 ? "%d\n" : "%d ", i);
                aux++;
            }
        }
    }
    else {
        int aux = 0;
        for (int i=1;i<=s;i++) {
            if (dp1[i]) {
                printf(aux == cont-1 ? "%d\n" : "%d ", i);
                aux++;
            }
        }
    }
    return 0;
}
