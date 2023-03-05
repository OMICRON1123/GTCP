#include <bits/stdc++.h>
using namespace std;

/*
Aplicar topological sort
*/

bool found;
vector<int> visited,cycle;
vector<vector<int>> graph;

void DFS(int node) {
    if (visited[node] == 2) return;
    if (visited[node] == 1) {
        found = 1;
        return;
    }
    visited[node] = 1;
    for (int i=0;i<graph[node].size();i++) {
        if (found) break;
        DFS(graph[node][i]);
    }
    visited[node] = 2;
    cycle.push_back(node);
}

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    visited = vector<int>(n+1);
    graph = vector<vector<int>>(n+1);
    while (m--) {
        int a,b;
        scanf("%d%d",&a,&b);
        graph[a].push_back(b);
    }
    for (int i=1;i<=n;i++) {
        if (found) break;
        if (visited[i] == 0) DFS(i);
    }
    if (!found) {
        for (int i=cycle.size()-1;i>0;i--) printf("%d ",cycle[i]);
        printf("%d\n",cycle[0]);
    }
    else {
        printf("IMPOSSIBLE\n");
    }
    return 0;
}
