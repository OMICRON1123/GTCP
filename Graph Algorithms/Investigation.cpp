#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9+7;
const long long oo = 1e17;

vector<vector<pair<int,int>>> graph1,graph2;


vector<map<long long,long long>> memo; //first es longitud, second es cantidad de formas
long long dp(int node,long long val) {
    if (val < 0) return 0;
    if (memo[node].find(val) != memo[node].end()) return memo[node][val];
    memo[node].insert({val,0});
    for (int i=0;i<graph2[node].size();i++) {
        memo[node][val] += memo[graph2[node][i].first][val-graph2[node][i].second];
    }
    return memo[node][val];
}

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    graph1 = graph2 = vector<vector<pair<int,int>>>(n+1);
    vector<bool> visited(n+1);
    vector<long long> dist(n+1,oo);
    while(m--) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        graph1[a].push_back({b,c});
        graph2[b].push_back({a,c});
    }
    priority_queue<pair<long long,int>> q;
    q.push({0,1});
    dist[1] = 0;
    while (!q.empty()) {
        int node = q.top().second;
        q.pop();
        if (visited[node]) continue;
        visited[node] = 1;
        for (int i=0;i<graph1[node].size();i++) {
            int f = graph1[node][i].first,d = graph1[node][i].second;
            dist[f] = min(dist[f],dist[node]+d);
            q.push({-min(dist[f],dist[node]+d),graph1[node][i].first});
        }
    }
    memo[1].insert({0,1});
    memo[n][dist[n]] = dp(n,dist[n]);
    return 0;
}
