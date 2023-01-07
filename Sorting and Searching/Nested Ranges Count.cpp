#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_multiset;

/*
La lógica de este ejercicio es bastante similar al de Nested Ranges Check. Para ver
cuánto intervalos contiene un intervalo lo primero que se hace es ordenar de la misma
manera que en el anterior ejercicio pero en vez de mantener una variable que mantiene
el mayor extremo inicial en este caso se van a ir guardando todos los extremos
iniciales anteriores en un multiset indexado y luego con ayuda del order_of_key("extremo inicial actual") se
puede saber cuántos elementos tienen un extremo inicial menor al actual y entonces
la cantidad actual menos este número dará la cantidad de intervalos que contiene
el actual.
Similarmente para saber por cuántos intervalos es contenido un intervalor, se ordena
de la misma manera que el ejercicio anterior pero en este se mantiene un multiset indexado
que mantiene los extremos finales de los intervalos ya examinados, luego hacemos
order_of_key("estremo final actual") y esto nos dará cuánto intervalos anteriores tienen
un extremo final menor al actual, si restamos la cantidad actual de intervalos examinados
menos este número nos dará la cantidad de intervalos que tienen extremo final mayor o
igual al actual, es decir la cantidad de intervalos en los que está contenido.
Nótese que esto funciona debido a la manera de ordenar ya que en el primer caso
ningún intervalo después de los ya examinado es contenido por el actual ya que
su extremo final es mayor mientras que en el segundo caso ningún intervalo siguiente
al actual puede contener a este ya que su extremo inicial es mayor y en caso de
ser igual su extremo final es menor.
*/

int main() {
    int n;
    indexed_multiset init,last;
    scanf("%d",&n);
    vector<int> contains(n),iscontained(n);
    vector<tuple<int,int,int> > range(n);
    for (int i=0;i<n;i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        range[i] = make_tuple(x,y,i);
    }
    sort(range.begin(),range.end(),[](tuple<int,int,int> x,tuple<int,int,int> y) {
        if (get<1>(x) == get<1>(y)) return get<0>(x) > get<0>(y);
        return get<1>(x) < get<1>(y);
    });
    contains[get<2>(range[0])] = 0;
    init.insert(get<0>(range[0]));
    for (int i=1;i<n;i++) {
        contains[get<2>(range[i])] = i - init.order_of_key(get<0>(range[i]));
        init.insert(get<0>(range[i]));
    }
    sort(range.begin(),range.end(),[](tuple<int,int,int> x,tuple<int,int,int> y) {
        if (get<0>(x) == get<0>(y)) return get<1>(x) > get<1>(y);
        return get<0>(x) < get<0>(y);
    });
    iscontained[get<2>(range[0])] = 0;
    last.insert(get<1>(range[0]));
    for (int i=1;i<n;i++) {
        iscontained[get<2>(range[i])] = i - last.order_of_key(get<1>(range[i]));
        last.insert(get<1>(range[i]));
    }
    for (int i=0;i<n;i++)
        printf(i == n-1 ? "%d\n":"%d ",contains[i]);
    for (int i=0;i<n;i++)
        printf(i == n-1 ? "%d\n":"%d ",iscontained[i]);
    return 0;
}
