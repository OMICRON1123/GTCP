#include <bits/stdc++.h>
using namespace std;

//Usando algoritmo de tarjan

int n,m,id=1,t=1;
vector<bool> visited,ans,inStack;
vector<int> disc,low,comp;
vector<vector<int>> graph;
stack<int> order;

void DFS(int node) {
    visited[node] = 1;
    low[node] = disc[node] = t++;
    order.push(node);
    inStack[node] = 1;
    for (int i=0;i<graph[node].size();i++) {
        if(inStack[graph[node][i]]) {
            low[node] = min(low[node],disc[graph[node][i]]);
        }
        else if (!visited[graph[node][i]]) {
            DFS(graph[node][i]);
            low[node] = min(low[node],low[graph[node][i]]);
        }
    }
    if (low[node] == disc[node]) {
        int aux = -1;
        while (aux != node) {
            aux = order.top();
            order.pop();
            comp[aux] = id;
            inStack[aux] = 0;
        }
        id++;
    }
}

int main() {
    bool ok = 1;
    scanf("%d%d",&n,&m);
    ans = vector<bool>(m+1);
    inStack = visited = vector<bool>(2*m+1);
    disc = low = comp = vector<int>(2*m+1);
    graph = vector<vector<int>>(2*m+1);
    while (n--) {
        string s;
        int num,a,b;
        cin>>s;
        scanf("%d",&num);
        a = s.compare("+") == 0 ? num : -num;
        cin>>s;
        scanf("%d",&num);
        b = s.compare("+") == 0 ? num : -num;
        graph[m-a].push_back(b+m);
        graph[m-b].push_back(a+m);
    }
    for (int i=0;i<=2*m;i++) {
        if (!visited[i]) DFS(i);
    }
    for (int i=1;i<=m;i++) {
        if (comp[i+m] == comp[-i+m]) {
            ok = 0;
            break;
        }
        if (comp[i+m] > comp[-i+m]) {
            ans[i] = 0;
        }
        else {
            ans[i] = 1;
        }
    }
    if (!ok) printf("IMPOSSIBLE\n");
    else {
        for (int i=1;i<=m;i++) {
            printf(ans[i] ? "+" : "-");
            printf(i == m ? "\n" : " ");
        }
    }
    return 0;
}
