#include <bits/stdc++.h>
using namespace std;

/*
Para este ejercicio se almacenan la suma de todas las parejas de valores del arreglo
en un mapa y luego se busca en este mapa la diferencia entre el valore deseado y la suma de otros dos valores, si hay dos parejas
que suman el número entonces ya se tienen los cuatro números que lo suman.
*/

int main() {
    bool ok = 0;
    int n,x;
    scanf("%d%d",&n,&x);
    vector<int> a(n);
    for (int i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
    map<int,pair<int,int> > sums;
    for (int i=0;i<n-1;i++) {
        for (int j=i+1;j<n;j++) {
            if (sums.find(a[i]+a[j]) == sums.end()) {
                sums.insert({a[i]+a[j],{i+1,j+1}});
            }
        }
    }
    for (int i=0;i<n-1;i++) {
        for (int j=i+1;j<n;j++) {
            if (sums.find(x-a[i]-a[j]) != sums.end()) {
                int f = sums[x-a[i]-a[j]].first,s = sums[x-a[i]-a[j]].second;
                if (f != i+1 && s != j+1 && f != j+1 && s != i+1) {
                    printf("%d %d %d %d\n",i+1,j+1,f,s);
                    ok = 1;
                }
            }
            if (ok)
                break;
        }
        if (ok)
            break;
    }
    if (!ok) {
        printf("IMPOSSIBLE\n");
    }
    return 0;
}
