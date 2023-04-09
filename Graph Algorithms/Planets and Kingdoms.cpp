#include <bits/stdc++.h>
using namespace std;

/*
Si un nodo no tiene aristas entrantes o no tiene aristas salientes, entonces ese
nodo es un reino en sí mismo, luego si no tenía aristas entrantes, entonces
a todos los nodos a los que se comunique se les disminuye en 1 la cantidad de aristas
entrantes y se mira si su nuevo grado de aristas entrantes es 0, si es así entonces
también será un reino en sí mismo. Lo mismo aplica para un nodo que tiene 0 aristas
salientes, entonces los nodos que se comunican a este se disminuyen en 1 su cantidad
de aristas salientes y si comienzan a ser 0 también son reinos en sí mismos. Luego
de este proceso ya se optimizó bastante los casos que pueden llegar a dar TLE entonces
solo resta aplicar DFS desde cada nodo aún no determinado tanto con las aristas
normales como con las aristas cambiadas, y de esta manera se observa qué nodos pertenecen
a este reino.
*/

bool modify = 0;
int id = 1;
vector<int> indegree,outdegree,kingdom1,kingdom2;
vector<vector<int>>graph1,graph2;

void DFS1(int node) {
    if (kingdom1[node]) return;
    kingdom1[node] = id;
    if (modify)
        kingdom2[node] = 0;
    for (int i=0;i<graph1[node].size();i++) {
        DFS1(graph1[node][i]);
    }
}

void DFS2(int node) {
    if (kingdom2[node]) return;
    kingdom2[node] = id;
    if (modify)
        kingdom1[node] = 0;
    for (int i=0;i<graph2[node].size();i++) {
        DFS2(graph2[node][i]);
    }
}

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    set<int> nodesin,nodesout;
    for (int i=1;i<=n;i++) {
        nodesin.insert(i);
        nodesout.insert(i);
    }
    kingdom1=kingdom2=indegree=outdegree=vector<int>(n+1);
    graph1=graph2=vector<vector<int>>(n+1);
    while (m--) {
        int a,b;
        scanf("%d%d",&a,&b);
        graph1[a].push_back(b);
        graph2[b].push_back(a);
        indegree[b]++;
        outdegree[a]++;
        if (nodesin.find(b) != nodesin.end()) nodesin.erase(nodesin.find(b));
        if (nodesout.find(a) != nodesout.end()) nodesout.erase(nodesout.find(a));
    }
    queue<int> in,out;
    for (auto it=nodesin.begin();it!=nodesin.end();it++) {
        in.push(*it);
    }
    for (auto it=nodesout.begin();it!=nodesout.end();it++) {
        out.push(*it);
    }
    nodesin.clear();
    nodesout.clear();
    while (!in.empty()) {
        int N = in.front();
        in.pop();
        if (kingdom1[N]) continue;
        kingdom1[N] = kingdom2[N] = id++;
        for (int i=0;i<graph1[N].size();i++) {
            indegree[graph1[N][i]]--;
            if (indegree[graph1[N][i]] == 0)
                in.push(graph1[N][i]);
        }
    }
    while (!out.empty()) {
        int N = out.front();
        out.pop();
        if (kingdom1[N]) continue;
        kingdom1[N] = kingdom2[N] = id++;
        for (int i=0;i<graph2[N].size();i++) {
            outdegree[graph2[N][i]]--;
            if (outdegree[graph2[N][i]] == 0)
                out.push(graph2[N][i]);
        }
    }
    for (int i=1;i<=n;i++) {
        if (kingdom1[i] == 0) {
            modify = 1;
            DFS1(i);
            modify = 0;
            DFS2(i);
            id++;
        }
        else if (kingdom2[i] == 0) {
            modify = 1;
            DFS2(i);
            modify = 0;
            DFS1(i);
            id++;
        }
    }
    printf("%d\n",id-1);
    for (int i=1;i<=n;i++) {
        printf("%d ",kingdom1[i]);
    }
    return 0;
}
