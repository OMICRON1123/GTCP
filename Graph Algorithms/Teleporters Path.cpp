#include <bits/stdc++.h>
using namespace std;

/*
Encontrar caminos eulerianos con ayuda del algoritmo de Hierholzer. Tener en cuenta
que este solo funciona para circuitos, entonces añadir la arista faltante para
completar el circuito y una vez se tiene el circuito se busca en qué momento se usó
dicha arista y la nueva respuesta será un arreglo que comience en la posición en la
que se usó dicha arista y recorra todo el arreglo de manera cíclica desde esa posición
*/

int main() {
    bool ok = 1;
    int n,m;
    stack<int> s;
    scanf("%d%d",&n,&m);
    vector<int> indeg(n+1),outdeg(n+1),ans;
    vector<multiset<int>> graph(n+1);
    while (m--) {
        int a,b;
        scanf("%d%d",&a,&b);
        graph[a].insert(b);
        outdeg[a]++;
        indeg[b]++;
    }
    if (outdeg[1] != indeg[1] + 1 || indeg[n] != outdeg[n] + 1) {
        ok = 0;
    }
    else {
        graph[n].insert(1);
    }
    for (int i=2;i<n;i++) {
        if (outdeg[i] != indeg[i]) {
            ok = 0;
        }
    }
    s.push(1);
    while (!s.empty()) {
        int aux = s.top();
        if (graph[aux].empty()) {
            s.pop();
            ans.push_back(aux);
        }
        else {
            s.push(*graph[aux].begin());
            graph[aux].erase(graph[aux].begin());
        }
    }
    for (int i=1;i<=n;i++) {
        if (!graph[i].empty()) {
            ok = 0;
            break;
        }
    }
    if (!ok) {
        printf("IMPOSSIBLE\n");
    }
    else {
        reverse(ans.begin(),ans.end());
        vector<int> ans2;
        for (int i=0;i<ans.size()-1;i++) {
            if (ans[i] == n && ans[i+1] == 1) {
                for (int j=i+1;j<ans.size();j++) ans2.push_back(ans[j]);
                for (int j=0;j<=i;j++) ans2.push_back(ans[j]);
                break;
            }
        }
        printf("%d",ans2[0]);
        for (int i=1;i<ans2.size();i++) {
            if (ans2[i] != ans2[i-1]) printf(" %d",ans2[i]);
        }
    }
    return 0;
}
