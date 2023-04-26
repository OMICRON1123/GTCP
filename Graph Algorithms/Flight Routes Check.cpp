#include <bits/stdc++.h>
using namespace std;

/*
Se hace un DFS normal y otro DFS con la dirección de las aristas cambiadas desde el mismo punto.
Si se puede llegar desde cualquier nodo a cualquier nodo entonces ambos
DFS deben cubrir todos los nodos del grafo, si no los cubren entonces la
respuesta es NO.
*/

vector<bool> vis1,vis2;
vector<vector<int>> graph1,graph2;

void DFS1(int node) {
    if (vis1[node]) return;
    vis1[node] = 1;
    for (int i=0;i<graph1[node].size();i++) {
        DFS1(graph1[node][i]);
    }
}

void DFS2(int node) {
    if (vis2[node]) return;
    vis2[node] = 1;
    for (int i=0;i<graph2[node].size();i++) {
        DFS2(graph2[node][i]);
    }
}

int main() {
    bool ok = 1;
    int n,m,ans1,ans2;
    scanf("%d%d",&n,&m);
    vis1 = vis2 = vector<bool>(n+1);
    graph1 = graph2 = vector<vector<int>>(n+1);
    while (m--) {
        int a,b;
        scanf("%d%d",&a,&b);
        graph1[a].push_back(b);
        graph2[b].push_back(a);
    }
    DFS1(1);
    DFS2(1);
    for (int i=1;i<=n;i++) {
        if (!vis1[i]) {
            ok = 0;
            ans1 = 1;
            ans2 = i;
            break;
        }
    }
    if (ok) {
        for (int i=1;i<=n;i++) {
            if (!vis2[i]) {
                ok = 0;
                ans1 = i;
                ans2 = 1;
                break;
            }
        }
    }
    if (ok) printf("YES\n");
    else printf("NO\n%d %d\n",ans1,ans2);
}
