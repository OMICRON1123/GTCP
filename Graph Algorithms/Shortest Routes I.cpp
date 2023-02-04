#include <bits/stdc++.h>
using namespace std;

/*
Para este ejercicio solo se necesita aplicar el algoritmo de Dijkstra para hallar
la ruta más corta.
*/

const long long oo = 1e18;

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    vector<bool> visited(n+1);
    vector<long long> dist(n+1,oo);
    vector<vector<pair<int,int>>> graph(n+1);
    priority_queue<pair<long long,int>> dijkstra;
    while (m--) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        graph[a].push_back({b,c});
    }
    dist[1] = 0;
    dijkstra.push({0,1});
    while(!dijkstra.empty()) {
        int node = dijkstra.top().second;
        dijkstra.pop();
        if (visited[node]) continue;
        visited[node] = 1;
        for (int i=0;i<graph[node].size();i++) {
            int no = graph[node][i].first, w = graph[node][i].second;
            dist[no] = dist[no] < dist[node] + w ? dist[no] : dist[node]+w;
            dijkstra.push({-dist[no],no});
        }
    }
    printf("0");
    for (int i=2;i<=n;i++) {
        printf(" %lld",dist[i]);
    }
    return 0;
}
