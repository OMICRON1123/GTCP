#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_multiset;

/*
Para este ejercicio hay que tener en cuenta que lo mejor es convertir todos los números
a la mediana de cada subarreglo. Primero se calcula para el subarreglo inicial y luego
se calcula para los siguientes sumando la distancia del nuevo elemento a la mediana
resto la distancia del elemento que se eliminó a la mediana anterior y si la cantidad
de elementos es par sumar por último la diferencia entre la mediana anterior y la actual.
*/

int main() {
    int n,k,med0,med1,idx = 0;
    long long cost = 0;
    scanf("%d%d",&n,&k);
    indexed_multiset sub;
    vector<int> x(n);
    for (int i=0;i<n;i++) {
        scanf("%d",&x[i]);
    }
    for (int i=0;i<k;i++) {
        sub.insert(x[i]);
    }
    med0 = med1 = *sub.find_by_order((k-1)/2);
    for (int i=0;i<k;i++) {
        cost += abs(x[i]-med1);
    }
    printf("%lld",cost);
    for (int i=k;i<n;i++) {
        auto it = sub.find_by_order(sub.order_of_key(x[idx]));
        sub.erase(it);
        sub.insert(x[i]);
        med1 = *sub.find_by_order((k-1)/2);
        if (k%2 != 0) {
            cost -= abs(x[idx]-med0);
            cost += abs(x[i]-med1);
        }
        else {
            cost -= abs(x[idx]-med0);
            cost += med0 - med1;
            cost += abs(x[i]-med1);
        }
        med0 = med1;
        idx++;
        printf(" %lld",cost);
    }
    return 0;
}
