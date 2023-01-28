#include <bits/stdc++.h>
using namespace std;

/*
Hay una buena explicación para la lógica en el libro Guide To Competitive Programming
en general cada fila se puede representar como un string de unos y ceros, donde el
uno representa que se debe encajar con la fila de abajo y el cero q no. Primero se
llena una matriz, los strings de unos y ceros se pueden representar como números
debido a us representación binaria, entonces en la fila i de la matriz tiene un
número x si la representación binaria de x encaja con la representación binaria de i.
x es la fila superior, i es la inferior. Ahora, se sabe que x encaja con i, si todos
los unos de x tienen un 0 en esa posición en i, y los ceros de i que no están
debajos de uno siempre deben venir de a pares. Llenando esta matriz,
sencillamente luego se crea una dp en la que en cada fila del rectángulo se prueba
todas las posibles filas para este y se suma la cantidad de filas anteriores
que encajan con esta. Similarmente se usa representación binaria entonces para hallar
dp1[i] se busca la fila i de la matriz inicial, la cual contiene números x, y con
cada uno de estos números se hace dp1[i] += dp2[x] ya que i encaja con x, dp1 representa
la fila actual y dp2 la anterior.
*/
const long long MOD = 1e9+7;

int main() {
    bool ok = 0;
    int n,m;
    scanf("%d%d",&n,&m);
    vector<vector<int> > check(1<<n);
    for (int j=0;j<(1<<n);j++) {
        for (int k=0;k<(1<<n);k++) {
            bool valid = 1,cont0 = 0;
            for (int t=0;t<n;t++) {
                if (((1<<t)&k) != 0) {
                    if (((1<<t)&j) != 0 || cont0) {
                        valid = 0;
                    }
                }
                else if (((1<<t)&j) != 0) {
                    if (cont0) {
                        valid = 0;
                    }
                }
                else if (t == n-1 && !cont0) {
                    valid = 0;
                }
                else {
                    cont0 = !cont0;
                }
                if (!valid)
                    break;
            }
            if (valid) {
                check[j].push_back(k);
            }
        }
    }

    vector<long long> dp1(1<<n),dp2(1<<n);
    dp1[0] = 1;
    for (int i=0;i<m;i++) {
        if (!ok) {
            for (int j=0;j<(1<<n);j++) {
                dp2[j] = 0;
                for (int k=0;k<check[j].size();k++) {
                    dp2[j] += dp1[check[j][k]];
                    dp2[j] %= MOD;
                }
            }
        }
        else {
            for (int j=0;j<(1<<n);j++) {
                dp1[j] = 0;
                for (int k=0;k<check[j].size();k++) {
                    dp1[j] += dp2[check[j][k]];
                    dp1[j] %= MOD;
                }
            }
        }
        ok = !ok;
    }
    if (ok) {
        printf("%lld\n",dp2[0]);
    }
    else {
        printf("%lld\n",dp1[0]);
    }
    return 0;
}
