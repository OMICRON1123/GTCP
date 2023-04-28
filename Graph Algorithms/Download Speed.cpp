#include <bits/stdc++.h>
using namespace std;

/*
Aplicar algún algoritmo que permita hallar el maximum flow de un
grafo.
*/

int n,m;
vector<int> pre;
vector<vector<long long>> graph;

bool BFS() {
    bool ok = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int i=1;i<graph[node].size();i++) {
            if (graph[node][i] <= 0) continue;
            if (pre[i] == -1) {
                pre[i] = node;
                q.push(i);
            }
            if (i == n) ok = 1;
        }
    }
    return ok;
}

int main() {
    long long Mflow = 0;
    scanf("%d%d",&n,&m);
    pre = vector<int>(n+1,-1);
    graph = vector<vector<long long>>(n+1,vector<long long>(n+1));
    while (m--) {
        int a,b;
        long long c;
        scanf("%d%d%lld",&a,&b,&c);
        graph[a][b] += c;
    }
    while (BFS()) {
        int aux = n;
        long long flow = 1e18;
        while (aux != 1) {
            flow = min(flow,(long long)graph[pre[aux]][aux]);
            aux = pre[aux];
        }
        aux = n;
        while (aux != 1) {
            graph[pre[aux]][aux] -= flow;
            graph[aux][pre[aux]] += flow;
            aux = pre[aux];
        }
        Mflow += flow;
        fill(pre.begin(),pre.end(),-1);
    }
    printf("%lld\n",Mflow);
    return 0;
}
