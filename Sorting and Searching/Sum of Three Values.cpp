#include <bits/stdc++.h>
using namespace std;

/*
La lógica es ordenar el arreglo y sumar dos valores del arreglo y luego a la diferencia
entre el resultado y esta suma hacerle búsqueda binaria para ver si existe en los otros
valores del arreglo.
*/

int main() {
    bool ok = 0;
    int n,x;
    scanf("%d%d",&n,&x);
    vector<pair<int,int> > a(n);
    for (int i=0;i<n;i++) {
        scanf("%d",&a[i].first);
        a[i].second = i+1;
    }
    sort(a.begin(),a.end());
    for (int i=0;i<n-2;i++) {
        for (int j=i+1;j<n-1;j++) {
            auto it = lower_bound(a.begin()+j+1,a.end(),make_pair(x-a[i].first-a[j].first,0));
            if (it == a.end())
                continue;
            if ((*it).first == x-a[i].first-a[j].first) {
                printf("%d %d %d\n",a[i].second,a[j].second,(*it).second);
                ok = 1;
                break;
            }
        }
        if (ok)
            break;
    }
    if (!ok) {
        printf("IMPOSSIBLE\n");
    }
    return 0;
}
