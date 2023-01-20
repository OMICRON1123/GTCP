#include <bits/stdc++.h>
using namespace std;

/*
Para este ejercicio se tiene que tomar en cuenta que si un subarreglo que comienza
en la posición i y termina en la posición j tiene una suma de x es porque
s[j]-s[i] = x donde s[j] representa la suma del subarreglo que va desde 0 hasta j.
Entonces basta ir recorriendo el arreglo almacenando la suma hasta la posición,
y luego se busca cuántas de las sumas anteriores corresponden a s[j]-x donde s[j] es
la posición actual, si ya existe una suma que dé s[i] = s[j] - x es porque entonces
es porque x = s[j]-s[i] y por ende se aumenta en uno el contador, si hay más de una suma
cuyo resultado es s[j]-x entonces se le suma esta cantidad al contador.
*/

int main() {
    long long n,x,s=0;
    long long cont=0;
    scanf("%lld%lld",&n,&x);
    map<long long,long long> sums;
    vector<long long> a(n);
    for (long long i=0;i<n;i++) {
        scanf("%lld",&a[i]);
    }
    sums.insert({0,1});
    for (long long i=0;i<n;i++) {
        s += a[i];
        if (sums.find(s-x) != sums.end()) {
            cont += sums[s-x];
        }
        if (sums.find(s) == sums.end()) {
            sums.insert({s,1});
        }
        else {
            sums[s]++;
        }
    }
    printf("%lld\n",cont);
    return 0;
}
