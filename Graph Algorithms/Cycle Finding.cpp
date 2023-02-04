#include <bits/stdc++.h>
using namespace std;

const long long oo = 1e4;

bool ok = 0,print = 0;
vector<bool> visdfs;
vector<int> cycle;
vector<long long> sums;
vector<vector<pair<int,int>>> graph;

void DFS(int node,long long sum) {
    printf("%d %lld\n",node,sum);
    if (visdfs[node] && sum-sums[node] < 0) {
        //printf("I am here\n");
        cycle.push_back(node);
        ok = print = 1;
        return;
    }
    if (visdfs[node]) return;
    visdfs[node] = 1;
    sums[node] = sum;
    for (int i=0;i<graph[node].size();i++) {
        if (ok) break;
        DFS(graph[node][i].first,sum+graph[node][i].second);
    }
    if (print) {
        cycle.push_back(node);
        if (node == cycle[0]) {
            print = 0;
        }
    }
}

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    visdfs= vector<bool>(n+1);
    sums = vector<long long>(n+1,-oo);
    graph = vector<vector<pair<int,int>>>(n+1);
    vector<bool> visited(n+1);
    vector<long long> dist(n+1,oo),auxdist(n+1,oo);
    vector<tuple<int,int,int>> edges(m);
    for (int i=0;i<m;i++) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        edges[i] = make_tuple(a,b,c);
        graph[a].push_back({b,c});
    }
    for (int i=1;i<=n;i++) {
        sort(graph[i].begin(),graph[i].end());
        vector<pair<int,int>> aux;
        for (int j=0;j<graph[i].size();j++) {
            if (j == 0 || graph[i][j].first != graph[i][j-1].first) {
                aux.push_back(graph[i][j]);
            }
        }
        graph[i] = aux;
    }/*
    for (int i=1;i<=n;i++) {
        printf("%d:",i);
        for (int j=0;j<graph[i].size();j++) {
            printf(" {%d,%d}",graph[i][j].first,graph[i][j].second);
        }
        printf("\n");
    }*/
    for (int t=1;t<=n;t++) {
        if (ok) break;
        if (visited[t]) continue;
        visited[t] = 1;
        dist[t] = 0;
        for (int i=0;i<n+1;i++) {
            for (int j=0;j<m;j++) {
                int a,b,c;
                tie(a,b,c) = edges[j];
                if (dist[a] != oo) dist[b] = min(dist[b],dist[a]+c);
            }
            if (i == n-1) {
                auxdist = dist;
            }
        }
        //for (int i=1;i<=n;i++) printf("%lld ",dist[i]); printf("\n");
        //for (int i=1;i<=n;i++) printf("%lld ",auxdist[i]); printf("\n");
        for (int i=1;i<=n;i++) {
            if (ok) break;
            if (dist[i] != oo) visited[i] = 1;
            if (auxdist[i] != dist[i]) {
                DFS(i,0);
            }
            fill(visdfs.begin(),visdfs.end(),0);
            fill(sums.begin(),sums.end(),-oo);
        }
        fill(dist.begin(),dist.end(),oo);
    }
    if (ok) {
        printf("YES\n");
        reverse(cycle.begin(),cycle.end());
        printf("%d",cycle[0]);
        for (int i=1;i<cycle.size();i++) printf(" %d",cycle[i]);
        printf("\n");
    }
    else printf("NO\n");
    return 0;
}
