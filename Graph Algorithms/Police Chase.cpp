#include <bits/stdc++.h>
using namespace std;

/*
Aplicar un algoritmo de maximum flow para hallar el minimum cut,
luego añadir aristas sabiendo que si b no es alcanzable pero a sí es
y existe una arista a->b entonces dicha arista se tendra que eliminar
*/

int n,m;
vector<int> pre,order;
vector<vector<int>> graph,graphaux;

bool BFS() {
    bool ok = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int i=1;i<=n;i++) {
            if (graph[node][i] <= 0) continue;
            if (i == n) ok = 1;
            if (pre[i] == -1) {
                pre[i] = node;
                q.push(i);
            }
        }
    }
    return ok;
}

int main() {
    int Mflow = 0;
    scanf("%d%d",&n,&m);
    pre = vector<int>(n+1,-1);
    graphaux = graph = vector<vector<int>>(n+1,vector<int>(n+1));
    vector<bool> reach(n+1);
    vector<pair<int,int>> edge;
    while (m--) {
        int a,b;
        scanf("%d%d",&a,&b);
        graphaux[a][b]++;
        graphaux[b][a]++;
        graph[a][b]++;
        graph[b][a]++;
    }
    while (BFS()) {
        int aux = n,e1,e2,mo = 1e9;
        Mflow++;
        while (aux != 1) {
            graph[pre[aux]][aux] = 0;
            aux = pre[aux];
        }
        fill(pre.begin(),pre.end(),-1);
    }
    queue<int> q;
    q.push(1);
    reach[1] = 1;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int i=1;i<=n;i++) {
            if (graph[node][i] <= 0) continue;
            if (!reach[i]) {
                reach[i] = 1;
                q.push(i);
            }
        }
    }
    for (int i=1;i<=n;i++) {
        if (!reach[i]) {
            for (int j=1;j<=n;j++) {
                if (graphaux[j][i] != 0 && reach[j]) {
                    edge.push_back(j < i ? make_pair(j,i) : make_pair(i,j));
                }
            }
        }
    }
    printf("%d\n",Mflow);
    for (int i=0;i<edge.size();i++) {
        printf("%d %d\n",edge[i].first,edge[i].second);
    }
    return 0;
}
