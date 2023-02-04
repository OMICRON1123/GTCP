#include <bits/stdc++.h>
using namespace std;

/*
Para este ejercicio se hace un BFS pero con dos colas, primero se analiza a cuáles
casillas pueden llegar los monstruos y se marcan como ocupadas luego se analiza
a cuáles casillas puede llegar el protagonista que todavía no estén ocupadas
y se marcan como ocupadas, un monstruo no puede llegar a una casilla ocupada
así como el protagonista tampoco. Si se llega en algún punto a una casilla de un
borde entonces sí se puede realizar y ya solo es imprimir la ruta.
*/

const int oo = 1e9;

int main() {
    bool ok = 0;
    int n,m,y0,x0,y1,x1;
    scanf("%d%d",&n,&m);
    vector<string> grid(n);
    queue<pair<int,int>> q,qmonster;
    vector<vector<bool>> visited(n,vector<bool>(m,0));
    vector<vector<int>> dist(n,vector<int>(m,oo));
    vector<vector<char>> path(n,vector<char>(m));
    for (int i=0;i<n;i++) {
        cin>>grid[i];
        for (int j=0;j<m;j++) {
            if (grid[i][j] == 'A') {
                q.push({i,j});
                y0 = i;
                x0 = j;
            }
            else if (grid[i][j] == 'M') {
                qmonster.push({i,j});
            }
        }
    }
    dist[y0][x0] = 0;
    if (n == 1 && m == 1 || (y0 == 0 || y0 == n-1 || x0 == 0 || x0 == m-1)) {
        ok = 1;
        y1 = y0;
        x1 = x0;
    }
    while (!q.empty()) {
        if (ok) break;
        queue<pair<int,int>> auxq;
        while (!qmonster.empty()) {
            int f = qmonster.front().first,s = qmonster.front().second;
            qmonster.pop();
            if (visited[f][s]) continue;
            visited[f][s] = 1;
            if (f+1 < n && grid[f+1][s] != '#' && !visited[f+1][s]) {
                auxq.push({f+1,s});
            }
            if (f-1 >= 0 && grid[f-1][s] != '#' && !visited[f-1][s]) {
                auxq.push({f-1,s});
            }
            if (s+1 < m && grid[f][s+1] != '#' && !visited[f][s+1]) {
                auxq.push({f,s+1});
            }
            if (s-1 >= 0 && grid[f][s-1] != '#' && !visited[f][s-1]) {
                auxq.push({f,s-1});
            }
        }
        qmonster = auxq;
        queue<pair<int,int>> auxq1;
        while (!q.empty()) {
            int f = q.front().first,s = q.front().second;
            q.pop();
            if (visited[f][s]) continue;
            visited[f][s] = 1;
            if (f == 0 || f == n-1 || s == 0 || s == m-1) {
                ok = 1;
                y1 = f;
                x1 = s;
            }
            if (f+1 < n && grid[f+1][s] != '#' && !visited[f+1][s]) {
                dist[f+1][s] = dist[f][s]+1;
                path[f+1][s] = 'D';
                auxq1.push({f+1,s});
            }
            if (f-1 >= 0 && grid[f-1][s] != '#' && !visited[f-1][s]) {
                dist[f-1][s] = dist[f][s]+1;
                path[f-1][s] = 'U';
                auxq1.push({f-1,s});
            }
            if (s+1 < m && grid[f][s+1] != '#' && !visited[f][s+1]) {
                dist[f][s+1] = dist[f][s]+1;
                path[f][s+1] = 'R';
                auxq1.push({f,s+1});
            }
            if (s-1 >= 0 && grid[f][s-1] != '#' && !visited[f][s-1]) {
                dist[f][s-1] = dist[f][s]+1;
                path[f][s-1] = 'L';
                auxq1.push({f,s-1});
            }
        }
        q = auxq1;
    }
    if (ok) {
        printf("YES\n");
        string sol = "";
        int auxy = y1, auxx = x1;
        while (y1 != y0 || x1 != x0) {
            sol.push_back(path[y1][x1]);
            if (path[y1][x1] == 'U') y1++;
            else if (path[y1][x1] == 'D') y1--;
            else if (path[y1][x1] == 'L') x1++;
            else x1--;
        }
        printf("%d\n",dist[auxy][auxx]);
        reverse(sol.begin(),sol.end());
        cout<<sol<<"\n";
    }
    else
        printf("NO\n");
    return 0;
}
