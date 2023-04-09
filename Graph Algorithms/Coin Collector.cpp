#include <bits/stdc++.h>
using namespace std;

/*
Para este ejercicio se utilizó el algoritmo de Tarján para encontrar los componentes
fuertemente conectados, estos componentes se trataron como nodos para un nuevo grafo
Este nuevo grafo cumple con la condición de ser un ADG Grafo Dirigido Acíclico y por
ende se puede calcular fácilmente el valor máximo mediante una programación dinámica
en el que para todo componente se calcula su valor máximo con base a los componentes
a los cuales se puede llegar desde el componente actual.
*/

int id = 1,t = 1;
vector<bool> visited,inStack;
vector<int> k,low,disc,comp;
vector<long long> memo,nk;
vector<vector<int>> graph,ngraph;
stack<int> order;

void DFS(int node) {
    inStack[node] = visited[node] = 1;
    low[node] = disc[node] = t++;
    order.push(node);
    for (int i=0;i<graph[node].size();i++) {
        if (inStack[graph[node][i]]) {
            low[node] = min(low[node],disc[graph[node][i]]);
        }
        else if (!visited[graph[node][i]]) {
            DFS(graph[node][i]);
            low[node] = min(low[node],low[graph[node][i]]);
        }
    }
    if (low[node] == disc[node]) {
        int aux = -1;
        while (aux != node) {
            aux = order.top();
            order.pop();
            comp[aux] = id;
            inStack[aux] = 0;
        }
        id++;
    }
}

long long dp(int node) {
    if (visited[node]) return memo[node];
    visited[node] = 1;
    memo[node] = nk[node];
    for (int i=0;i<ngraph[node].size();i++) {
        dp(ngraph[node][i]);
        memo[node] = max(memo[node],nk[node]+memo[ngraph[node][i]]);
    }
    return memo[node];
}

int main() {
    int n,m;
    long long ans=-1;
    scanf("%d%d",&n,&m);
    visited = inStack = vector<bool>(n+1);
    comp = disc = low = k = vector<int>(n+1);
    graph = vector<vector<int>>(n+1);
    for (int i=1;i<=n;i++) {
        scanf("%d",&k[i]);
    }
    while (m--) {
        int a,b;
        scanf("%d%d",&a,&b);
        graph[a].push_back(b);
    }
    for (int i=1;i<=n;i++) {
        if (!visited[i]) DFS(i);
    }
    visited = vector<bool>(id);
    memo = nk = vector<long long>(id);
    ngraph = vector<vector<int>>(id);
    for (int i=1;i<=n;i++) {
        nk[comp[i]] += k[i];
        for (int j=0;j<graph[i].size();j++) {
            if (comp[i] != comp[graph[i][j]]) {
                ngraph[comp[i]].push_back(comp[graph[i][j]]);
            }
        }
    }
    k.clear();
    graph.clear();
    for (int i=1;i<id;i++) {
        memo[i] = dp(i);
    }
    for (int i=1;i<id;i++) {
        ans = max(ans,memo[i]);
    }
    printf("%lld\n",ans);
    return 0;
}
