#include <bits/stdc++.h>
using namespace std;

/*
Usar programación dinámica (top down), en este caso la distancia mayor a un nodo
es la mayor de las distancias a los nodos que están conectados con él más uno
*/

vector<bool> calc;
vector<int> cities,pre,cycle;
vector<vector<int>> graph;

int dp(int node) {
    if (calc[node]) return cities[node];
    for (int i=0;i<graph[node].size();i++) {
        if (dp(graph[node][i]) != -1 && dp(graph[node][i])+1 > cities[node]) {
            cities[node] = dp(graph[node][i])+1;
            pre[node] = graph[node][i];
        }
    }
    calc[node] = 1;
    return cities[node];
}

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    calc = vector<bool>(n+1);
    cities = pre = vector<int>(n+1,-1);
    graph = vector<vector<int>>(n+1);
    while (m--) {
        int a,b;
        scanf("%d%d",&a,&b);
        graph[b].push_back(a);
    }
    cities[1] = 1;
    calc[1] = 1;
    cities[n] = dp(n);
    if (cities[n] != -1) {
        printf("%d\n",cities[n]);
        int idx = n;
        while (idx != 1) {
            cycle.push_back(idx);
            idx = pre[idx];
        }
        cycle.push_back(1);
        for (int i=cycle.size()-1;i>0;i--) printf("%d ",cycle[i]);
        printf("%d",cycle[0]);
    }
    else {
        printf("IMPOSSIBLE\n");
    }
}
