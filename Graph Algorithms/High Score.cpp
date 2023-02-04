#include <bits/stdc++.h>
using namespace std;

/*
Para este ejercicio se aplica el algoritmo de Bellman-Ford, hasta la n-sima iteración
para ver si hay, y si los hay, y se cumple que a partir del 1 se puede llegar al ciclo
y a partir del ciclo de puede llegar a n entonces  la respuesta es -1.
Si no, es la respuesta que diga el algoritmo.
*/

void DFS(int);
bool DFS(int,int);

const long long oo = 1e18;


bool sol = 1;
int n,m;
vector<bool> visited1,visited2;
vector<vector<int>> graph;

void DFS(int node) {
    if (node == n) {
        sol = 0;
        return;
    }
    if (visited1[node]) return;
    visited1[node] = 1;
    for (int i=0;i<graph[node].size();i++){
        if (!sol) break;
        DFS(graph[node][i]);
    }
}

bool DFS(int node,int res) {
    if (node == res) return true;
    if (visited2[node]) return false;
    visited2[node] = 1;
    bool ans = 0;
    for (int i=0;i<graph[node].size();i++) {
        if (ans) break;
        ans |= DFS(graph[node][i],res);
    }
    return ans;
}

int main() {
    scanf("%d%d",&n,&m);
    visited1 = vector<bool>(n+1);
    visited2 = vector<bool>(n+1);
    graph = vector<vector<int>>(n+1);
    vector<long long> dist1(n+1,-oo),auxdist;
    vector<tuple<int,int,int>> edges(m);
    for (int i=0;i<m;i++) {
        int a,b,x;
        scanf("%d%d%d",&a,&b,&x);
        edges[i] = make_tuple(a,b,x);
        graph[a].push_back(b);
    }
    dist1[1] = 0;
    for (int i=0;i<n+1;i++) {
        for (int j=0;j<m;j++) {
            int a,b,x;
            tie(a,b,x) = edges[j];
            dist1[b] = max(dist1[b],dist1[a]+x);
        }
        if (i == n-1) {
            auxdist = dist1;
        }
    }
    for (int i=1;i<=n;i++) {
        if (!sol) break;
        if (auxdist[i] != dist1[i] && DFS(1,i)) DFS(i);
        fill(visited1.begin(),visited1.end(),0);
        fill(visited2.begin(),visited2.end(),0);
    }
    if (sol) {
        printf("%lld\n",dist1[n]);
    }
    else {
        printf("-1\n");
    }
    return 0;
}
