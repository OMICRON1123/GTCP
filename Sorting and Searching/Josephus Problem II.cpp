#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

/*
Para este ejercicio se hace uso de las estructuras de datos del compilador G++ y con
ayuda del conjunto indexado se puede hacer fácilmente la simulación para cualquier
caso, solamente aumentando la posición que se de imprimir en k y haciendo matemática
modular.
*/

int main() {
    int n,k;
    indexed_set num;
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++) {
        num.insert(i);
    }
    int pos = k;
    while (num.size() >  0) {
        pos %= num.size();
        printf(num.size() == 1 ? "%d\n":"%d ",*num.find_by_order(pos));
        num.erase(num.find_by_order(pos));
        pos += k;
    }
    return 0;
}
