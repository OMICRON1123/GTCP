#include <bits/stdc++.h>
using namespace std;

/*
El ejercicio se puede ver como dos matrices nxn. En la primera fila se van a guardar
los mejores score para subarreglos de longitud 1, en la segunda fila los mejores score
para subarreglos de longitud dos y así sucesivamente. El número de la columna
representa que en la posición [i][j] será el mejor score para un arreglo de longitud i
el cual comienza en la posición j. La segunda matriz será similar solo que en esta
la posición [i][j] representa un arreglo de longitud i que termina en la posición j
si dp1 es la primera matriz y dp2 es la segunda matriz entonces
dp1[i][j] se halla de la siguiente manera
si dp1[i-1][j+1] es mayor que dp2[i-1][j+i]
entonces dp1[i][j] = x[j] + max(dp1[i-2][j+2],dp2[i-2][j+i])
Si no entonces dp1[i][j] = x[j] + max(dp1[i-2][j+1],dp2[i-2][j+i-1])
Esto se debe a que cada fila representa el turno de un jugador y el jugador anterior
siempre escoge la opción más óptima para él de resto es sencillamente
el valor de la posición actual sumado con el máximo entre quitar el último elemento
del arreglo de longitud i-2 o quitar el primero, similarmente para dp2 se tiene que
si dp2[i-1][j-1] es mayor que dp1[i-1][j-i]
entonces dp2[i][j] = x[j] + max(dp1[i-2][j-i],dp2[i-2][j-2])
Si no entonces dp2[i][j] = x[j] + max(dp2[i-2][j-1],dp1[i-2][j-i+1])
Al final la respuesta será el máximo entre dp1[n][1] y dp2[n][n]
Se puede optimizar la memoria remplazando las matrices con cuatro vectores para que
no ocupe tanta memoria y pueda pasar.
*/

int main() {
    int n;
    scanf("%d",&n);
    bool ok = n%2;
    vector<int> x(n);
    vector<long long> dp1r(n),dp2r(n),auxdp1r(n),auxdp2r(n);
    vector<long long> dp1l(n),dp2l(n),auxdp1l(n),auxdp2l(n);
    for (int i=0;i<n;i++) {
        scanf("%d",&x[i]);
        dp1r[i] = dp2r[i] = auxdp1r[i] = auxdp2r[i] = x[i];
        dp1l[i] = dp2l[i] = auxdp1l[i] = auxdp2l[i] = x[i];
    }
    if (ok) {
        for (int i=0;i<n-1;i++) {
            dp2r[i] = auxdp2r[i] = x[i];
            dp2l[i+1] = auxdp2l[i+1] = x[i+1];
        }
        dp2r[n-1] = auxdp2r[n-1] = -1e18;
        dp2l[0] = auxdp2l[0] = -1e18;
    }
    else {
        for (int i=0;i<n-1;i++) {
            dp1r[i] = auxdp1r[i] = x[i];
            dp1l[i+1] = auxdp1l[i+1] = x[i+1];
        }
        dp1r[n-1] = auxdp1r[n-1] = -1e18;
        dp1l[0] = auxdp1l[0] = -1e18;
    }
    for (int i=2;i<n;i++) {
        if (ok) {
            for (int j=0;j+i<n;j++) {
                if (dp2r[j+1] > dp2l[j+i]) {
                    dp1r[j] = x[j] + max(auxdp1r[j+2],auxdp1l[j+i]);
                }
                else {
                    dp1r[j] = x[j] + max(auxdp1r[j+1],auxdp1l[j+i-1]);
                }
            }
            for (int j=i;j<n;j++) {
                if (dp2r[j-i] > dp2l[j-1]){
                    dp1l[j] = x[j] + max(auxdp1r[j-i+1],auxdp1l[j-1]);
                }
                else {
                    dp1l[j] = x[j] + max(auxdp1r[j-i],auxdp1l[j-2]);
                }
            }
            auxdp1r = dp1r;
            auxdp1l = dp1l;
        }
        else {
            for (int j=0;j+i<n;j++) {
                if (dp1r[j+1] > dp1l[j+i]) {
                    dp2r[j] = x[j] + max(auxdp2r[j+2],auxdp2l[j+i]);
                }
                else {
                    dp2r[j] = x[j] + max(auxdp2r[j+1],auxdp2l[j+i-1]);
                }
            }
            for (int j=i;j<n;j++) {
                if (dp1r[j-i] > dp1l[j-1]){
                    dp2l[j] = x[j] + max(auxdp2r[j-i+1],auxdp2l[j-1]);
                }
                else {
                    dp2l[j] = x[j] + max(auxdp2r[j-i],auxdp2l[j-2]);
                }
            }
            auxdp2r = dp2r;
            auxdp2l = dp2l;
        }
        ok = !ok;
    }
    printf("%lld\n",max(dp1l[n-1],dp1r[0]));
    return 0;
}
