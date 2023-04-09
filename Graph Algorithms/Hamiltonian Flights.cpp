#include <bits/stdc++.h>
using namespace std;

/*
Se aplica programación dinámica para poder hallar la cantidad de maneras. Se hace
un dp(S,x) donde S es el subconjunto de nodos y x es el nodo en el que termina el
recorrido del subconjunto. Entonces dp(S,x) = sum(dp(S\{y},y)) donde y es un nodo
que pertenece a S y hay una arista que va del nodo y al nodo x.
*/

const int MOD = 1e9+7;

vector<vector<int>> graph;
vector<vector<int>> memo;

int dp(int subset,int last) {
    if (memo[subset][last] != -1) return memo[subset][last];
    if (((1<<last)&subset) == 0) return memo[subset][last] = 0;
    memo[subset][last] = 0;
    for (int i=0;i<graph[last].size();i++) {
        int aux = dp(subset&(~(1<<last)),graph[last][i]);
        memo[subset][last] += aux;
        memo[subset][last] = memo[subset][last] > MOD ? memo[subset][last] - MOD : memo[subset][last];
    }
    return memo[subset][last];
}

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    graph = vector<vector<int>>(n);
    memo = vector<vector<int>>((1<<n),vector<int>(n,-1));
    memo[0][0] = 0;
    memo[1][0] = 1;
    while (m--) {
        int a,b;
        scanf("%d%d",&a,&b);
        a--;
        b--;
        graph[b].push_back(a);
    }
    int res = dp((1<<n)-1,n-1);
    printf("%d\n",res);
    return 0;
}
