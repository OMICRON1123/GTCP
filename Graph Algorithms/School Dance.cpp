#include <bits/stdc++.h>
using namespace std;

/*
Usar un algoritmo para calcular el maximum flow de un grafo bipartito. Mejor expliación
en Guide To Competitive Programming.
*/

int n,m,k;
vector<int> pre;
vector<pair<int,int>> couple;
vector<vector<int>> graph;

bool BFS() {
    bool ok = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int i=0;i<graph[node].size();i++) {
            if (graph[node][i] <= 0) continue;
            if (i == n+m+1) ok = 1;
            if (pre[i] == -1) {
                q.push(i);
                pre[i] = node;
            }
        }
    }
    return ok;
}

int main() {
    int Nflow = 0;
    scanf("%d%d%d",&n,&m,&k);
    pre = vector<int>(n+m+2,-1);
    graph = vector<vector<int>>(n+m+2,vector<int>(n+m+2));
    while (k--) {
        int a,b;
        scanf("%d%d",&a,&b);
        graph[0][a] = 1;
        graph[a][b+n] = 1;
        graph[b+n][n+m+1] = 1;
    }
    while (BFS()) {
        int aux = n+m+1;
        Nflow++;
        while (aux != 0) {
            graph[pre[aux]][aux] = 0;
            graph[aux][pre[aux]] = 1;
            aux = pre[aux];
        }
        fill(pre.begin(),pre.end(),-1);
    }
    for (int i=1;i<=n;i++) {
        for (int j=n+1;j<=n+m;j++) {
            if (graph[i][j] == 0 && graph[j][i] == 1) {
                couple.push_back({i,j-n});
            }
        }
    }
    printf("%d\n",Nflow);
    for (int i=0;i<couple.size();i++) {
        printf("%d %d\n",couple[i].first,couple[i].second);
    }
    return 0;
}
