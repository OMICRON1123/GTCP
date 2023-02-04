#include <bits/stdc++.h>
using namespace std;

/*
Para este ejercicio hacer un DFS para buscar el ciclo, cuando se llegue a un nodo
que ya se halla visitado antes ese es el principio del ciclo, luego se almacenan los
nodos del ciclo en un vector.
*/

bool print = 0,found = 0;
vector<bool> visited;
vector<int> cycle;
vector<vector<int>> graph;

void DFS(int node,int pre) {
    if (visited[node]) {
        found = 1;
        print = 1;
        cycle.push_back(node);
        return;
    }
    visited[node] = 1;
    for (int i=0;i<graph[node].size();i++) {
        if (found) break;
        if (graph[node][i] != pre) DFS(graph[node][i],node);
    }
    if (print) {
        cycle.push_back(node);
        if (node == cycle[0]) {
            print = 0;
        }
    }
}

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    visited = vector<bool>(n+1);
    graph = vector<vector<int>>(n+1);
    while (m--) {
        int a,b;
        scanf("%d%d",&a,&b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i=1;i<=n;i++) {
        if (found) break;
        if (!visited[i]) DFS(i,-1);
    }
    if (found) {
        printf("%d\n",cycle.size());
        for (int i=cycle.size()-1;i>=0;i--) {
            printf("%d ",cycle[i]);
        }
    }
    else
        printf("IMPOSSIBLE\n");
    return 0;
}
