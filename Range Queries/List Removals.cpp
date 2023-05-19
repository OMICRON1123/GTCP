#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

/*
Usar un conjunto indexado. El conjunto originalmente tendr� todos los n�meros
de 0 a n-1 luego cuando se elimine un n�mero se estar� eliminando el �ndice
de esa posici�n, y el elemento del arreglo que se muestra es el que est�
en la posici�n del �ndice reci�n eliminado.
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
