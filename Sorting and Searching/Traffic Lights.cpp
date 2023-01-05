#include <bits/stdc++.h>
using namespace std;

/*
Para este ejercicio se tiene un set en el que se guardan las posiciones en las que
se han puesto semáforos y un multiset donde se guarda las longitudes de los
intervalos entre los semáforos. En el set se guarda originalmente las posiciones 0
y x, mientras que en el multiset originalmente se guarda la longitud inicial,
es decir x. Cada vez que se añade un semáforo se analiza qué semáforo había adelante
y atrás. Digamos que el semáforo de adelante está en la posición b y el de atrás en
la posición a. Entonces, se borra del multiset un intervalo de longitud b-a
mientras que se añaden dos intervalos uno b-p y otro p-a donde p representa la
posición en la que se está añadiendo un semáforo actualmente. Finalmente, se añade
p al set y se observa cuál es la longitud más larga en el multiset.
*/

int main() {
    int x,n,p;
    set<int> light;
    multiset<int> len;
    scanf("%d%d",&x,&n);
    light.insert(0);
    light.insert(x);
    len.insert(x);
    for (int i=0;i<n;i++) {
        scanf("%d",&p);
        auto it = light.upper_bound(p);
        int b = *it, a = *prev(it);
        len.insert(p-a);
        len.insert(b-p);
        len.erase(len.find(b-a));
        light.insert(p);
        printf(i == n-1 ? "%d\n":"%d ",*prev(len.end()));
    }
    return 0;
}
