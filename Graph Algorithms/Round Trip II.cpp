#include <bits/stdc++.h>
using namespace std;

/*
Se hace un DFS pero guardando los nodos por los que ha pasado específicamente
ese DFS, si un nodo pertenece al ciclo se encuentra el ciclo obligatoriamente.
Los nodos que se han visitado en cualquier se marcan como ocupados pero
se tiene un  conjunto que es el que indica cómo es el recorrido actual,
que un nodo se marque como ocupado no indica que pertenezca al recorrido actual.
Si un nodo que se visita está en el recorrido actual quiere decir que ese nodo
forma un ciclo y entonces se imprimen todos los nodos pertenecientes a ese ciclo
usando la función recursiva.
*/

bool found,print;
vector<bool> visited,auxvisited;
vector<int> cycle;
vector<vector<int>> graph;
set<int> nodes;

void DFS(int node) {
    if (nodes.find(node) != nodes.end()) {
        found = print = 1;
        cycle.push_back(node);
        return;
    }
    if (visited[node]) return;
    visited[node] = 1;
    nodes.insert(node);
    for (int i=0;i<graph[node].size();i++) {
        if (found) break;
        DFS(graph[node][i]);
    }
    if (print) {
        cycle.push_back(node);
        if (node == cycle[0]) {
            print = 0;
        }
    }
    nodes.erase(nodes.find(node));
}

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    vector<int> pre(n+1,-1);
    visited = vector<bool>(n+1);
    auxvisited = vector<bool>(n+1);
    graph = vector<vector<int>>(n+1);
    while (m--) {
        int a,b;
        scanf("%d%d",&a,&b);
        graph[a].push_back(b);
    }
    for (int i=1;i<=n;i++) {
        if (!visited[i]) {
            DFS(i);
        }
    }
    if (cycle.size()) {
        printf("%d\n%d",cycle.size(),cycle[cycle.size()-1]);
        for (int i=cycle.size()-2;i>=0;i--) {
            printf(" %d",cycle[i]);
        }
    }
    else {
        printf("IMPOSSIBLE\n");
    }
    return 0;
}
