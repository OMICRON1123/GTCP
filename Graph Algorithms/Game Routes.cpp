#include <bits/stdc++.h>
using namespace std;

/*
Nuevamente, usar programación dinámica (top down) la forma de llegar a un nodo es
la suma de la cantidad de formas que se puede llegar a cada uno de los nodos que
están conectados con este.
*/

long long MOD = 1e9+7;

vector<bool> calc;
vector<long long> ways;
vector<vector<int>> graph;

long long dp(int node) {
    if (calc[node]) return ways[node];
    for (int i=0;i<graph[node].size();i++) {
        ways[node] += dp(graph[node][i]);
        ways[node] %= MOD;
    }
    calc[node] = 1;
    return ways[node];
}

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    calc = vector<bool>(n+1);
    ways = vector<long long>(n+1,0);
    graph = vector<vector<int>>(n+1);
    while(m--) {
        int a,b;
        scanf("%d%d",&a,&b);
        graph[b].push_back(a);
    }
    ways[1] = 1;
    calc[1] = 1;
    ways[n] = dp(n);
    printf("%lld\n",ways[n]);
}
