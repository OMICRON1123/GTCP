#include <bits/stdc++.h>
using namespace std;

/*
Se tiene que aplicar Dijkstra con una peque�a modificaci�n, cada vez que se procesa
un nodo se tiene que insertar en la cola de prioridad cu�l es el valor m�nimo
de llegar a ese nodo ya usando el cup�n o sin haberlo usado. Para esto se pueden
manjera dos arreglos de costos uno en el que no se ha usado el cup�n y otro en
el que s�. Cuando se procesa a un nodo en el cual ya se ha usado el cup�n, se buscan
los nodos adyacentes y si el costo de viajar del nodo actual al adyacente m�s el costo
de llegar al actual es menor que el costo anterior del adyacente entonces se modifica
y se agrega a la cola de prioridad. Cuando se procesa un nodo cuando a�n no se ha
usado el cup�n entonces se tienen que ver los adyacentes tanto para llegar sin el cup�n
como con el cup�n y se insertan ambos valores a la cola de prioridad. En la cola de
prioridad tambi�n se tiene que guardar cada vez si la informaci�n que se inserta es
cuando ya se us� el cup�n o cuando a�n no se ha usado para poder procesarlo.
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
