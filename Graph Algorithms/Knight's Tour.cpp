#include <bits/stdc++.h>
using namespace std;

/*
Ver el tablero de ajedrez como un grafo, donde cada casilla es un nodo y cada casilla
tiene una arista a las casillas a las cuales el caballo puede saltar desde dicha
casilla. Luego, el problema se reduce a encontrar un camino Hamiltoniano, no obstante,
se sabe que lo mejor es que siempre el caballo salte a la casilla donde hay menos
casillas disponibles para moverse.
*/

bool ok = 0;
int t = 1;
set<int> nums;
vector<int> ans(64);
vector<vector<int>> graph(64);

bool valid(pair<int,int> pos) {
    return pos.first >= 0 && pos.first < 8 && pos.second >= 0 && pos.second < 8;
}

void init() {
    for (int i=0;i<64;i++) {
        int x = i%8, y = i/8;
        if (valid({x-2,y-1})) graph[i].push_back(i-10);
        if (valid({x-1,y-2})) graph[i].push_back(i-17);
        if (valid({x+1,y-2})) graph[i].push_back(i-15);
        if (valid({x+2,y-1})) graph[i].push_back(i-6);
        if (valid({x+2,y+1})) graph[i].push_back(i+10);
        if (valid({x+1,y+2})) graph[i].push_back(i+17);
        if (valid({x-1,y+2})) graph[i].push_back(i+15);
        if (valid({x-2,y+1})) graph[i].push_back(i+6);
    }
}

void Hammilton(int node) {
    //printf("%d\n",node);
    nums.insert(node);
    ans[node] = t++;
    if (nums.size() == 64) {
        ok = 1;
        return;
    }
    if (graph[node].size() == 0) return;
    sort(graph[node].begin(),graph[node].end(),[&](int x,int y) {
        return graph[x].size() < graph[y].size();
    });
    for (int i=0;i<graph[node].size();i++) {
        if (ok) break;
        if (nums.find(graph[node][i]) == nums.end()) Hammilton(graph[node][i]);
    }
    if (!ok) {
        nums.erase(nums.find(node));
        t--;
    }
}

int main() {
    init();
    int x,y;
    scanf("%d%d",&x,&y);
    x--;
    y--;
    Hammilton(8*y+x);
    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            printf(j == 7 ? "%d\n" : "%d ", ans[i*8+j]);
        }
    }
    return 0;
}
