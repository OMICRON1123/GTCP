#include <bits/stdc++.h>
using namespace std;

/*
En este ejercicio implementar BFS para encontrar el camino más corto y luego ir
guardando en cada nodo el nodo que lo precede en el camino.
*/

const int oo = 1e9;

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    vector<bool> visited(n+1);
    vector<int> node(n+1),dist(n+1,oo);
    vector<vector<int>> graph(n+1);
    queue<int> q;
    while (m--) {
        int a,b;
        scanf("%d%d",&a,&b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    q.push(1);
    dist[1] = 0;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        if (visited[curr]) continue;
        visited[curr] = 1;
        for (int i=0;i<graph[curr].size();i++) {
            if (!visited[graph[curr][i]] && dist[curr]+1 < dist[graph[curr][i]]) {
                q.push(graph[curr][i]);
                node[graph[curr][i]] = curr;
                dist[graph[curr][i]] = dist[curr]+1;
            }
        }
    }
    if (dist[n] != oo) {
        printf("%d\n",dist[n]+1);
        int curr = n;
        vector<int> sol;
        while (curr != 1) {
            sol.push_back(curr);
            curr = node[curr];
        }
        printf("%d",1);
        for (int i=sol.size()-1;i>=0;i--) {
            printf(" %d",sol[i]);
        }
        printf("\n");
    }
    else {
        printf("IMPOSSIBLE\n");
    }
    return 0;
}
