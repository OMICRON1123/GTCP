#include <bits/stdc++.h>
using namespace std;

/*
Para este ejercicio se modifica el algoritmo de Dijkstra, ahora en vez
de tener un arreglo que almacena números que indican la distancia más corta,
se tiene un arreglo que almacena conjuntos con las distancias (varias) más
cortas. Se tiene un arreglo auxiliar que almacena distancias que se pueden
usar más adelante, ahora el concepto de visitad no aplica ya que un nodo
se puede visitar varias veces para obtener todas las distancias, lo que se
tiene es que si un nodo no tiene distancias disponibles para usar entonces
sencillamente ya no se recorre. Tener en cuenta que el conjunto de distancias
puede ser de por mucho k elementos, cuando se tiene una nueva distancia
que es mayor a la mayor distancia del nodo y el nodo ya tiene sus k distancias
completadas pues sencillamente esta no se agrega al conjunto de distancias
disponibles, así es como este arreglo se va quedando vacío a medida que
pasa el tiempo.
*/

int main() {
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    vector<multiset<long long>> dist(n+1),auxdist(n+1);
    vector<vector<pair<int,int>>> graph(n+1);
    for (int i=0;i<m;i++) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        graph[a].push_back({b,c});
    }
    dist[1].insert(0);
    auxdist[1].insert(0);
    priority_queue<pair<long long,int>> q;
    q.push({0,1});
    while (!q.empty()) {
        int node = q.top().second;
        q.pop();
        if (auxdist[node].empty()) continue;
        for (int i=0;i<graph[node].size();i++) {
            q.push({-(*auxdist[node].begin()+graph[node][i].second),graph[node][i].first});
            for (auto it=auxdist[node].begin();it!=auxdist[node].end();it++) {
                if (dist[graph[node][i].first].size() < k || dist[graph[node][i].first].upper_bound(*it+graph[node][i].second) != dist[graph[node][i].first].end()){
                    dist[graph[node][i].first].insert(*it+graph[node][i].second);
                    auxdist[graph[node][i].first].insert(*it+graph[node][i].second);
                }
                if (dist[graph[node][i].first].size() > k) {
                    dist[graph[node][i].first].erase(prev(dist[graph[node][i].first].end()));
                }
                if (auxdist[graph[node][i].first].size() > k){
                    auxdist[graph[node][i].first].erase(prev(auxdist[graph[node][i].first].end()));
                }
            }
        }
        auxdist[node].clear();
    }
    for (auto it=dist[n].begin();it!=dist[n].end();it++) {
        printf(next(it) == dist[n].end() ? "%lld\n":"%lld ",*it);
    }
    return 0;
}
