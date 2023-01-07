#include <bits/stdc++.h>
using namespace std;

/*
La lógica de este ejercicio es bastante sencilla, primerso de ordenan las horas
de llegada y salida en orden ascendente por la de llegada y en caso de empate
ascendente por la de salida. Luego se comienza una simulación con ayuda de un
multimap, este multimap guarda la hora de salida de la habitación que le tocó a esa
persona. Si llega una persona cuya hora de llegada es menor o igual a la menor hora de
salida se tiene que crear una nueva habitación, aumentando el contador y se le asigna a esta. Ahora,
si la hora de llegada es mayor se elimina del multimap la persona con esta hora de
salida y se inserta un nuevo par donde la hora de salida es la del recién llegado
pero la habitación es la de la anterior persona.
*/

int main() {
    int n,cont = 1;
    scanf("%d",&n);
    multimap<int,int> dep;
    vector<tuple<int,int,int> > client(n);
    vector<int> room(n);
    for (int i=0;i<n;i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        client[i] = make_tuple(a,b,i);
    }
    sort(client.begin(),client.end());
    dep.insert({get<1>(client[0]),1});
    room[get<2>(client[0])] = 1;
    for (int i=1;i<n;i++) {
        if (get<0>(client[i]) <= dep.begin()->first) {
            dep.insert({get<1>(client[i]),++cont});
            room[get<2>(client[i])] = cont;
        }
        else {
            int r = dep.begin()->second;
            dep.erase(dep.begin());
            dep.insert({get<1>(client[i]),r});
            room[get<2>(client[i])] = r;
        }
    }
    printf("%d\n",cont);
    for (int i=0;i<n;i++) {
        printf(i == n-1 ? "%d\n":"%d ",room[i]);
    }
    return 0;
}
