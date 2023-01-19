#include <bits/stdc++.h>
using namespace std;

/*
Para este ejercicio se mantiene un map que indica la �ltima posici�n en la que
apareci� un n�mero. El primer elemento siempre ser� emparejado con 0 y se a�adir�
al mapa con la posici�n 1. Luego cada vez que se vea un nuevo n�mero se a�adir�
al mapa con la posici�n respectiva y se eliminar�n todos los n�meros mayores a �l
del mapa ya que no son necesarios manteniendo esto se puede ver que el n�mero menor
que est� m�s cercano a otro ser� sencillamente el primer n�mero menor que a�n se encuentre
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
