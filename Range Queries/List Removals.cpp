#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

/*
Usar un conjunto indexado. El conjunto originalmente tendrá todos los números
de 0 a n-1 luego cuando se elimine un número se estará eliminando el índice
de esa posición, y el elemento del arreglo que se muestra es el que está
en la posición del índice recién eliminado.
*/

int main() {
    int n;
    scanf("%d",&n);
    indexed_set s;
    vector<int> x(n);
    for (int i=0;i<n;i++) {
        scanf("%d",&x[i]);
        s.insert(i);
    }
    while (n--) {
        int pos;
        scanf("%d",&pos);
        int r = *s.find_by_order(--pos);
        s.erase(s.find_by_order(pos));
        printf(n ? "%d ":"%d\n",x[r]);
    }
    return 0;
}
