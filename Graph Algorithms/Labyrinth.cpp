#include <bits/stdc++.h>
using namespace std;

/*
Hacer un BFS para calcular las distancias de todos las casillas a la casilla inicial
en cada punto se mira la casilla superior, inferior, la izquierda y la derecha.
Así mismo se va guardando la distancia mínima a cada casilla y se guarda el movimiento
que se hizo para poder al final hacer la inversa e imprimir el camino.
*/

const int oo = 1e9;

int main() {
    int n,m,x0,xf,y0,yf;
    scanf("%d%d",&n,&m);
    queue<pair<int,int>> q;
    vector<string> s = vector<string>(n);
    vector<vector<int>> grid = vector<vector<int>>(n,vector<int>(m,oo));
    vector<vector<bool>> visited = vector<vector<bool>>(n,vector<bool>(m));
    vector<vector<char>> path = vector<vector<char>>(n,vector<char>(m));
    for (int i=0;i<n;i++) {
        cin>>s[i];
        for (int j=0;j<m;j++) {
            if (s[i][j] == 'A') {
                x0 = j;
                y0 = i;
                grid[y0][x0] = 0;
            }
            else if (s[i][j] == 'B') {
                xf = j;
                yf = i;
            }
        }
    }
    q.push({y0,x0});
    while (!q.empty()) {
        pair<int,int> p = q.front();
        q.pop();
        if (visited[p.first][p.second]) continue;
        visited[p.first][p.second] = 1;
        if (p.first+1 < n && !visited[p.first+1][p.second] && s[p.first+1][p.second] != '#') {
            grid[p.first+1][p.second] = grid[p.first][p.second]+1;
            path[p.first+1][p.second] = 'D';
            q.push({p.first+1,p.second});
        }
        if (p.first-1 >= 0 && !visited[p.first-1][p.second] && s[p.first-1][p.second] != '#') {
            grid[p.first-1][p.second] = grid[p.first][p.second]+1;
            path[p.first-1][p.second] = 'U';
            q.push({p.first-1,p.second});
        }
        if (p.second+1 < m && !visited[p.first][p.second+1] && s[p.first][p.second+1] != '#') {
            grid[p.first][p.second+1] = grid[p.first][p.second]+1;
            path[p.first][p.second+1] = 'R';
            q.push({p.first,p.second+1});
        }
        if (p.second-1 >= 0 && !visited[p.first][p.second-1] && s[p.first][p.second-1] != '#') {
            grid[p.first][p.second-1] = grid[p.first][p.second]+1;
            path[p.first][p.second-1] = 'L';
            q.push({p.first,p.second-1});
        }
    }
    if (visited[yf][xf]) {
        string sol = "";
        printf("YES\n%d\n",grid[yf][xf]);
        while (yf != y0 || xf != x0) {
            sol.push_back(path[yf][xf]);
            if (path[yf][xf] == 'L') {
                xf++;
            }
            else if (path[yf][xf] == 'U') {
                yf++;
            }
            else if (path[yf][xf] == 'R') {
                xf--;
            }
            else {
                yf--;
            }
        }
        reverse(sol.begin(),sol.end());
        cout<<sol;
    }
    else {
        printf("NO\n");
    }
    return 0;
}
