#include <bits/stdc++.h>
using namespace std;

/*
Para este ejercicio sencillamente se mantiene un conjunto que indica cuántos elementos
diferentes tiene un subarreglo y se mantiene una variable que cuenta como tal la cantidad
de elementos totales, sean diferentes o no, si la cantidad de elementos diferentes
supera a k entonces sencillamente se comienzan a eliminar los elementos del principio
hasta q no la supere, cada vez que se añade un elemento y en total hay s elementos
y estos cumplen que no hay más de k elementos diferentes la cantidad de subarreglos
aumenta en s ya que existen s posibles nuevos subarreglos que son los que terminan
en el último elemento añadido.
*/

int main() {
    int n,k,idx = 0,sz = 0;
    scanf("%d%d",&n,&k);
    set<int> dis;
    map<int,int> rep;
    vector<int> x(n);
    for (int i=0;i<n;i++) {
        scanf("%d",&x[i]);
    }
    long long res = 0;
    for (int i=0;i<n;i++) {
        dis.insert(x[i]);
        if (rep.find(x[i]) == rep.end()) {
            rep.insert({x[i],1});
        }
        else {
            rep[x[i]]++;
        }
        sz++;
        if (dis.size() > k) {
            while (rep[x[idx]] > 1) {
                sz--;
                rep[x[idx]]--;
                idx++;
            }
            sz--;
            rep.erase(rep.find(x[idx]));
            dis.erase(dis.find(x[idx++]));
        }
        res += sz;
    }
    printf("%lld\n",res);
    return 0;
}
