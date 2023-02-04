#include <bits/stdc++.h>
using namespace std;

/*
Se tiene que aplicar Dijkstra con una pequeña modificación, cada vez que se procesa
un nodo se tiene que insertar en la cola de prioridad cuál es el valor mínimo
de llegar a ese nodo ya usando el cupón o sin haberlo usado. Para esto se pueden
manjera dos arreglos de costos uno en el que no se ha usado el cupón y otro en
el que sí. Cuando se procesa a un nodo en el cual ya se ha usado el cupón, se buscan
los nodos adyacentes y si el costo de viajar del nodo actual al adyacente más el costo
de llegar al actual es menor que el costo anterior del adyacente entonces se modifica
y se agrega a la cola de prioridad. Cuando se procesa un nodo cuando aún no se ha
usado el cupón entonces se tienen que ver los adyacentes tanto para llegar sin el cupón
como con el cupón y se insertan ambos valores a la cola de prioridad. En la cola de
prioridad también se tiene que guardar cada vez si la información que se inserta es
cuando ya se usó el cupón o cuando aún no se ha usado para poder procesarlo.
*/

const long long oo = 1e18;

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    vector<bool> visited0(n+1),visited1(n+1);
    vector<long long> dist0(n+1,oo),dist1(n+1,oo);
    vector<vector<pair<int,int>>> graph(n+1);
    priority_queue<tuple<long long,int,bool>> dijkstra;
    while (m--) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        graph[a].push_back({b,c});
    }
    dist0[1] = 0;
    dist1[1] = 0;
    dijkstra.push({0,1,0});
    while(!dijkstra.empty()) {
        int node = get<1>(dijkstra.top());
        bool coupon = get<2>(dijkstra.top());
        dijkstra.pop();
        if (coupon && visited1[node]) continue;
        if (!coupon && visited0[node]) continue;
        if (coupon) visited1[node] = 1;
        else visited0[node] = 1;
        for (int i=0;i<graph[node].size();i++){
            int no = graph[node][i].first,w = graph[node][i].second;
            if (coupon) {
                dist1[no] = min(dist1[no],dist1[node]+w);
                dijkstra.push({-dist1[no],no,1});
            }
            else {
                if (dist0[node]+w/2 < dist1[no]) {
                    dist1[no] = dist0[node]+w/2;
                    dijkstra.push({-dist1[no],no,1});
                }
                dist0[no] = min(dist0[no],dist0[node]+w);
                dijkstra.push({-dist0[no],no,0});
            }
        }
    }
    printf("%lld\n",dist1[n]);
    return 0;
}
