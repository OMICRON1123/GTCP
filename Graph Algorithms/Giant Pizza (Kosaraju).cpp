#include <bits/stdc++.h>
using namespace std;

/*
Usar las implicaciones como aristas del grafo, si x implica ~x y ~x implica x entonces
el problema no tiene solución. Dividir el grafo en componentes fuertemente conectados
si x y ~x están en el mismo componente es porque el problema no tiene solución
*/

int n,m,id=1;
vector<bool> visited,ans;
vector<int> comp;
vector<vector<int>> graph1,graph2;
stack<int> S;

int Num(int node) {return node+m;}
int Node(int num) {return num-m;}

void DFS1(int num) {
    if (visited[num]) return;
    visited[num] = 1;
    for (int i=0;i<graph1[num].size();i++) {
        DFS1(graph1[num][i]);
    }
    S.push(num);
}

void DFS2(int num) {
    if (visited[num]) return;
    visited[num] = 1;
    comp[num] = id;
    for (int i=0;i<graph2[num].size();i++) {
        DFS2(graph2[num][i]);
    }
}

int main() {
    bool found = 1;
    scanf("%d%d",&n,&m);
    ans = visited = vector<bool>(2*m+1);
    comp = vector<int>(2*m+1);
    graph1 = graph2 = vector<vector<int>>(2*m+1);
    for (int i=0;i<n;i++) {
        string s;
        int num,a,b;
        cin>>s;
        scanf("%d",&num);
        a = s.compare("+") == 0 ? num : -num;
        cin>>s;
        scanf("%d",&num);
        b = s.compare("+") == 0 ? num : -num;
        graph1[Num(-a)].push_back(Num(b));
        graph1[Num(-b)].push_back(Num(a));
        graph2[Num(b)].push_back(Num(-a));
        graph2[Num(a)].push_back(Num(-b));
    }
    for (int i=0;i<=2*m;i++) {
        if (i == m) continue;
        if (!visited[i]) DFS1(i);
    }
    fill(visited.begin(),visited.end(),0);
    while (!S.empty()) {
        int aux = S.top();
        S.pop();
        if (!visited[aux]) {
            DFS2(aux);
            id++;
        }
    }
    for (int i=1;i<=m;i++) {
        if (comp[Num(i)] == comp[Num(-i)]) {
            found = 0;
            break;
        }
        if (comp[Num(i)] > comp[Num(-i)]) {
            ans[i] = 1;
        }
        else {
            ans[i] = 0;
        }
    }
    if (!found) printf("IMPOSSIBLE\n");
    else {
        for (int i=1;i<=m;i++) {
            printf(ans[i] ? "+" : "-");
            printf(i == m ? "\n" : " ");
        }
    }
    return 0;
}
