#include <bits/stdc++.h>
using namespace std;

/*
Se calcula cu�l es la distancia de cualquier nodo al �ltimo nodo del
ciclo al que est� unido, si el nodo que se est� buscando se encuentra
en el mismo camino al ciclo que este sencillamente se puede encontrar
con la funci�n succ y con la cantidad de pasos determinados.
Si no es as�, se va al principio del ciclo y se busca desde all�,
finalmente si no se encuentra es q no se puede llegar.
*/

vector<bool> visited;
vector<int> len;
vector<vector<int>> t;

void DFS(int node) {
    if (visited[node]) return;
    visited[node] = 1;
    DFS(t[0][node]);
    len[node] = len[t[0][node]]+1;
}

int succ(int node, int dis) {
    if (dis <= 0) return node;
    for (int i=0;i<30;i++) {
        if ((1<<i)&dis) {
            node = t[i][node];
        }
    }
    return node;
}

int main() {
    int n,q,x;
    scanf("%d%d",&n,&q);
    visited = vector<bool>(n+1);
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
        if (!visited[i]) DFS(i);
    }
    while(q--) {
        int a,b;
        scanf("%d%d",&a,&b);
        int nodea = succ(a,len[a]);
        if (succ(a,len[a]-len[b]) == b) {
            printf("%d\n",len[a]-len[b]);
        }
        else if (succ(nodea,len[nodea]-len[b]) == b) {
            printf("%d\n",len[a]+len[nodea]-len[b]);
        }
        else {
            printf("-1\n");
        }
    }
    return 0;
}
