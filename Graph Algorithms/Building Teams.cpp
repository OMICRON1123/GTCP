#include <bits/stdc++.h>
using namespace std;

/*
Este problema se puede ver como colorear un grafo de dos colores distintos de tal
manera que los nodos adyacentes no tengan el mismo color, haciendo un DFS se resuelve
fácilmente
*/

bool pos = 1;
vector<bool> visited,team;
vector<vector<int>> graph;

void DFS(bool ok,int node) {
    if (visited[node] && ok != team[node]) {
        pos = 0;
        return;
    }
    if (visited[node]) return;
    visited[node] = true;
    team[node] = ok;
    for (int i=0;i<graph[node].size();i++) {
        DFS(!ok,graph[node][i]);
    }
}

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    visited = vector<bool>(n+1);
    team = vector<bool>(n+1);
    graph = vector<vector<int>>(n+1);
    while (m--) {
        int a,b;
        scanf("%d%d",&a,&b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i=1;i<=n;i++) {
        if (visited[i]) continue;
        DFS(0,i);
    }
    if (pos)
        for (int i=1;i<=n;i++) {
            printf(team[i] ? "2\n" : "1\n");
        }
    else
        printf("IMPOSSIBLE\n");
    return 0;
}
