#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_multiset;

/*
En este ejercicio usamos un multiset indexado para acceder fácilmente a la posición
de la mitad, cada vez que se agrega un elemento se elimina el primero que se había
añadido y se le calcula la mediana al nuevo conjunto.
*/

int main() {
    int n,k,idx = 0;
    scanf("%d%d",&n,&k);
    vector<int> x(n);
    indexed_multiset sub;
    for (int i=0;i<n;i++) {
        scanf("%d",&x[i]);
        sub.insert(x[i]);
        if (i >= k-1) {
            auto it = sub.find_by_order(sub.order_of_key(x[idx++]));
            printf(i == n-1 ? "%d\n" : "%d ",*sub.find_by_order((k-1)/2));
            sub.erase(it);
        }
    }
    return 0;
}
