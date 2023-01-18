#include <bits/stdc++.h>
using namespace std;

/*
Para este ejercicio toca ordenar los tiempos de lectura de menor a mayor de los libros
y luego se comienza a mantener una variable con la suma de esos tiempos hasta el actual.
Si el libro actual es mayor a la suma de los anteriores, la respuesta pasa a ser
el tiempo del libro actual multiplicado por 2 si no es así la respuesta será la suma
hasta el tiempo actual.
*/

int main() {
    int n;
    scanf("%d",&n);
    long long s,ans;
    vector<long long> t(n);
    for (int i=0;i<n;i++) {
        scanf("%lld",&t[i]);
    }
    sort(t.begin(),t.end());
    s = t[0];
    ans = t[0]<<1;
    for (int i=1;i<n;i++) {
        if (t[i] >= s) {
            ans = t[i]*2;
        }
        else {
            ans = t[i] + s;
        }
        s += t[i];
    }
    printf("%lld\n",ans);
    return 0;
}
