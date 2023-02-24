#include <bits/stdc++.h>
using namespace std;



int main() {
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    vector<int> visited(n+1);
    vector<multiset<long long>> dist(n+1),auxdist(n+1);
    vector<vector<pair<int,int>>> graph(n+1);
    for (int i=0;i<m;i++) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        graph[a].push_back({b,c});
    }
    dist[1].insert(0);
    auxdist[1].insert(0);
    priority_queue<pair<long long,int>> q;
    q.push({0,1});
    while (!q.empty()) {
        /*for (int i=1;i<n+1;i++) {
            printf("{");
            for (auto it=dist[i].begin();it!=dist[i].end();it++) {
                //printf("%lld ",*it);
            }
            printf("}\n");
        }*/
        int node = q.top().second;
        q.pop();
        if (visited[node] >= k || auxdist[node].empty()) continue;
        visited[node]++;
        //printf("Node: %d\n",node);
        for (int i=0;i<graph[node].size();i++) {
            //printf("    node: %d\n",graph[node][i].first);
            q.push({-(*auxdist[node].begin()+graph[node][i].second),graph[node][i].first});
            for (auto it=auxdist[node].begin();it!=auxdist[node].end();it++) {
                //printf("    HI\n");
                if (dist[graph[node][i].first].size() < k || dist[graph[node][i].first].upper_bound(*it+graph[node][i].second) != dist[graph[node][i].first].end()){
                    dist[graph[node][i].first].insert(*it+graph[node][i].second);
                }
                //printf("    HELLO");
                if (dist[graph[node][i].first].size() > k) {
                    dist[graph[node][i].first].erase(prev(dist[graph[node][i].first].end()));
                }
                auxdist[graph[node][i].first].insert(*it+graph[node][i].second);
                if (auxdist[graph[node][i].first].size() > k)
                    auxdist[graph[node][i].first].erase(prev(auxdist[graph[node][i].first].end()));
                //printf("    I am here\n");
            }
        }
        auxdist[node].clear();
    }
    for (auto it=dist[n].begin();it!=dist[n].end();it++) {
        printf(next(it) == dist[n].end() ? "%lld\n":"%lld ",*it);
    }
    return 0;
}
