#include <bits/stdc++.h>
using namespace std;

/*
Usar un algoritmo de flujo máximo y luego hallar los paths usados por este algoritmo.
*/

int n,m;
vector<int> pre;
vector<vector<int>> graph;

bool BFS() {
    bool ok = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int i=1;i<=n;i++) {
            if (graph[node][i] <= 0) continue;
            if (i == n) ok = 1;
            if (pre[i] == -1) {
                pre[i] = node;
                q.push(i);
            }
        }
    }
    return ok;
}

int main() {
    int Nflow = 0;
    scanf("%d%d",&n,&m);
    pre = vector<int>(n+1,-1);
    graph = vector<vector<int>>(n+1,vector<int>(n+1));
    while (m--) {
        int a,b;
        scanf("%d%d",&a,&b);
        graph[a][b] = 1;
    }
    vector<vector<int>> graphaux = graph;
    while(BFS()) {
        int aux = n;
        Nflow++;
        while (aux != 1) {
            graph[pre[aux]][aux]--;
            graph[aux][pre[aux]]++;
            aux = pre[aux];
        }
        fill(pre.begin(),pre.end(),-1);
    }
    vector<vector<int>> ans;
    for (int i=2;i<=n;i++) {
        if (graph[1][i] == 0 && graphaux[1][i] != 0) {
            int aux = i;
            vector<int> nans(1,1);
            while (aux != n) {
                nans.push_back(aux);
                for (int j=1;j<=n;j++) {
                    if (graph[aux][j] == 0 && graphaux[aux][j] != 0) {
                        graph[aux][j] = 1;
                        aux = j;
                        break;
                    }
                }
            }
            nans.push_back(n);
            ans.push_back(nans);
        }
    }
    printf("%d\n",Nflow);
    for (int i=0;i<ans.size();i++) {
        printf("%d\n",ans[i].size());
        for (int j=0;j<ans[i].size();j++) {
            printf(j == ans[i].size()-1 ? "%d\n":"%d ",ans[i][j]);
        }
    }
    return 0;
}
