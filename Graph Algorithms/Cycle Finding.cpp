#include <bits/stdc++.h>
using namespace std;

/*
Este ejercicio se puede hacer con DFS, guardando cuánto es la suma hasta
algún nodo, cuando se llega nuevamente al nodo, se vuelve a revisar si
la suma actual menos la anterior que estaba almacenada en ese nodo es negativa.
Si es así, es porque se encontró un ciclo negativo entonces se procede
a guardarlo, el DFS se tiene que lanzar desde cada nodo para comprobar
todas las opciones posibles.
*/

const int oo = 2e9;
const long long ooll = 1e17;

bool ok,print;
vector<bool> visited;
vector<int> cycle;
vector<long long> sums;
vector<vector<pair<int,int>>> graph;

void DFS(int node,long long sum) {
    if (visited[node] && sum - sums[node] < 0) {
        ok = print = 1;
        cycle.push_back(node);
        return;
    }
    if (visited[node]) return;
    visited[node] = 1;
    sums[node] = sum;
    for (int i=0;i<graph[node].size();i++) {
        if (ok) break;
        DFS(graph[node][i].first,sum+graph[node][i].second);
    }
    if (print) {
        cycle.push_back(node);
        if (node == cycle[0]) print = 0;
    }
    sums[node] = -ooll;
}

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    visited = vector<bool>(n+1);
    sums =  vector<long long>(n+1,-ooll);
    graph = vector<vector<pair<int,int>>>(n+1);
    vector<set<pair<int,int>>> graphaux(n+1);
    while (m--) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if (graphaux[a].empty()) {
            graphaux[a].insert({b,c});
        }
        else {
            auto it = graphaux[a].lower_bound({b,-oo});
            if (it->first != b)  {
                graphaux[a].insert({b,c});
            }
            else if (it->second > c) {
                graphaux[a].erase(it);
                graphaux[a].insert({b,c});
            }
        }
    }
    for (int i=1;i<=n;i++) {
        graph[i].assign(graphaux[i].begin(),graphaux[i].end());
    }
    for (int i=1;i<=n;i++) {
        if (ok) break;
        DFS(i,0);
        fill(visited.begin(),visited.end(),0);
    }
    if (ok) {
        printf("YES\n");
        printf("%d",cycle[0]);
        for (int i=cycle.size()-2;i>=0;i--) {
            printf(" %d",cycle[i]);
        }
    }
    else {
        printf("NO\n");
    }
    return 0;
}
