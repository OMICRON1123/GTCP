#include <bits/stdc++.h>
using namespace std;

//Kosaraju's algorithm

int id = 1;
vector<bool> visited1,visited2;
vector<int> kingdom;
vector<vector<int>> graph1,graph2;
stack<int> order;

void DFS1(int node) {
    if (visited1[node]) return;
    visited1[node] = 1;
    for (int i=0;i<graph1[node].size();i++) {
        DFS1(graph1[node][i]);
    }
    order.push(node);
}

void DFS2(int node) {
    if (visited2[node]) return;
    visited2[node] = 1;
    for (int i=0;i<graph2[node].size();i++) {
        DFS2(graph2[node][i]);
    }
    kingdom[node] = id;
}

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    visited1 = visited2 = vector<bool>(n+1);
    kingdom = vector<int>(n+1);
    graph1 = graph2 = vector<vector<int>>(n+1);
    while(m--) {
        int a,b;
        scanf("%d%d",&a,&b);
        graph1[a].push_back(b);
        graph2[b].push_back(a);
    }
    for (int i=1;i<=n;i++) {
        if (!visited1[i]) {
            DFS1(i);
        }
    }
    while (!order.empty()) {
        if (!visited2[order.top()]) {
            DFS2(order.top());
            id++;
        }
        order.pop();
    }
    printf("%d\n",id-1);
    for (int i=1;i<=n;i++) {
        printf("%d ",kingdom[i]);
    }
    return 0;
}
