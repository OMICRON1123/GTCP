#include <bits/stdc++.h>
using namespace std;

/*
Para este ejercicio es aplicar el algoritmo de Floyd-Warshall para hallar la mínima
distancia desde cualquier punto a cualquier punto.
*/

const long long oo = 1e18;

int main() {
    int n,m,q;
    scanf("%d%d%d",&n,&m,&q);
    vector<vector<long long>> graph(n+1,vector<long long>(n+1,oo));
    for (int i=1;i<=n;i++) {
        graph[i][i] = 0;
    }
    while (m--) {
        int a,b;
        long long c;
        scanf("%d%d%lld",&a,&b,&c);
        graph[a][b] = min(graph[a][b],c);
        graph[b][a] = min(graph[b][a],c);
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++){
            for (int k=1;k<=n;k++) {
                graph[j][k] = min(graph[j][k],graph[j][i]+graph[i][k]);
            }
        }
    }
    while (q--) {
        int a,b;
        scanf("%d%d",&a,&b);
        if (graph[a][b] == oo)
            printf("-1\n");
        else
            printf("%lld\n",graph[a][b]);
    }
    return 0;
}
