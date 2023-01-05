#include <bits/stdc++.h>
using namespace std;

/*
Para este ejercicio nada más se hace una simulación con un multiset, por cada valor
que se lee del tamaño del cubo se busca el primer valor mayor a este en el
multiset, se elimina este valor y se inserta el nuevo indicando que el cubo actual
se colocó encima del otro. Si no hay ningún valor mayor que este sencillamente
se inserta en el multiset y se aumenta en 1 la cantidad de torres indicando
que este nuevo cubo formará una torre.
*/

int main() {
    int n,k,cont = 0;
    scanf("%d",&n);
    multiset<int> tower;
    for (int i=0;i<n;i++) {
        scanf("%d",&k);
        if (tower.empty()) {
            cont++;
        }
        else {
            auto it = tower.upper_bound(k);
            if (it == tower.end()) {
                cont++;
            }
            else {
                tower.erase(it);
            }
        }
        tower.insert(k);
    }
    printf("%d\n",cont);
    return 0;
}
