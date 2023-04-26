#include <bits/stdc++.h>
using namespace std;

/*
Calcular len para cada uno de los nodos con un dfs teniendo en cuenta
que los ciclos pueden llegar a afectar el resultado, si se encuentra
un nodo que hace parte de un ciclo se  tiene que examinar cuál es la
longitud de este ciclo para poder calcular len de los nodos anteriores

*/

void DFS(int);
int succ(int,int);

bool cycle;
int val,currnode;
vector<bool> visited,complete,part;
vector<int> len;
vector<vector<int>> t;

void DFS(int node) {
    if (complete[node] && part[node]) {
        val = len[succ(node,len[node])];
        return;
    }
    if (visited[node] && !complete[node]) {
        cycle = 1;
        currnode = node;
        return;
    }
    visited[node] = 1;
    DFS(t[0][node]);
    if (cycle) {
        part[node] = 1;
    }
    if (cycle && node == currnode) {
        cycle = 0;
    }
    if (val == -1) {
        len[node] = len[t[0][node]]+1;
    }
    else {
        len[node] = val+1;
        val = -1;
    }
    complete[node] = 1;
}

int succ(int node,int k) {
    if (k <= 0) return node;
    int i=0;
    while (k != 0) {
        if (k&1) node = t[i][node];
        k >>= 1;
        i++;
    }
    return node;
}

int main() {
    int n;
    scanf("%d",&n);
    part = complete = visited = vector<bool>(n+1);
    len = vector<int>(n+1);
    t = vector<vector<int>>(30,vector<int>(n+1));
    for (int i=1;i<=n;i++) {
        scanf("%d",&t[0][i]);
    }
    for (int i=1;i<30;i++) {
        for (int j=1;j<=n;j++) {
            t[i][j] = t[i-1][t[i-1][j]];
        }
    }
    for (int i=1;i<=n;i++) {
        val = -1;
        if (!visited[i]) DFS(i);
    }
    for (int i=1;i<=n;i++) {
        int aux = succ(i,len[i]);
        if (succ(aux,len[aux]-len[i]) == i)
            printf("%d\n",len[aux]);
        else
            printf("%d\n",len[i]);
    }
    return 0;
}
