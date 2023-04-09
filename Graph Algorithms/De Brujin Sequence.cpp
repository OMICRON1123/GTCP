#include <bits/stdc++.h>
using namespace std;

/*
Para este ejercicio se construye un grafo en el que cada cadena posible se comunica
con las cadenas a las que puede pasar si se le añade un 1 o un 0 al final. Luego
se busca un recorrido que pase por todas las cadenas (nodos) sin repetir ninguno.
La cadena que se forma de dicho recorrido es la que tiene mínima cantidad posible.
*/

bool ok = 0;
set<int> nums;
vector<int> ans;
vector<vector<int>> graph;

void DFS(int node) {
    nums.erase(nums.find(node));
    ans.push_back((1&node));
    if (nums.empty()) {
        ok = 1;
        return;
    }
    for (int i=0;i<graph[node].size();i++) {
        if (ok) break;
        if (nums.find(graph[node][i]) != nums.end()) DFS(graph[node][i]);
    }
    if (!ok) {
        nums.insert(node);
        ans.pop_back();
    }
}

int main() {
    int n,node;
    scanf("%d",&n);
    int aux = (~(1<<n));
    graph = vector<vector<int>>(1<<n);
    for (int i=0;i<(1<<n);i++) {
        nums.insert(i);
        if (((i<<1)&aux) != i) graph[i].push_back((i<<1)&aux);
        if ((((i<<1)+1)&aux) != i) graph[i].push_back(((i<<1)+1)&aux);
    }
    for (int i=1;i<n;i++) ans.push_back(0);
    DFS(0);
    for (int i=0;i<ans.size();i++) printf("%d",ans[i]);
    return 0;
}
