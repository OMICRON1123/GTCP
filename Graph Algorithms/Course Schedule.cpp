#include <bits/stdc++.h>
using namespace std;

bool found;
vector<bool> visited;
vector<vector<int>> graph;
set<int> nodes;
map<int,int> before;

void DFS(int node,int bef,int beg) {
    //printf("node: %d\n",node);
    if (nodes.find(node) != nodes.end()) {
        found = 1;
        return;
    }
    if (visited[node]) {
        before[beg] = before[node];
        before[node] = bef;
        return;
    }
    visited[node] = 1;
    before[node] = bef;
    nodes.insert(node);
    /*for (int i=0;i<path.size();i++) {
        if (print[i]) {
            printf("%d ",path[i]);
        }
    }
    printf("\n");*/
    for (int i=0;i<graph[node].size();i++) {
        if (found) break;
        if (i == 0) {
            DFS(graph[node][i],node,beg);
        }
        else {
            DFS(graph[node][i],node,graph[node][i]);
        }
    }
    nodes.erase(nodes.find(node));
}

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    vector<int> pre(n+1,-1);
    visited = vector<bool>(n+1);
    graph = vector<vector<int>>(n+1);
    while (m--) {
        int a,b;
        scanf("%d%d",&a,&b);
        graph[a].push_back(b);
    }
    /*for (int i=1;i<=n;i++) {
        printf("%d: ",i);
        for (int j=0;j<graph[i].size();j++) {
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }*/
    for (int i=1;i<=n;i++) {
        if (!visited[i]) {
            //printf("DFS: %d\n",i);
            DFS(i,-1,i);
        }
    }
    if (found) {
        printf("IMPOSSIBLE\n");
    }
    else {
        vector<vector<int>> path;
        while (!before.empty()){
            int nodef = before.begin()->first;
            for (auto it=before.begin();it!=before.end();it++) {
                if (it->second == nodef) {
                    nodef = it->first;
                }
            }
            vector<int> npath;
            while (nodef != -1) {
                if (before.find(nodef) == before.end()) break;
                npath.push_back(nodef);
                int aux = nodef;
                nodef = before[nodef];
                before.erase(before.find(aux));
            }
            path.push_back(npath);
        }
        int cont = 0;
        for (int i=0;i<path.size();i++) {
            for (int j=path[i].size()-1;j>=0;j--) {
                printf(cont == n-1 ? "%d\n":"%d ",path[i][j]);
            }
        }
    }
    return 0;
}
