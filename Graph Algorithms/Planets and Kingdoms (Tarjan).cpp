#include <bits/stdc++.h>
using namespace std;

//Tarjan's Algorithm

int t = 1,id = 1;
vector<bool> inStack,visited;
vector<int> disc,low,kingdom;
vector<vector<int>> graph;
stack<int> order;

void DFS(int node) {
    inStack[node] = visited[node] = 1;
    disc[node] = low[node] = t++;
    order.push(node);
    for (int i=0;i<graph[node].size();i++) {
        if (inStack[graph[node][i]]) {
            low[node] = min(low[node],disc[graph[node][i]]);
        }
        else if(!visited[graph[node][i]]){
            DFS(graph[node][i]);
            low[node] = min(low[node],low[graph[node][i]]);
        }
    }
    if (low[node] == disc[node]) {
        int aux = -1;
        while (aux != node) {
            aux = order.top();
            order.pop();
            inStack[aux] = 0;
            kingdom[aux] = id;
        }
        id++;
    }
}

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    inStack = visited = vector<bool>(n+1);
    kingdom = disc = low = vector<int>(n+1);
    graph = vector<vector<int>>(n+1);
    while (m--) {
        int a,b;
        scanf("%d%d",&a,&b);
        graph[a].push_back(b);
    }
    for (int i=1;i<=n;i++) {
        if (!visited[i]) DFS(i);
    }
    printf("%d\n",id-1);
    for (int i=1;i<=n;i++) printf("%d ",kingdom[i]);
    return 0;
}
