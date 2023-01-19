#include <bits/stdc++.h>
using namespace std;

/*
Para este ejercicio se mantiene un map que indica la última posición en la que
apareció un número. El primer elemento siempre será emparejado con 0 y se añadirá
al mapa con la posición 1. Luego cada vez que se vea un nuevo número se añadirá
al mapa con la posición respectiva y se eliminarán todos los números mayores a él
del mapa ya que no son necesarios manteniendo esto se puede ver que el número menor
que está más cercano a otro será sencillamente el primer número menor que aún se encuentre
en el map.
*/

int main() {
    int n;
    map<int,int> pos;
    scanf("%d",&n);
    vector<int> x(n);
    for (int i=0;i<n;i++) {
        scanf("%d",&x[i]);
    }
    printf("0");
    pos.insert({x[0],1});
    for (int i=1;i<n;i++){
        if (pos.lower_bound(x[i]) == pos.begin()) {
            printf(" 0");
            pos.clear();
            pos.insert({x[i],i+1});
        }
        else {
            auto it = prev(pos.lower_bound(x[i]));
            printf(" %d",it->second);
            pos.erase(next(it),pos.end());
            pos.insert({x[i],i+1});
        }
    }
    return 0;
}
