#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_multiset;

/*
Usar un multiset indexado para poder llevar el control de los salarios
que son menores a cierto salario y así se puede calcular cuántos salarios
hay en determinado rango. Para actualizar solo se borra el valor de multiset
y se añade el nuevo.
*/

int main() {
    int n,q;
    scanf("%d%d",&n,&q);
    vector<int> p(n);
    indexed_multiset ms;
    for (int i=0;i<n;i++) {
        scanf("%d",&p[i]);
        ms.insert(p[i]);
    }
    while (q--) {
        string s;
        cin>>s;
        if (s.compare("!") == 0) {
            int k,x;
            scanf("%d%d",&k,&x);
            k--;
            ms.erase(ms.find_by_order(ms.order_of_key(p[k])));
            ms.insert(x);
            p[k] = x;
        }
        else {
            int a,b;
            scanf("%d%d",&a,&b);
            printf("%d\n",ms.order_of_key(b+1)-ms.order_of_key(a));
        }
    }
}
