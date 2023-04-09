#include <bits/stdc++.h>
using namespace std;

int main() {
    bool ok = 1;
    int n,m;
    scanf("%d%d",&n,&m);
    vector<int> deg(n+1),ans;
    vector<set<int>> graph(n+1);
    while (m--) {
        int a,b;
        scanf("%d%d",&a,&b);
        graph[a].insert(b);
        graph[b].insert(a);
        deg[a]++;
        deg[b]++;
    }
    stack<int> s;
    s.push(1);
    while (!s.empty()) {
        int aux = s.top();
        if (graph[aux].size() == 0) {
            ans.push_back(aux);
            s.pop();
        }
        else {
            int node = *graph[aux].begin();
            s.push(node);
            graph[aux].erase(graph[aux].begin());
            graph[node].erase(graph[node].find(aux));
        }
    }
    for (int i=1;i<=n;i++) {
        if (deg[i]%2 != 0 || !graph[i].empty()) {
            ok = 0;
            break;
        }
    }
    if (!ok) printf("IMPOSSIBLE\n");
    else {
        for (int i=0;i<ans.size();i++) {
            printf(i == ans.size()-1 ? "%d\n" : "%d ",ans[i]);
        }
    }
    return 0;
}
