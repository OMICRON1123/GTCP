#include <bits/stdc++.h>
using namespace std;

/*
Para este ejercicio se tiene un set en el que se guardan las posiciones en las que
se han puesto sem�foros y un multiset donde se guarda las longitudes de los
intervalos entre los sem�foros. En el set se guarda originalmente las posiciones 0
y x, mientras que en el multiset originalmente se guarda la longitud inicial,
es decir x. Cada vez que se a�ade un sem�foro se analiza qu� sem�foro hab�a adelante
y atr�s. Digamos que el sem�foro de adelante est� en la posici�n b y el de atr�s en
la posici�n a. Entonces, se borra del multiset un intervalo de longitud b-a
mientras que se a�aden dos intervalos uno b-p y otro p-a donde p representa la
posici�n en la que se est� a�adiendo un sem�foro actualmente. Finalmente, se a�ade
p al set y se observa cu�l es la longitud m�s larga en el multiset.
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
