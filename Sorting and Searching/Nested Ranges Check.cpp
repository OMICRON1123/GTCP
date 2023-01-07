#include <bits/stdc++.h>
using namespace std;

/*
Para este ejercicio se tienen que tomar dos lógicas diferentes para contiene y es
contenido.
En primer lugar para poder saber si un rango contiene otro se ordenan los rangos en
orden ascendente por su extremo final, y si hay empate de manera descendente por su
extremo inicial. Para los datos
1 6
1 5
2 4
4 8
3 6
El orden quedaría así
2 4
1 5
3 6
1 6
4 8
El primer rango no puede contener a ningún otro ya que es el rango con menor extremo
final y mayor inicial. Luego se fija una variable init que indica cuál es el mayor
extremo inicial hasta el momento, inicialmente se fija como el extremo inicial del
primer rango. Luego, se recorre el resto de elementos en orden, se sabe que el
extremo final del resto de rangos será mayor a los anteriores, por lo tanto, si su
extremo inicial es menor a init entonces sí contiene a otro rango mientras que si
es mayor no contiene ninguno y se hace init igual a este nuevo mayor valor.

Para saber si es contenido se procede a ordenar los rangos de distinta manera. Se
ordenan primero por orden ascendente por su extremo inicial y si empatan de manera
descendente por su extremo final, el orden de los elementos anteriores quedaría
así.
1 6
1 5
2 4
3 6
4 8
El primer elemento no puede ser contenido por ningún otro rango ya que es el rango
con mayor longitud que empieza de primeros. Luego se mantiene una variable last que
indica el extremo final de un rango menor a todos los ya analizados, last se hace
igual al extremo final del primer rango originalmente. Luego, si el siguiente rango
tiene un extremo final menor a last se sabe que está contenido en algún otro debido
a que su extremo final es menor y su extremo inicial mayor debido al orden y si el
extremo final es mayor se sabe que no está contenido en ninguno y se hace last igual
al extremo final de este último rango.
*/

int main() {
    int n,last,init;
    scanf("%d",&n);
    vector<tuple<int,int,int> > range(n);
    vector<bool> contains(n),iscontained(n);
    for (int i=0;i<n;i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        range[i] = make_tuple(x,y,i);
    }
    sort(range.begin(),range.end(),[](tuple<int,int,int> x,tuple<int,int,int> y) {
        if (get<1>(x) == get<1>(y)) return get<0>(x) > get<0>(y);
        return get<1>(x) < get<1>(y);
        });
    init = get<0>(range[0]);
    contains[get<2>(range[0])] = 0;
    for (int i=1;i<n;i++) {
        if (get<0>(range[i]) <= init) {
            contains[get<2>(range[i])] = 1;
        }
        else {
            init = get<0>(range[i]);
        }
    }
    sort(range.begin(),range.end(),[](tuple<int,int,int> x,tuple<int,int,int> y) {
        if (get<0>(x) == get<0>(y)) return get<1>(x) > get<1>(y);
        return get<0>(x) < get<0>(y);
        });
    last = get<1>(range[0]);
    iscontained[get<2>(range[0])] = 0;
    for (int i=1;i<n;i++) {
        if (get<1>(range[i]) <= last) {
            iscontained[get<2>(range[i])] = 1;
        }
        else {
            last = get<1>(range[i]);
        }
    }
    for (int i=0;i<n-1;i++)
        printf(contains[i] ? "1 " : "0 ");
    printf(contains[n-1] ? "1\n" : "0\n");
    for (int i=0;i<n-1;i++)
        printf(iscontained[i] ? "1 ": "0 ");
    printf(iscontained[n-1] ? "1\n" : "0\n");
    return 0;
}
