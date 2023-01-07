#include <bits/stdc++.h>
using namespace std;

/*
Se hace búsqueda binaria sobre la respuesta, para ello se tiene en cuenta que si
el tiempo es mid entonces la cantidad de productos hechos en eso tiempo es la suma
de mid/k[i], si la cantidad de producto es menor a t entonces se sabe que el tiempo
deberá ser mayor a mid, se hace lo = mid + 1 mientras que si es mayor o igual se hace
hi = mid
*/

int main() {
    long long n,t;
    scanf("%lld%lld",&n,&t);
    vector<long long> k(n);
    for (int i=0;i<n;i++) {
        scanf("%lld",&k[i]);
    }
    sort(k.begin(),k.end());
    long long lo = 0,hi = t*k[0];
    while (lo < hi) {
        long long mid = lo+(hi-lo)/2,pro = 0;
        for (int i=0;i<n;i++) {
            pro += mid/k[i];
        }
        if (pro < t) {
            lo = mid+1;
        }
        else {
            hi = mid;
        }
    }
    printf("%lld\n",lo);
    return 0;
}
