#include <bits/stdc++.h>
using namespace std;

/*
Esta es otra forma para resolver Cycle Finding sin DFS, se hace el
algoritmo de Bellman-Ford, pero cada vez que una distancia a cierto
nodo disminuya se guarda en un vector que el predecesor del nodo actual
es el nodo que le hizo disminuir su distancia, si al final alguna distancia
disminuye, es porque está conectada con el nodo, entonces se toma
el nodo al cual le disminuyó la distancia y se encuentra su predecesor,
este proceso se repite n veces ya que el nodo que disminuyó como tal
puede no ser parte del ciclo, solo estar conectado a él, pero
retrocediendo n nodos se asegura estar en el ciclo, ya con esto se
recorre el ciclo hasta que se vuelva al mismo nodo mientras se guarda
en un vector, este vector se cambia de orden con reverse y este
será el ciclo deseado.
*/

const long long oo = 1e17;

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    vector<int> former(n+1);
    vector<long long> dist(n+1,oo);
    vector<tuple<int,int,int>> edge(m);
    for (int i=0;i<m;i++) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        edge[i] = {a,b,c};
    }
    int aux;
    dist[1] = 0;
    for (int i=0;i<n+1;i++) {
        aux = 0;
        for (int j=0;j<m;j++) {
            int a,b,c;
            tie(a,b,c) = edge[j];
            if (dist[a] + c < dist[b]) {
                dist[b] = dist[a] + c;
                former[b] = a;
                aux = b;
            }
        }
    }
    if (aux) {
        printf("YES\n");
        vector<int> cycle;
        for (int i=0;i<n+1;i++) {
            aux = former[aux];
        }
        cycle.push_back(aux);
        aux = former[aux];
        while (aux != cycle[0]) {
            cycle.push_back(aux);
            aux = former[aux];
        }
        reverse(cycle.begin(),cycle.end());
        for (int i=0;i<cycle.size();i++) {
            printf("%d ",cycle[i]);
        }
        printf("%d\n",cycle[0]);
    }
    else {
        printf("NO\n");
    }
}
