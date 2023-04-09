#include <bits/stdc++.h>
using namespace std;

/*
Usar el algoritmo para encontrar ciclos eulerianos
*/

int id = 1,t = 1;
vector<int> deg,ans;
vector<set<int>> graph;

void euler(int node) {
    while (!graph[node].empty()) {
        int aux = *graph[node].begin();
        graph[node].erase(graph[node].begin());
        graph[aux].erase(graph[aux].find(node));
        euler(aux);
    }
    ans.push_back(node);
}

int main() {
    bool ok = 1;
    int n,m;
    scanf("%d%d",&n,&m);
    deg = vector<int>(n+1);
    graph = vector<set<int>>(n+1);
    while (m--) {
        int a,b;
        scanf("%d%d",&a,&b);
        graph[a].insert(b);
        graph[b].insert(a);
        deg[a]++;
        deg[b]++;
    }
    euler(1);
    for (int i=1;i<=n;i++) {
        if (deg[i]%2 != 0 || !graph[i].empty()) {
            ok = 0;
            break;
        }
    }
    if (!ok) printf("IMPOSSIBLE\n");
    else {
        for (int i=0;i<ans.size();i++) {
            printf(i == ans.size()-1 ? "%d\n" : "%d ",ans[i]);
        }
    }
    return 0;
}
