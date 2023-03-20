#include <bits/stdc++.h>
using namespace std;

/*
Aplicar Dijkstra pero llevando de control de la cantidad de maneras de llegar, del
mínimo y máximo número de vuelos en otros arreglos.
*/

const long long oo = 1e17;
const long long MOD = 1e9+7;

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    vector<vector<pair<int,int>>> graph(n+1);
    vector<bool> visited(n+1,0);
    vector<long long> dist(n+1,oo),fly(n+1,0),minf(n+1,oo),maxf(n+1,-1);
    while (m--) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        graph[a].push_back({b,c});
    }
    priority_queue<pair<long long,int>> q;
    dist[1] = 0;
    fly[1] = 1;
    minf[1] = 0;
    maxf[1] = 0;
    q.push({0,1});
    while(!q.empty()) {
        int node = q.top().second;
        q.pop();
        if (visited[node]) continue;
        visited[node] = 1;
        for (int i=0;i<graph[node].size();i++) {
            q.push({-(dist[node]+graph[node][i].second),graph[node][i].first});
            if (dist[graph[node][i].first] > dist[node] + graph[node][i].second) {
                dist[graph[node][i].first] = dist[node] + graph[node][i].second;
                fly[graph[node][i].first] = fly[node];
                minf[graph[node][i].first] = minf[node]+1;
                maxf[graph[node][i].first] = maxf[node]+1;
            }
            else if (dist[graph[node][i].first] == dist[node] + graph[node][i].second) {
                fly[graph[node][i].first] += fly[node];
                fly[graph[node][i].first] %= MOD;
                minf[graph[node][i].first] = min(minf[graph[node][i].first],minf[node]+1);
                maxf[graph[node][i].first] = max(maxf[graph[node][i].first],maxf[node]+1);
            }
        }
    }
    printf("%lld %lld %lld %lld\n",dist[n],fly[n],minf[n],maxf[n]);
    return 0;
}
